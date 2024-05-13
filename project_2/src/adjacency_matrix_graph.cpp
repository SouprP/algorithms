#include "graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // Graph properties
    size_t graph_size = reader.get_graph_size();
    size_t edges_count = reader.get_edges_count();

    // Graph creation and setup
    auto graph = std::make_unique<AdjacencyMatrixGraph>();

    //graph.get()->matrix = new std::vector<std::vector<Edge*>>(graph_size, std::vector<Edge*>(graph_size, nullptr));
    graph.get()->matrix = new Edge**[graph_size];
    graph.get()->starting_vertex_index = reader.get_starting_vertex();
    graph.get()->size = graph_size;

    for(size_t x = 0; x < graph_size; x++){
        graph.get()->matrix[x] = new Edge*[graph_size];
        for(size_t y = 0; y < graph_size; y++)
            graph.get()->matrix[x][y] = nullptr;
    }

    for(size_t index = 1; index < reader.get_lines().size() - 1; index++){
        std::vector<int> data = reader.parse(reader.get_lines()[index]);
        Vertex* v1 = new Vertex(data[0], false);
        Vertex* v2 = new Vertex(data[1], false);
        int weigth = data[2];

        graph.get()->insertVertex(v1);
        graph.get()->insertVertex(v2);
        graph.get()->insertEdge(v1, v2, weigth);
    }

    return graph;
}


void AdjacencyMatrixGraph::insertVertex(Vertex* v)
{
    for(auto obj : v_vector)
        if(v->index == obj->index)
            return;

    if(starting_vertex_index == v->index)
        starting_vertex = v;
    
    v_vector.push_back(v);
}

void AdjacencyMatrixGraph::insertEdge(Vertex* v1, Vertex* v2, int weight)
{
    for(auto obj : v_vector){
        if(obj->index == v1->index)
            v1 = obj;

        if(obj->index == v2->index)
            v2 = obj;
    }

    Edge* edge = new Edge(v1, v2, weight);

    // check if needed to be reworked
    // include checks if Vertices exist
    matrix[v1->index][v2->index] = edge;
    e_vector.push_back(edge);
}

void AdjacencyMatrixGraph::removeVertex(Vertex* v)
{
    for(size_t y = 0; y < size; y++)
        matrix[y][v->index] = nullptr;
    
    for(size_t x = 0; x < size; x++)
        matrix[v->index][x] = nullptr;
    
}

void AdjacencyMatrixGraph::removeEdge(Edge* edge)
{
    matrix[edge->v1->index][edge->v2->index] = nullptr;
}

std::vector<Edge*> AdjacencyMatrixGraph::incidentEdges(Vertex* v)
{
    std::vector<Edge*> buffer;

    for(size_t x = 0; x < size; x++)
        if(matrix[v->index][x] != nullptr)
            buffer.push_back(matrix[v->index][x]);

    return buffer;
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
    return {edge->v1, edge->v2};
}

Vertex* AdjacencyMatrixGraph::opposite(Vertex* v, Edge* egde)
{
    if(egde->v1 == v)
        return egde->v2;

    return egde->v1;
}

bool AdjacencyMatrixGraph::areAdjacent(Vertex* v1, Vertex* v2)
{
    return matrix[v1->index][v2->index] != nullptr;
}

void AdjacencyMatrixGraph::replace(Vertex* v, std::string label)
{
    v->label = label;
}

void AdjacencyMatrixGraph::replace(Edge* edge, int weight)
{
    edge->weight = weight;
}

void AdjacencyMatrixGraph::visualise()
{
    for(size_t y = 0; y < size; y++){
        std::cout << y << "  [ ";
        for(size_t x = 0; x < size; x++)
            if(matrix[y][x] != nullptr)
                std::cout << matrix[y][x]->v2->index << " ";

        std::cout << "]" << std::endl;
    }
}

void AdjacencyMatrixGraph::visualiseFile(){
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

Vertex* AdjacencyMatrixGraph::get_starting_vertex()
{
    return starting_vertex;
}
