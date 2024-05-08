#include "graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // Graph properties
    size_t graph_size = reader.get_graph_size();
    size_t edges_count = reader.get_edges_count();
    size_t starting_vertex = reader.get_starting_vertex();

    // Graph creation and setup
    auto graph = std::make_unique<AdjacencyListGraph>();

        for(size_t index = 1; index < reader.get_lines().size() - 1; index++){
        std::vector<size_t> data = reader.parse(reader.get_lines()[index]);
        Vertex* v1 = new Vertex(data[0], false);
        Vertex* v2 = new Vertex(data[1], false);
        size_t weigth = data[2];
        
        //std::cout << data[0] << " " << data[1] << " " << data[2] << std::endl;
        graph.get()->insertVertex(v1);
        graph.get()->insertVertex(v2);
        graph.get()->insertEdge(v1, v2, weigth);
    }

    return graph;
}

void AdjacencyListGraph::insertVertex(Vertex* v)
{
    for(auto obj : v_vector)
        if(obj->index == v->index)
            return;

    v_vector.push_back(v);
}

void AdjacencyListGraph::insertEdge(Vertex* v1, Vertex* v2, size_t weight)
{
    for(auto obj : v_vector){
        if(obj->index == v1->index)
            v1 = obj;

        if(obj->index == v2->index)
            v2 = obj;
    }

    Edge* edge = new Edge(v1, v2, weight);
    e_vector.push_back(edge);

    if(v_map.size() == 0){
        std::list<Vertex*> v1_list;
        std::list<Vertex*> v2_list;

        v1_list.push_back(v2);
        v2_list.push_back(v1);

        v_map.emplace(v1, v1_list);
        v_map.emplace(v2, v2_list);
        return;
    }

    if(v_map.find(v1) != v_map.end()){
        v_map[v1].push_back(v2);
    }else{
        std::list<Vertex*> v1_list;
        v1_list.push_back(v2);

        v_map.emplace(v1, v1_list);
    }

    if(v_map.find(v2) != v_map.end()){
        v_map[v2].push_back(v1);
    }else{
        std::list<Vertex*> v2_list;
        v2_list.push_back(v1);

        v_map.emplace(v2, v2_list);
    }
    
}

void AdjacencyListGraph::removeVertex(Vertex* v)
{

    v_map.erase(v);

    for(auto& pair : v_map)
        pair.second.remove(v);

    //for(auto pair : v_map)
    //    for(size_t i = 0; i < pair.second.size(); i++)
    //        if(pair.second == v)



    for(size_t i = 0; i < v_vector.size(); i++)
        if(v_vector[i] == v)
            v_vector.erase(v_vector.begin() + i);

    delete v;
}

void AdjacencyListGraph::removeEdge(Edge* edge)
{
    Vertex* v1 = edge->v1;
    Vertex* v2 = edge->v2;

    v_map.at(v1).remove(v2);
    v_map.at(v2).remove(v1);

    for(size_t i = 0; i < e_vector.size(); i++)
        if(e_vector[i] == edge)
            e_vector.erase(e_vector.begin() + i);

    delete edge;
}

std::vector<Edge*> AdjacencyListGraph::incidentEdges(Vertex* v)
{
    std::vector<Edge*> temp;

    for(auto obj : e_vector)
        if(obj->v1 == v || obj->v2 == v)
            temp.push_back(obj);

    return temp;
}

std::vector<Edge*> AdjacencyListGraph::edges()
{
    return e_vector;
}

std::vector<Vertex*> AdjacencyListGraph::vertices()
{
    return v_vector;
}

std::vector<Vertex*> AdjacencyListGraph::endVertices(Edge* edge)
{
    std::vector<Vertex*> temp;
    temp.push_back(edge->v1);
    temp.push_back(edge->v2);

    return temp;
}

Vertex* AdjacencyListGraph::opposite(Vertex* v, Edge* egde)
{
    if(egde->v1 == v)
        return egde->v2;

    return egde->v1;
}

bool AdjacencyListGraph::areAdjacent(Vertex* v1, Vertex* v2)
{
    if(v_map.find(v1) == v_map.end())
        return false;

    if(v_map.find(v2) == v_map.end())
        return false;

    for(auto obj : v_map[v1])
        if(obj == v2)
            return true;

    return false;
}

void AdjacencyListGraph::replace(Vertex* v, std::string label)
{
    v->label = label;
}

void AdjacencyListGraph::replace(Edge* edge, size_t weight)
{
    edge->weight = weight;
}

void AdjacencyListGraph::visualise()
{
    // obj.first - key
    // obj.second - value
    
    for(auto &pair : v_map){
        std::cout << "Vertex: " << pair.first->index << "[ ";
        for(auto value : pair.second)
            std::cout << value->index << " ";
        
        std::cout << "]" << std::endl;
    }
    
}