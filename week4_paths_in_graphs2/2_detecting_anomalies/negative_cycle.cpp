#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
  int v = adj.size();
  vector<bool> visited(v);

  for (int m = 0; m < v; m++)
  {
    vector<int> dist(v, INT_MAX);
    dist[m] = 0;

    for (int k = 0; k < v - 1; k++)
    {
      // Run v-1 interations

      for (int i = 0; i < v; i++)
      {
        for (int j = 0; j < adj[i].size(); j++)
        {
          if (dist[i] + cost[i][j] < dist[adj[i][j]] && dist[i] != INT_MAX)
          {
            dist[adj[i][j]] = dist[i] + cost[i][j];
          }
        }
      }
    }

    for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        if (dist[i] + cost[i][j] < dist[adj[i][j]] && dist[i] != INT_MAX)
        {
          return 1;
        }
      }
    }
  }

  return 0;
}

int main()
{
  int n, m;
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
  std::cout << negative_cycle(adj, cost);
}
