#include <iostream>
#include <climits>

#define N 10
#define M 3
using namespace std;

void bellman_ford(int graph[][M], int e, int src, int n) {
    int d[N];
    for (int i = 0; i < n; i++) d[i] = INT_MAX;
 
    d[src] = 0;
    
    for (int i = 0; i < n - 1; i++) {
 
        for (int j = 0; j < e; j++) {
            if (d[graph[j][0]] != INT_MAX && ((d[graph[j][0]] + graph[j][2]) < d[graph[j][1]]))
                d[graph[j][1]] = d[graph[j][0]] + graph[j][2];
        }
    }

    for (int i = 0; i < e; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];

        if (d[u] != INT_MAX && d[u] + weight < d[v])
            cout << "Graph contains negative weight cycle" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << " :" << d[i] << endl;
    }
}

int main()
{
    int n, graph[N][N], source, edges[N][M], e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source node: ";
    cin >> source;
    e = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[e][0] = i;
                edges[e][1] = j;
                edges[e][2] = graph[i][j];
                e++;
            }
        }
    }
    bellman_ford(edges, e, source-1, n);

    return 0;
}