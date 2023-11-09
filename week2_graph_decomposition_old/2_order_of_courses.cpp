#include <iostream>
#include <vector>

using namespace std;

#define VERTICES 999999

class Graph
{
private:
  struct Node
  {
    int data;
    struct Node *next;
  };
  int no_of_vertices;
  struct Node **adj_list;
  vector<int> order;

public:
  bool visited[VERTICES] = {0};
  void make_graph(int no_of_vertices);
  void display();
  void add_edge(int i, int j);
  void dfs(int v);
};

void Graph ::add_edge(int i, int j)
{

  if (adj_list[i] == NULL)
  {
    adj_list[i] = new struct Node;
    adj_list[i]->data = j;
    adj_list[i]->next = NULL;
  }
  else
  {
    struct Node *temp;
    temp = adj_list[i];
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = new struct Node;
    temp->next->data = j;
    temp->next->next = NULL;
  }
}
// end of function

void Graph ::dfs(int v)
{
  visited[v] = 1;

  struct Node *temp;
  temp = adj_list[v];

  while (temp != NULL)
  {
    if (visited[temp->data] == 0)
    {
      dfs(temp->data);
    }
    temp = temp->next;
  }
  // cout << v ;
  order.push_back(v + 1);
}

void Graph ::make_graph(int no_of_vertices)
{
  this->no_of_vertices = no_of_vertices;
  // creating a graph
  adj_list = new struct Node *[no_of_vertices];
  for (int i = 0; i < no_of_vertices; i++)
  {
    adj_list[i] = NULL;
  }
}

void Graph ::display()
{
  for (int i = 0; i < order.size(); i++)
  {
    cout << order[order.size() - 1 - i] << " ";
  }
  cout << endl;
}

int main()
{
  Graph g;
  int no_of_vertices;
  cin >> no_of_vertices;
  int no_of_edges;
  cin >> no_of_edges;

  g.make_graph(no_of_vertices);

  for (int i = 0; i < no_of_edges; i++)
  {
    int x, y;
    cin >> x >> y;
    g.add_edge(x - 1, y - 1);
  }

  for (int v = 0; v < no_of_vertices; v++)
  {
    if (g.visited[v] == 0)
    {
      g.dfs(v);
    }
  }

  g.display();

  return 0;
}
// end of main
