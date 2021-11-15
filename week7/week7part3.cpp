#include <iostream>
#include <climits>

#define N 10
using namespace std;

int shortest_path(int graph[][N], int n, int u, int v, int k) {
    if (k == 0 && u == v) return 0;
   if (k == 1 && graph[u][v]) return graph[u][v];
   if (k <= 0) return INT_MAX;
 
   int res = INT_MAX;
 
   for (int i = 0; i < n; i++)
   {
       if (graph[u][i] && u != i && v != i)
       {
           int rec_res = shortest_path(graph, n, i, v, k-1);
           if (rec_res != INT_MAX)
              res = min(res, graph[u][i] + rec_res);
       }
   }
   return res;
}

int main()
{
    int n, graph[N][N], src, dest, k, res;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source, destination, k: ";
    cin >> src >> dest >> k;

    res = shortest_path(graph, n, src-1, dest-1, k);

    cout << "Weight of shortest path: " << res << endl;

    return 0;
}