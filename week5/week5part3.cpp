#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == a[j])
        {
            cout << a[j]<<"  ";
            i++;
            j++;
        }
        else if (a[i] > a[j])
            j++;
        else
            i++;
    }
    return 0;
}