#include <bits/stdc++.h>
using namespace std;
int fun(int a[], int s, int n, int ele)
{
    if (n >= s)
    {
        int mid = s + (n - s) / 2;
        if (a[mid] == ele)
            return mid;
        if (a[mid]>ele)
            return fun(a, s, mid-1, ele);
        else
            return fun(a, mid+1, n, ele);
    }
    return -1;
}
int main(){

    int t;
    cin >> t;
    while (t--)
    {
        int n,s;
        cout << "enter the no of elements";
        cin >> n;
        int a[n], ele;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i=0; i< n-1;i++){
            for(int j=i+1;j<n;j++)
            {
                
                    int y= fun(a,0,n,(a[i]+a[j]));
                    if(y!=-1)
                    {    s=1;
                        cout<<i+1<<" "<<j+1<<" "<<y+1;
                    }
                
            }
        }
        if(s!=1)
        cout<<"No Sequence Found";
    }  
return 0;
}