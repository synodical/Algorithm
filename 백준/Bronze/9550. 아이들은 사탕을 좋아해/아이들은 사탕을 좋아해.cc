#include <iostream>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
using ll = long long;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> k;
        while (n--) {
            int candy;
            cin >> candy;
            ans += candy / k;
        }
        cout << ans << '\n';
    }
    return 0;
}
