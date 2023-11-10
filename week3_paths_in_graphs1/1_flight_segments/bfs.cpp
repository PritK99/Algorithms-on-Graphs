#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

void bfs(vector<vector<int>> &adj, int s, int t, vector <int> &visited)
{
  queue <int> q;
  q.push(s);
  visited[s]=1;

  while (!q.empty())
  {
    s = q.front();
    q.pop();
    for (int i = 0; i < adj[s].size(); i++)
    {
      if (visited[adj[s][i]] == 0)
      {
        q.push(adj[s][i]);
        visited[adj[s][i]] = visited[s]+1;
      }
    }
  }
}

int distance(vector<vector<int> > &adj, int s, int t) {
  vector <int> visited (adj.size());
  bfs(adj, s, t, visited);
  if (visited[t] == 0)
  {
    return -1;
  }
  return visited[t]-1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
