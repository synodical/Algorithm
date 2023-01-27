#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 16;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    int t[MAX]; int p[MAX]; int dp[MAX] = {0, };
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
    }
    for (int i = 0; i < t[0]; ++i) {
        if (i + t[i] <= n) {
            dp[i] = p[i];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (t[j] + j <= i && i + t[i] <= n) {
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}

//1
//2 10
//
//1
//1 10

