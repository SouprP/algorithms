cmake_minimum_required(VERSION 3.10)
project(graph_algorithms)

set (CMAKE_CXX_STANDARD 17)

add_library(graph_algorithms_lib src/adjacency_list_graph.cpp src/adjacency_matrix_graph.cpp src/shortest_path_algorithms.cpp)
target_include_directories(graph_algorithms_lib PUBLIC include/)

add_executable(test_sp
        src/sp_test_graphs.cpp src/shortest_path_algorithms.cpp)
target_link_libraries(test_sp graph_algorithms_lib)
target_compile_definitions(test_sp PUBLIC DATA_DIR_PATH="${CMAKE_CURRENT_SOURCE_DIR}/sp_data/")

add_executable(efficiency_tests
        src/main.cpp)
target_link_libraries(efficiency_tests graph_algorithms_lib)
