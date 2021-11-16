#include <iostream>
#include <climits>
#include <string>
#include <vector>

#define N 10
using namespace std;
const int INF = 1e9;

int main()
{
    int n;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string tmp;
            cin >> tmp;
           
            if (tmp == "INF") continue;
            else graph[i][j] = stoi(tmp);
        }
    }

    vector<vector<int>> dist = graph;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    cout << "\nShortest distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }

    return 0;
}