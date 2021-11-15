#include <iostream>
#include <climits>

#define N 10
using namespace std;

void printPath(int path[], int curr) {
    if (path[curr] == -1){
        cout << "1 ";
        return;
    }

    printPath(path, path[curr]);

    cout << curr+1 << " ";
}

void dijsktra(int graph[][N], int source, int n) {
    int d[n]; 
    int path[n], k = 0; 
    bool spt[n]; 

    path[0] = -1;
    for (int i = 0; i < n; i++) {
        spt[i] = false; 
        d[i] = INT_MAX;
    }
    
    d[source] = 0;

    for (int i = 0; i < n-1; i++) {
        int min = INT_MAX, u;
        for (int i = 0; i < n; i++) {
            if (!spt[i] && d[i] <= min) {
                min = d[i];
                u = i;
            }
        }

        spt[u] = true;

        for (int v = 0; v < n; v++) {
            if (!spt[v] && graph[u][v] != 0 && d[u] != INT_MAX && (d[u] + graph[u][v] < d[v])) {
                d[v] = d[u] + graph[u][v];
                path[v] = u;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printPath(path, i);
        cout << ": " << d[i] << endl;
    }

}

int main()
{
    int n, graph[N][N], source;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }

    cout << "Enter source node: ";
    cin >> source;

    dijsktra(graph, source-1, n);

    return 0;
}