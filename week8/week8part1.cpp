#include <iostream>
#include <climits>

#define N 10
using namespace std;

int prim(int graph[][N], int n) {
    int mst[N], d[N], parent[N], cost = 0;

    for (int i = 0; i < n; i++) { 
        d[i] = INT_MAX;
        mst[i] = false;
    }

    d[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n-1; i++) {
        int u, min = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!mst[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        mst[u] = true;
        
        for (int k = 0; k < n; k++) {
            if (graph[u][k] && !mst[k] && graph[u][k] < d[k]) {
                parent[k] = u;
                d[k] = graph[u][k];
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        cost += graph[i][parent[i]];
    }

    return cost;
}

int main()
{
    int n, graph[N][N], res = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }

    res = prim(graph, n);

    cout << "Minimum spanning weight: " << res << endl;

    return 0;
}
// 0 0 7 5 0 0 0
// 0 0 8 5 0 0 0
// 7 8 0 9 7 0 0
// 5 5 9 0 15 6 0
// 0 0 7 15 0 8 9
// 0 0 0 6 8 0 11
// 0 0 0 0 9 11 0