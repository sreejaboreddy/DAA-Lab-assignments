#include <iostream>
#include <queue>

#define N 50
using namespace std;

bool bipartite(int graph[][N], int src)
{
    int color[N];

    for (int i = 0; i < N; ++i)
        color[i] = -1;
 
    color[src] = 1;
 
    queue <int> q;
    q.push(src);
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        if (graph[u][u] == 1)
        return false;
 
        for (int v = 0; v < N; ++v)
        {
            if (graph[u][v] && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
 
            else if (graph[u][v] && color[v] == color[u])
                return false;
        }
    }
 
    return true;
}

int main()
{
    int n, graph[N][N];
    bool res;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Input adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    }
 
    res = bipartite(graph, 0);
    
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}





