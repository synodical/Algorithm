#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const int INF = 10001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, ans = 0;
        cin >> x >> y;
        int s = sqrt(y - x);
        if (y-x == s*s)
            cout << s * 2 - 1 << '\n';
        else if (y-x - s*s > s)
            cout << s * 2 + 1 << '\n';
        else
            cout << s * 2 << '\n';
    }
    return 0;
}