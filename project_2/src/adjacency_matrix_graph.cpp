#include "graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // Graph properties
    size_t graph_size = reader.get_graph_size();
    size_t edges_count = reader.get_edges_count();
    //size_t starting_vertex_index = reader.get_starting_vertex();

    // Graph creation and setup
    auto graph = std::make_unique<AdjacencyMatrixGraph>();
    graph.get()->matrix = new Matrix<Edge*>(graph_size);
    graph.get()->size = graph_size;

    for(size_t col = 0; col < graph_size; col++)
        for(size_t row = 0; row < graph_size; row++)
            graph.get()->matrix->insert(nullptr, row, col);

    for(size_t index = 1; index < reader.get_lines().size() - 1; index++){
        std::vector<size_t> data = reader.parse(reader.get_lines()[index]);
        Vertex* v1 = new Vertex(data[0], false);
        Vertex* v2 = new Vertex(data[1], false);
        size_t weigth = data[2];
 
        //if(v1->index == starting_vertex_index)
        //    graph.get()->starting_vertex = v1;

        //if(v2->index == starting_vertex_index)
        //    graph.get()->starting_vertex = v2;
        
        //std::cout << data[0] << " " << data[1] << " " << data[2] << std::endl;
        graph.get()->insertVertex(v1);
        graph.get()->insertVertex(v2);
        graph.get()->insertEdge(v1, v2, weigth);
    }

    //for(auto obj : reader.get_lines())
    //    std::cout << obj << std::endl;
    
    //std::cout << "Graph size: " << graph_size << std::endl;
    //std::cout << "Number of edges: " << edges_count << std::endl;
    //std::cout << "Starting vertex: " << starting_vertex << std::endl;
    return graph;
}


void AdjacencyMatrixGraph::insertVertex(Vertex* v)
{
    for(auto obj : v_vector)
        if(obj->index == v->index)
            return;

    v_vector.push_back(v);
}
void AdjacencyMatrixGraph::insertEdge(Vertex* v1, Vertex* v2, int weight)
{
    // putting the v2 first, makes djikstra work for some
    // stupid reason
    Edge* edge = new Edge(v2, v1, weight);
    e_vector.push_back(edge);

    matrix->insert(edge, v1->index, v2->index);
    //matrix->insert(edge, v2->index, v1->index);
}
void AdjacencyMatrixGraph::removeVertex(Vertex* v)
{
    for(size_t index = 0; index < v_vector.size(); index++)
        if(v_vector[index] == v){
            std::cout << "remove it " << 
                v_vector.at(index)->index <<std::endl;

            // This commented code, deletes rows and cols,
            // and may be a little buggy
            // so dont use it

            //for(auto obj : matrix->get_rows())
                //obj.erase(obj.begin() + index);
            //matrix->remove_row(index);
            //size--;


            // This code below changes value to nullprt, but 
            // doesnt remove the cols and rows
            for(size_t j = 0; j < v_vector.size(); j++){
                //std::cout << "deleting: " << matrix->get(j, index) << std::endl;
                matrix->insert(nullptr, j, index);
                matrix->insert(nullptr, index, j);
            }
        }
}
void AdjacencyMatrixGraph::removeEdge(Edge* edge)
{
    matrix->insert(nullptr, edge->v1->index, edge->v2->index);
    matrix->insert(nullptr, edge->v2->index, edge->v1->index);

    for(size_t index = 0; index < e_vector.size(); index++)
        if(e_vector[index] == edge)
            e_vector.erase(e_vector.begin() + index);
    
}
std::vector<Edge*> AdjacencyMatrixGraph::incidentEdges(Vertex* v)
{
    std::vector<Edge*> temp;
    for(auto obj : matrix->get_row(v->index))
        if(obj != nullptr)
            //std::cout << obj->weight << std::endl;
            temp.push_back(obj);

    return temp;
}

std::vector<Edge*> AdjacencyMatrixGraph::edges()
{
    return e_vector;
}

std::vector<Vertex*> AdjacencyMatrixGraph::vertices()
{
    return v_vector;
}

std::vector<Vertex*> AdjacencyMatrixGraph::endVertices(Edge* edge)
{
    std::vector<Vertex*> temp;
    temp.push_back(edge->v1);
    temp.push_back(edge->v2);

    return temp;
}

Vertex* AdjacencyMatrixGraph::opposite(Vertex* v, Edge* egde)
{
    if(egde->v1 == v)
        return egde->v2;

    return egde->v1;
}

bool AdjacencyMatrixGraph::areAdjacent(Vertex* v1, Vertex* v2)
{
    if(v1 == nullptr || v2 == nullptr)
        return false;
        
    if(matrix->get(v1->index, v2->index) != nullptr)
        return true;

    return false;
}
void AdjacencyMatrixGraph::replace(Vertex* v, std::string label)
{
    v->label = label;
}
void AdjacencyMatrixGraph::replace(Edge* edge, int weight)
{
    edge->weight = weight;
    matrix->insert(edge, edge->v1->index, edge->v2->index);
    matrix->insert(edge, edge->v2->index, edge->v1->index);
}
void AdjacencyMatrixGraph::visualise()
{
    // idk add some visualisation
    for(size_t col = 0; col < size; col++){
        for(size_t row = 0; row < size; row++){
            Edge* edge = matrix->get(row, col);
            size_t value = 0;
            if(edge != nullptr)
                value = edge->weight;

            std::cout << value << " ";
            if(row == col)
                if(edge != nullptr)
                    std::cout << "BREAK";
        }
        std::cout << std::endl;
    }
}

void AdjacencyMatrixGraph::visualiseFile(){

}

Vertex* AdjacencyMatrixGraph::get_starting_vertex()
{
    for(auto obj : v_vector)
        if(obj->index == starting_vertex_index)
            return obj;
    
    return nullptr;
    //return starting_vertex;
}
