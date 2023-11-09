#include <iostream>

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
    int *queue = NULL;
    int *head = NULL;
    int *tail = NULL;
    int count = 1;

public:
    int visited[VERTICES] = {0};
    void make_graph(int no_of_vertices);
    void display(int y);
    void add_edge(int i, int j);
    void bfs(int v);
};

void Graph ::make_graph(int no_of_vertices)
{
    this->no_of_vertices = no_of_vertices;
    adj_list = new struct Node *[no_of_vertices];
    queue = new int[no_of_vertices];
    head = &queue[0];
    tail = &queue[0];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adj_list[i] = NULL;
    }
}

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

    if (adj_list[j] == NULL)
    {
        adj_list[j] = new struct Node;
        adj_list[j]->data = i;
        adj_list[j]->next = NULL;
    }
    else
    {
        struct Node *temp;
        temp = adj_list[j];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new struct Node;
        temp->next->data = i;
        temp->next->next = NULL;
    }
}
// end of function

void Graph ::bfs(int v)
{
    *tail = v;
    tail++;
    visited[v] = count;
    count++;

    while (head != tail)
    {
        struct Node *temp;
        temp = adj_list[*head];
        head++;

        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                *tail = temp->data;
                visited[temp->data] = count;
                tail++;
            }
            temp = temp->next;
        }
        count++;
    }
}

void Graph ::display(int y)
{
    if (visited[y] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << visited[y] - 1;
    }
}
// end of function

// main function starts here
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

    int x, y;
    cin >> x >> y;
    g.bfs(x - 1);

    g.display(y - 1);

    return 0;
}
// end of main
