#include "graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // Graph properties
    size_t graph_size = reader.get_graph_size();
    size_t edges_count = reader.get_edges_count();
    //size_t starting_vertex_index = reader.get_starting_vertex();

    // Graph creation and setup
    auto graph = std::make_unique<AdjacencyListGraph>();
    graph.get()->starting_vertex_index = reader.get_starting_vertex();

        for(size_t index = 1; index < reader.get_lines().size() - 1; index++){
            std::vector<int> data = reader.parse(reader.get_lines()[index]);
            Vertex* v1 = new Vertex(data[0], false);
            Vertex* v2 = new Vertex(data[1], false);
            int weigth = data[2];

            //if(v1->index == starting_vertex_index)
                //graph.get()->starting_vertex = v1;

            //if(v2->index == starting_vertex_index)
                //graph.get()->starting_vertex = v2;
            
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

void AdjacencyListGraph::insertEdge(Vertex* v1, Vertex* v2, int weight)
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
        v1_list.push_back(v2);

        v_map.emplace(v1, v1_list);
        return;
    }

    if(v_map.find(v1) != v_map.end()){
        v_map[v1].push_back(v2);
    }else{
        std::list<Vertex*> v1_list;
        v1_list.push_back(v2);

        v_map.emplace(v1, v1_list);
    }
    /*
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
    */
    
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
    //v_map.at(v2).remove(v1);

    for(size_t i = 0; i < e_vector.size(); i++)
        if(e_vector[i] == edge)
            e_vector.erase(e_vector.begin() + i);

    delete edge;
}

std::vector<Edge*> AdjacencyListGraph::incidentEdges(Vertex* v)
{
    std::vector<Edge*> temp;

    //for(auto obj : v_vector)
        //if(areAdjacent(v, obj))
            
    for(auto obj : e_vector)
        if(obj->v1 == v)
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

    //if(v_map.find(v2) == v_map.end())
        //return false;

    for(auto obj : v_map[v1])
        if(obj == v2)
            return true;

    return false;
}

void AdjacencyListGraph::replace(Vertex* v, std::string label)
{
    v->label = label;
}

void AdjacencyListGraph::replace(Edge* edge, int weight)
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

void AdjacencyListGraph::visualiseFile(){
    std::stringstream file_name; 
    file_name << "graph_" << v_vector.size() << "V_" << e_vector.size() << "E.txt";

    // output file contents
    std::stringstream output;

    // header (vertex count, edges count)
    output << v_vector.size() << " " << e_vector.size() << "\n";

    // input edges
    for(auto edge : e_vector)
        output << edge->v1->index << " " << edge->v2->index << " " << edge->weight << "\n";

    // ending - starting vertex index
    output << get_starting_vertex()->index;


    // remove the file if it exists
    std::remove(file_name.str().c_str());

    // create a new file
    std::ofstream output_file(file_name.str());
    
    if(output_file){
        output_file << output.str();
        output_file.close();
    }
}

Vertex* AdjacencyListGraph::get_starting_vertex()
{
    for(auto obj : v_vector)
        if(obj->index == starting_vertex_index)
            return obj;
    
    return nullptr;
    //return starting_vertex;
}