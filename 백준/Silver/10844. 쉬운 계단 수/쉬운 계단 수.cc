#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 2'100'000'000;
const int MOD = 1'000'000'000;
int n, sum = 0;
int dp[101][10];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j+1];
            }
            else if (j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    for (int i = 0; i <= 9; i++) {
        sum += dp[n][i];
        sum %= MOD;
    }
    cout << sum;
    return 0;
}


