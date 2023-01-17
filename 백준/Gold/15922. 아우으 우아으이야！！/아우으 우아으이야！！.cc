#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1001;
ll max(ll a, ll b) {
    return a > b ? a : b;
}
ll ans=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, left, right;
    cin >> n;
    cin >> left >> right;
    ans += right - left;
    n--;
    while (n--) {
        ll x,y;
        cin >> x >> y;
        if (right >= x) {
            if (right >= y) {
                continue;
            }
            ans += y - right;
            right = max(right, y);
        }
        else {
            ans += y - x;
            left = x;
            right = y;
        }
    }
    cout << ans;
    return 0;
}

