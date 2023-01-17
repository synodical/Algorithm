#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1516;
const int MOD = 1'000'000'007;
int dp[3][MAX];
int n;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0][1] = 0; dp[0][2] = 1;
    dp[1][2] = 1; dp[2][2] = 0;
    for (int i = 3; i <= n; i++) {
        dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % MOD;
        dp[2][i] = (dp[1][i-1] + dp[0][i-1]) % MOD;
    }
    cout << dp[0][n];
    return 0;
}
