#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector <long long> djikstras(vector<vector<int>> &adj, vector<vector<int>> &cost, int s)
{
    vector <long long> distance (adj.size());
    vector <bool> visited (adj.size());

    for (int i = 0; i < adj.size(); i++)
    {
        //we use INT_MIN here since our priority queue is Max Heap by default
        distance[i] = INT_MIN;
    }

    distance[s] = 0;
    pair <long long, long long> p;
    p.first = 0;
    p.second = s;
    priority_queue <pair <long long, long long>> pq;
    pq.push(p);
    visited[p.second]=1;

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();

        for (int i = 0; i < adj[p.second].size(); i++)
        {
            if (visited[adj[p.second][i]] == 0)
            {
                pair <long long, long long> temp;
                temp.first = -cost[p.second][i];
                temp.second = adj[p.second][i];
                pq.push(temp);
                visited[adj[p.second][i]] = 1;
            }
            //edge relaxation
            distance[adj[p.second][i]] = max(distance[adj[p.second][i]], distance[p.second] - cost[p.second][i]);
        }
    }
    
    for (int i = 0; i < distance.size(); i++)
    {
      if (distance[i] == INT_MIN)
      {
        distance[i]=1;
      }
      distance[i]*=-1 ;
    }
    return distance;
}

int main()
{
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    vector<vector<int>> adj(num_vertices, vector<int>());
    vector<vector<int>> cost(num_edges, vector<int>());
    for (int i = 0; i < num_edges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s,t;
    cin >> s >> t;
    vector <long long> shortest_path = djikstras(adj, cost, s-1);

    cout << shortest_path[t-1];
    return 0;
}
