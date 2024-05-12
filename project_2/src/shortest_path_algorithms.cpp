#include "graphs/shortest_path_algorithms.hpp"

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    result.clear();
    graph.visualise();
    Vertex* start_vertex = graph.get_starting_vertex();
    Vertex* current_vertex = start_vertex;

    for(auto obj : graph.vertices())
        std::cout << obj->index << ", "<< obj << std::endl;
    std::cout << std::endl;

    //std::cout << "starting v: " << current_vertex << std::endl << std::endl;
    //graph.incidentEdges(start_vertex);
    //return;

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


    // path to root (start_vertex) is 0, put in a map
    // put our root into the queue
    queue.push(std::make_pair(0, start_vertex));

    // path weight to source vertex is always 0
    path_map.at(start_vertex) = 0;

    // loop till nowhere to go
    while(!queue.empty()){
        // go through all incident edges
        //queue.pop();
        for(auto& edge : graph.incidentEdges(current_vertex)){
            //std::cout <<"sus: " << edge->weight << std::endl;
            // get the neighbouring edges and check if we
            // are not going to the same vertex (cyclic loop)
            //return;
            Vertex* next_v = graph.opposite(current_vertex, edge);
            for(auto temp : path_map)
                if(next_v->index == temp.first->index)
                    next_v = temp.first;

            if(next_v == current_vertex)
                continue;
            
            size_t new_distance = path_map.at(current_vertex) + edge->weight;

            std::cout << "current: " << current_vertex->index
                 << " => " << next_v->index << ", " << next_v << std::endl;
            if(new_distance < path_map.at(next_v)){
                path_map.at(next_v) = new_distance;
                std::cout << "pushed" << std::endl;
                queue.push(std::make_pair(edge->weight, next_v));

                vertex_map.at(next_v) = vertex_map[current_vertex];
                vertex_map[next_v].push_back(next_v);
            }
            //std::cout << next_v->index << std::endl;
        }
        queue.pop();
        current_vertex = queue.top().second;
        //queue.pop();
        //std::cout << "Current" << current_vertex->index << std::endl;
    }

    // DEBUG SYSTEM
    //std::cout << "quyeue" << std::endl;
    //while(!queue.empty()){
    //    std::cout << queue.top().first << std::endl;
    //    queue.pop();
    //}

    std::cout << "weight n map" << std::endl;
    for(auto obj : path_map)
        std::cout << "Vertex: " << obj.first->index
            << ",path weight: " << obj.second << std::endl;

    std::cout << "vertex path f map" << std::endl;
    for(auto obj : vertex_map){
        std::cout << obj.first->index << ": "; // << start_vertex->index;
        for(auto v : obj.second)
            std::cout << " -> " << v->index;
            std::cout << std::endl;
    }
    

   // Result object creator
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
    result.clear();
    graph.visualise();
    Vertex* start_vertex = graph.get_starting_vertex();
    Vertex* current_vertex = start_vertex;

    // path weight it takes to go to the vertex
    std::map<Vertex*, int> path_map;
    // vertex map of previous vertices needed to go through 
    std::map<Vertex*, std::vector<Vertex*>> vertex_map;

    // setup for map objects
    // so there is no std::out_of_range
    for(auto obj : graph.vertices()){
        vertex_map.emplace(obj, std::vector<Vertex*>{start_vertex});
        path_map.emplace(obj, INT32_MAX);
    }

    // path weight to source vertex is always 0
    path_map.at(start_vertex) = 0;

    // relaxing edges V-1 times
    for(size_t i = 0; i < graph.vertices().size() - 1; i++){
        for(auto& edge : graph.edges()){
            Vertex* v1 = edge->v1;
            Vertex* v2 = edge->v2;
            int weight = edge->weight;

            int new_distance = path_map[v1] + weight;

            for(auto temp : path_map){
                if(v1->index == temp.first->index)
                    v1 = temp.first;

                if(v2->index == temp.first->index)
                    v2 = temp.first;
            }
            
            // path_map.at(v1) != INT32_MAX &&
            if(new_distance < path_map.at(v2)){
                path_map.at(v2) = new_distance;
                vertex_map[v2] = vertex_map[v1];
                vertex_map[v2].push_back(v2);
            }
        }
    }

    // DEBUG SYSTEM
    
    std::cout << "weight n map" << std::endl;
    for(auto obj : path_map)
        std::cout << "Vertex: " << obj.first->index
            << ",path weight: " << obj.second << std::endl;

    std::cout << "vertex path f map" << std::endl;
    for(auto obj : vertex_map){
        std::cout << obj.first->index << ": "; // << start_vertex->index;
        for(auto v : obj.second)
            std::cout << " -> " << v->index;
            std::cout << std::endl;
    }
    
    

   // Result object creator
   for(auto v_obj : path_map){
        std::vector<int> path;
        for(auto obj : vertex_map.at(v_obj.first))
            path.push_back(obj->index);

        result.emplace(v_obj.first->index, 
            std::make_pair(path_map.at(v_obj.first), path));
   }

    // check for negative weight cycles
    for(auto& edge : graph.edges()){
        Vertex* v1 = edge->v1;
        Vertex* v2 = edge->v2;
        int weight = edge->weight;

        int new_distance = path_map[v1] + weight;
        if(new_distance < path_map.at(v2)){
            std::cout << "negative cycle" << std::endl;
            return false;
        }
            //return false;
    }

    return true;
}
