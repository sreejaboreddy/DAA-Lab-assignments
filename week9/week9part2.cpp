#include <iostream>
#include <functional>
#include <queue>
#define N 50
using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> p;
    cout << "Enter size of input array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        p.push(tmp);
    }
    int sum = 0;
    
    for (int i = 0; i < n-1; i++) {
        int x = p.top(); p.pop();
        int y = p.top(); p.pop();
        p.push(x + y);
        sum += x + y;
    }
    cout << "Answer: " << sum << endl;
    return 0;
}