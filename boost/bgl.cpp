#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <iostream>
#include <vector>

int main() {

    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;
    typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

    Graph g(5);
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(3, 4, g);

    std::vector<int> distances(boost::num_vertices(g));
    Vertex start = 0;
    boost::dijkstra_shortest_paths(g, start, boost::distance_map(&distances[0]));

    //for (size_t i = 0; i < distances.size(); ++i) {
    //    std::cout << "Distance from: " << start << "to: " << i << "is: "<<distances[i]<<std::endl;

    //}


}
