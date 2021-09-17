#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> q(n);
        for (int i = 0; i < n; i++)
            cin >> q[i];
        vector<int> r(26, 0);
        for (auto x : q)
            ++r[x - 'a'];
        int c = *max_element(r.begin(), r.end());
        auto it = find(r.begin(), r.end(), c);
        int index = it - r.begin();
        if (c == 1)
            cout << "no duplicates present";
        else
            cout << char(index + 'a') << "-" << c;
    }
    return 0;
}