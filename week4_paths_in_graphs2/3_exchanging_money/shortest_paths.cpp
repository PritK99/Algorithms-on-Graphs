#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <set>

using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::vector;

void bfs(vector<vector<int>> &adj, vector<int> &reachable, queue<int> q, vector<bool> visited)
{
  set<int> s;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    s.insert(node);

    for (int i = 0; i < adj[node].size(); i++)
    {
      if (visited[adj[node][i]] == 0)
      {
        q.push(adj[node][i]);
        visited[adj[node][i]] = 1;
      }
    }
  }

  for (auto it : s)
  {
    reachable[it] = 1;
  }
}

void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest)
{
  queue<int> q;
  int v = adj.size();
  distance[s] = 0;
  vector<bool> visited(adj.size());

  // Outer loop runs for |V| times
  for (int i = 0; i < v; i++)
  {
    // Inner loops for iterating over all edges
    for (int j = 0; j < adj.size(); j++)
    {
      if (distance[j] == std::numeric_limits<long long>::max())
      {
        continue;
      }

      for (int k = 0; k < adj[j].size(); k++)
      {
        if (distance[j] != std::numeric_limits<long long>::max() && distance[adj[j][k]] > distance[j] + cost[j][k])
        {
          // Edge Relaxation
          if (i == v - 1)
          {
            q.push(adj[j][k]);
            visited[adj[j][k]] = 1;
          }
          else
          {
            distance[adj[j][k]] = distance[j] + cost[j][k];
          }
        }
      }
    }
  }

  bfs(adj, reachable, q, visited);
}

int main()
{
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++)
  {
    if (reachable[i] == 1)
    {
      std::cout << "-\n";
    }
    else if (distance[i] == std::numeric_limits<long long>::max())
    {
      std::cout << "*\n";
    }
    else
    {
      std::cout << distance[i] << "\n";
    }
  }
}
