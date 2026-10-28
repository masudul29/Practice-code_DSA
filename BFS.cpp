#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 10005;
vector<int> graph[MAXN];
queue<int> q;
int colour[MAXN];

void printAdj(vector<int> graph[MAXN], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void init(int v)
{
    for (int i = 0; i < v; i++)
    {
        colour[v] = {0};
    }
}
void bfs(int start, int v)
{
    q.push(start); // vertex push into queue
    colour[start] = 1;
    while (q.size() > 0)
    {
        int u;
        int v; // u vertex num,v adj element of u;
        u = q.front();
        q.pop();
        cout << u << " "; // vertex print

        for (int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];
            if (colour[v] == 0)
            {
                q.push(v);
                colour[v] = 1; // visited
            }
        }
    }
}

int main()
{
    int V, E, p, q;
    cin >> V >> E; // input vertices and edges

    for (int i = 0; i < E; i++)
    {
        cin >> p >> q;         // pair of edges
        graph[p].push_back(q); // adj list
        graph[q].push_back(p);
    }
    printAdj(graph, V); // print adj list
    int start = 0;
    init(V);
    bfs(start, V);
    return 0;
}