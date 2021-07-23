#include <bits/stdc++.h>
using namespace std;
int fun(int a[], int ele, int n)
{
    int step = sqrt(n);

    int prev = 0;
    while (a[min(step, n) - 1] < ele)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (a[prev] < ele)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if (a[prev] == ele)
        return prev;

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
        int c = fun(a, ele, n);g++ .\week1part2.cpp
        if (c != -1)
            cout << "Present at "<<c<< endl;
        else if (c == -1)
            cout << "Not Present" << endl;
    }
    return 0;
}