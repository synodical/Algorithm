// dp[3] = max(dp[2] + v[1], dp[1] + v[2], dp[0] + v[3])
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 10002;
int n;
int w[MAX], v[MAX], dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[0] = v[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + v[j]);
        }
    }
    cout << dp[n];
    return 0;
}