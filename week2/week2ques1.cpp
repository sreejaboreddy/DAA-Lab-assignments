#include <bits/stdc++.h>
using namespace std;
int fun(int a[], int n, int ele, int l)
{   int s=0;
    int index = -1;
    while (n >= s)
    {
        int mid = s + (n - s) / 2;
        if (a[mid] == ele)
        {
            index = mid;
            if (l == 0)
            {
                n = mid - 1;
            }
            else if (l == 1)
            {
                s = mid + 1;
            }
        }
        else if (a[mid] > ele)
            n=mid-1;
        else if (a[mid]<ele)
            s=mid+1;
    }
    return index;
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
        cout << "enter the element for its occurrence";
        cin >> ele;
        int last = 0;
        int c = fun(a, n - 1, ele, last);
        if (c == -1)
        {
            cout << "the element is not present";
        }
        else 
        {
            int k = fun(a, n - 1, ele, 1);
            cout<<"count of the number is "<<((k-c)+1);
        }
    }
    return 0;
}