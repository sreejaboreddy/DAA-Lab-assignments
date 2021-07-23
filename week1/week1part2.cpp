#include <bits/stdc++.h>
using namespace std;
int fun(int a[], int s, int n, int ele)
{
    if (n >= s)
    {
        int mid = s + (n - s) / 2;
        if (a[mid] == ele)
            return 1;
        if (a[mid]>ele)
            return fun(a, s, mid-1, ele);
        return fun(a, mid+1, n, ele);
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "enter the no of elements";
        cin >> n;
        int a[n], ele;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "enter the element to be found";
        cin >> ele;
        int c = fun(a, 0, n-1, ele);
        if (c == 1)
            cout << "Present"<<endl;
        else if (c == -1)
            cout << "Not Present"<<endl;
    }
    return 0;
}