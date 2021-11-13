#include <bits/stdc++.h>
using namespace std;
#define max 20
int dfs(int s, int d, int v, int a[][max], int visit[max] )
{
    int res = 0;
    if (s == d)
        res = 1;
    visit[s] = 1;

    for (int i = 0; i < v; i++)
    {
        if (a[s][i] == 1 && !(visit[i]))
            res = dfs(i, d, v, a, visit);
    }
    return res;
}
int main()
{
    int v, s, d, res, a[max][max] , visit[max];
    cout << "enter the no.of vertices " << endl;
    cin >> v;
    cout << "enter the adjacency matrix:" << endl;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) 
            cin >> a[i][j];
    for(int i =0 ;i<v ;i++) visit[i]=0;
    cout << "enter the source and destination";
    cin >> s >> d;
    res = dfs(s-1, d-1, v, a, visit);
    if (res==1)
        cout << "Yes Path exists";
    else
        cout << "No such exists";
    return 0;
}