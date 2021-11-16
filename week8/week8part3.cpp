#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#define N 10

using namespace std;

vector<int> parent(N);
vector<int> sz(N);

void make_set (int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set (int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

bool comp (vector<int>a, vector<int> b) {
    return a[0] > b[0];
}


int main()
{
    int n, graph[N][N], res = INT_MAX, cost = 0;
    vector<vector<int>> edges;

    for (int i = 0; i < N; i++) {
        make_set(i);
    }
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Input adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> graph[i][j];
    }

    //adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({graph[i][j], i,j});
            }
        }
    }

    //sort by weight
    sort(edges.begin(), edges.end(), comp);
    int e = edges.size();

    for (int i = 0; i < e; i++) {
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        int x = find_set(u);
        int y = find_set(v);

        if (x != y) {
            cost += w;
            union_sets(u, v);
        }
    }

    cout << "Maximum spanning weight: " << cost << endl;

    return 0;
}