#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 101;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n;
        while (n--) {
            int a;
            cin >> a;
            ans += a;
        }
        cout << ans << '\n';
    }
    return 0;
}
