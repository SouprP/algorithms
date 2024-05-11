#include "graphs/shortest_path_algorithms.hpp"

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    result.clear();
    //graph.visualise();
    Vertex* start_vertex = graph.get_starting_vertex();
    Vertex* current_vertex = start_vertex;

    // min-heap queue
    std::priority_queue<std::pair<size_t, Vertex*>, std::vector<std::pair<size_t, Vertex*>>
        ,std::greater<std::pair<size_t, Vertex*>>> queue;
    
    // path weight it takes to go to the vertex 
    std::map<Vertex*, size_t> path_map;
    // vertex map of previous vertices needed to go through 
    std::map<Vertex*, std::vector<Vertex*>> vertex_map;

    // setup for map objects
    // so there is no std::out_of_range
    for(auto obj : graph.vertices()){
        vertex_map.emplace(obj, std::vector<Vertex*>{start_vertex});
        path_map.emplace(obj, INT32_MAX);
    }

    // where does our vertex can go

    // path to root (start_vertex) is 0, put in a map
    // put our root into the queue
    queue.push(std::make_pair(0, start_vertex));

    path_map.at(start_vertex) = 0;

    // loop till nowhere to go
    while(!queue.empty()){
        // go through all incident edges
        for(auto edge : graph.incidentEdges(current_vertex)){
            // get the neighbouring edges and check if we
            // are not going to the same vertex (cyclic loop)
            Vertex* next_v = graph.opposite(current_vertex, edge);

            if(next_v == current_vertex)
                continue;
            
            size_t new_distance = path_map.at(current_vertex) + edge->weight;


            if(new_distance < path_map.at(next_v)){
                path_map.at(next_v) = new_distance;
                queue.push(std::make_pair(edge->weight, next_v));

                vertex_map.at(next_v) = vertex_map[current_vertex];
                vertex_map[next_v].push_back(next_v);
            }

        }
        current_vertex = queue.top().second;
        queue.pop();
    }

    
    std::cout << "quyeue" << std::endl;
    while(!queue.empty()){
        std::cout << queue.top().first << std::endl;
        queue.pop();
    }

    std::cout << "weight n map" << std::endl;
    for(auto obj : path_map)
        std::cout << "Vertex: " << obj.first->index
            << ",path weight: " << obj.second << std::endl;

    std::cout << "vertex path f map" << std::endl;
    for(auto obj : vertex_map){
        std::cout << obj.first->index << ": "; // << start_vertex->index;
        for(auto nigg : obj.second)
            std::cout << " -> " << nigg->index;
            std::cout << std::endl;
    }
    
   for(auto v_obj : path_map){
        std::vector<int> path;
        for(auto obj : vertex_map.at(v_obj.first))
            path.push_back(obj->index);

        result.emplace(v_obj.first->index, 
            std::make_pair(path_map.at(v_obj.first), path));
   }
        
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    return true;
}
