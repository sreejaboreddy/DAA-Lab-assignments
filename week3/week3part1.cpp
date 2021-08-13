
//This is insertion sort

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, j, c = 0, s = 0;
        cout << "enter the limit of the array";
        cin >> n;
        int a[n];
        cout << "enter the elements";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            int temp = a[i];
            for (j = i - 1; a[j] > temp && j >= 0; j--)
            {
                a[j + 1] = a[j];
                s++;
                c++;
            }
            a[j + 1] = temp;
            c++;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl
             << "the no of comparissions are " << c-1 << endl
             << "the no of shifts are " << s;
    }
    return 0;
}