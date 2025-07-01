

// time compolexity : O(N^2) / O(E*V)
// Relax every edge (N-1) times.
// 0 based indexing
void belmanFord(vector<pair<int, pair<int, int>>> edges, int source, int destination, int max_node)
{
  vector<int> distance(max_node, INT_MAX);
  distance[source] = 0;

  // Relax all edges V - 1 times
  for (int i = 1; i <= max_node - 1; i++)
  {
    for (auto values : edges)
    {
      int node = values.first;
      int neighbour = values.second.first;
      int weight = values.second.second;

      if (distance[node] != INT_MAX && distance[node] + weight < distance[neighbour])
      {
        distance[neighbour] = distance[node] + weight;
      }
    }
  }

  // Check for negative weight cycles
  for (auto values : edges)
  {
    int node = values.first;
    int neighbour = values.second.first;
    int weight = values.second.second;

    if (distance[node] != INT_MAX && distance[node] + weight < distance[neighbour])
    {
      cout << "There is a Negative cycle in this graph." << endl;
      return;
    }
  }

  // Print distances
  cout << "Shortest distances from node " << source << ":\n";
  for (int i = 0; i < max_node; i++)
  {
    if (distance[i] == INT_MAX)
    {
      cout << i << " --> " << "INF" << endl;
    }
    else
    {
      cout << i << " --> " << distance[i] << endl;
    }
  }

  cout << "Shortest distance to destination " << destination << " is: ";
  if (distance[destination] == INT_MAX)
    cout << "Unreachable" << endl;
  else
    cout << distance[destination] << endl;

  /*
      How we know if there is a negative cycle present ?
      The fact that it is known upto N-1 iterations we will get the minimum distances from source.
      But if at Nth iteration if we get distance less than previous for any node,
      it simply means that there is a negative cycle passing through that node.

  */
}