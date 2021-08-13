#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, c = -1,j;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    c = 1;
                    cout << "YES";
                    break;
                }
            }
        }
        if (c != 1)
            cout << "NO";
    }
    return 0;
}