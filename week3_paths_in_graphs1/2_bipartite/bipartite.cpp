#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj, int s, vector <bool> &visited) {
  vector <int> status (adj.size());


  queue <int> q;
  q.push(s);
  visited[s]=1;
  status[s]=1;
  bool flag=1;

  while (!q.empty())
  {
    s = q.front();
    q.pop();

    for (int i = 0; i < adj[s].size(); i++)
    {
      if (visited[adj[s][i]] == 1 && status[adj[s][i]] == status[s])
      {
        return 0;
      }
      if (visited[adj[s][i]] == 0)
      {
        q.push(adj[s][i]);
        visited[adj[s][i]] = 1;
        if (status[s]==2)
        {
          status[adj[s][i]] = 1;
        }
        else
        {
          status[adj[s][i]] = 2;
        }
        
      }
    }
  }

  return 1;
}

int bipartite_wrapper(vector<vector<int> > &adj)
{
  vector <bool> visited (adj.size());
  for (int i = 0; i < adj.size(); i++)
  {
    if (visited[i]==0)
    {
      int x = bipartite(adj, i, visited);
      if (x == 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite_wrapper(adj);
}