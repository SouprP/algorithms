#include "graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // Graph properties
    size_t graph_size = reader.get_graph_size();
    size_t edges_count = reader.get_edges_count();
    size_t starting_vertex = reader.get_starting_vertex();

    // Graph creation and setup
    auto graph = std::make_unique<AdjacencyMatrixGraph>();
    graph.get()->matrix = new Matrix<Edge*>(graph_size);
    graph.get()->size = graph_size;

    for(size_t col = 0; col < graph_size; col++)
        for(size_t row = 0; row < graph_size; row++)
            graph.get()->matrix->insert(nullptr, row, col);

    for(size_t index = 1; index < reader.get_lines().size() - 1; index++){
        std::vector<size_t> data = reader.parse(reader.get_lines()[index]);
        Vertex v1 = Vertex(data[0], false);
        Vertex v2 = Vertex(data[1], false);
        size_t weigth = data[2];
        
        std::cout << data[0] << " " << data[1] << " " << data[2] << std::endl;
        graph.get()->insertVertex(v1);
        graph.get()->insertVertex(v2);
        graph.get()->insertEdge(v1, v2, weigth);
    }

    //for(auto obj : reader.get_lines())
    //    std::cout << obj << std::endl;
    
    std::cout << "Graph size: " << graph_size << std::endl;
    std::cout << "Number of edges: " << edges_count << std::endl;
    std::cout << "Starting vertex: " << starting_vertex << std::endl;
    return graph;
}

void AdjacencyMatrixGraph::insertVertex(Vertex v)
{
    vertecies.push_back(v);
}

void AdjacencyMatrixGraph::insertEdge(Vertex v1, Vertex v2, size_t weight)
{
    Edge* edge = new Edge(v1, v2, weight);
    matrix->insert(edge, v1.index, v2.index);
    matrix->insert(edge, v2.index, v1.index);
}

void AdjacencyMatrixGraph::removeVertex(Vertex v)
{
    for(size_t i; i < vertecies.size(); i++)
        if(vertecies[i].index == v.index){
            vertecies.erase(vertecies.begin() + i);
            //matrix.
            return;
        }
            

}

void AdjacencyMatrixGraph::removeEdge(Edge edge)
{
    matrix->insert(nullptr, edge.v1.index, edge.v2.index);
    matrix->insert(nullptr, edge.v2.index, edge.v1.index);
}

std::vector<Edge> AdjacencyMatrixGraph::incidentEdges(Vertex v)
{
return std::vector<Edge>();
}

bool AdjacencyMatrixGraph::areAdjacent(Vertex v1, Vertex v2)
{
return false;
}

void AdjacencyMatrixGraph::visualise()
{
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
