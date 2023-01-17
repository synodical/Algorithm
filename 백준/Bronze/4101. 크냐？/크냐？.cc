#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 102;
int sum = 0;
int arr[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            return 0;
        }
        if (a > b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}