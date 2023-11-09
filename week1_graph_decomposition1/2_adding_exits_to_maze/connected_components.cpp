#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, int x, vector<bool> &visited)
{
  visited[x] = 1;

  for (int i = 0; i < adj[x].size(); i++)
  {
    if (visited[adj[x][i]] == 0)
    {
      dfs(adj, adj[x][i], visited);
    }
  }
}

int reach(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size());
  int ctr = 0;
  for (int i = 0; i < visited.size(); i++)
  {
    if (visited[i] == 0)
    {
      ctr++;
      dfs(adj, i, visited);
    }
  }

  return ctr;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << reach(adj);
}
