#include <bits/stdc++.h>
#define INF 1e8

using namespace std;

template<class node_type,class weight_type> class Dijkstra
{
  /* IF YOU WANT TO UNDERSTAND THE ALGORITHM DO NOT READ THESE LINES */

  typedef pair<node_type,weight_type> weighted_node;

  typedef vector< weighted_node > weighted_node_list;

  typedef vector< weighted_node_list > adjacency_list;

  typedef priority_queue< weighted_node, weighted_node_list, greater< weighted_node > > nodes_as_priority_queue;

  typedef vector< weight_type > weighted_list;
  typedef vector< node_type > path_list;

  /* READ FROM HERE IF YOU WANT TO UNDERSTAND THE ALGORITHM */

  // [(1,2),(0,4)] means node 0 has node 1 as neighbor with weight 2 and node 1 has node 0 as neighbor with weight 4
  adjacency_list weighted_graph;
  node_type start_node = 0;
  // priority_queue with pairs (weights,to_node)
  nodes_as_priority_queue queue;
  weighted_list distances;
  path_list paths;
  bool is_bidirectional = false;

  public:

    Dijkstra(){}
    Dijkstra(node_type quantity_of_nodes, node_type start_node, bool is_bidirectional){
      this->weighted_graph = adjacency_list(quantity_of_nodes);
      this->distances = weighted_list(quantity_of_nodes, INF);
      this->paths = weighted_list(quantity_of_nodes, INF);
      this->start_node = start_node;
      this->is_bidirectional = is_bidirectional;
    }

    void print_min_distances(){
      int i = 0;
      for (weight_type distance : distances) {
        cout << " | " << i;
        i++;
      }
      cout << " |\n";
      for (weight_type distance : distances) {
        cout << " | " << distance;
      }
      cout << " |\n";
    }

    void print_min_path(){
      int i = 0;
      for (node_type node : paths) {
        cout << " | " << i;
        i++;
      }
      cout << " |\n";
      for (node_type node : paths) {
        if(node == INF)
          cout << " | *";
        else
          cout << " | " << node;
      }
      cout << " |\n";
    }

    void connect(node_type from_node, node_type to_node, weight_type distance_between_nodes){
      weighted_graph[from_node].push_back(weighted_node(to_node,distance_between_nodes));
      if (is_bidirectional)
        weighted_graph[to_node].push_back(weighted_node(from_node,distance_between_nodes));
    }

    void do_dijkstra(){
      queue.push({0, start_node});
      distances[start_node] = 0;
      paths[start_node] = start_node;
      while (not queue.empty()) {
        weight_type weight_of_from_node = queue.top().first;
        node_type from_node = queue.top().second;
        queue.pop();
        if(weight_of_from_node != distances[from_node])
          continue;
        for(weighted_node arriving_node : weighted_graph[from_node]){
          node_type to_node = arriving_node.first;
          weight_type weight_of_to_node = arriving_node.second, new_distance = distances[from_node] + weight_of_to_node;
          if(new_distance < distances[to_node]){
            distances[to_node] = new_distance;
            paths[to_node] = from_node;
            queue.push({ new_distance, to_node });
          }
        }
      }
    }
};

int main(){

  /* 5 nodes starting from node '0' bidirectional*/
  Dijkstra<int,int> dij = Dijkstra<int,int>(5,0,true);

  dij.connect(0,1,3);
  dij.connect(0,4,2);
  dij.connect(1,4,4);
  dij.connect(1,2,3);
  dij.connect(1,3,7);
  dij.connect(2,3,1);
  dij.connect(3,4,2);

  dij.do_dijkstra();

  dij.print_min_distances();
  dij.print_min_path();

  return 0;
}
