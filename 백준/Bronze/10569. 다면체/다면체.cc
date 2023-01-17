#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int v,e;
        cin >> v >> e;
        cout << e - v + 2 << '\n';
    }
    return 0;
}
