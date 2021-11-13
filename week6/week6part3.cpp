#include<iostream>
#include<set>
#define N 50
using namespace std;

bool dfs(int graph[][N], int n, int curr, set<int>&white, set<int>&gray, set<int>&black) {
 
   white.erase(white.find(curr));
   gray.insert(curr);

   for(int v = 0; v < n; v++) {
      if(graph[curr][v] != 0) {    
         if(black.find(v) != black.end())
            continue;   
         if(gray.find(v) != gray.end())
            return true;    
         if(dfs(graph, n, v, white, gray, black))
            return true;   
      }
   }

   
   gray.erase(gray.find(curr));
   black.insert(curr);
   return false;
}

bool detect_cycle(int graph[][N], int n) {
   set<int> white, gray, black;    
   for(int i = 0; i<n; i++)
      white.insert(i);   

   while(white.size() > 0) {
      for(int current = 0; current < n; current++) {
         if(white.find(current) != white.end())
            if(dfs(graph, n, current, white, gray, black))
               return true;
      }
   }
   return false;
}

int main() {

    int n, graph[N][N];
    bool res;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Input adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    }

    res = detect_cycle(graph, n);
    if(res)
        cout << "The graph has cycle." << endl;
    else
        cout << "The graph has no cycle." << endl;
}