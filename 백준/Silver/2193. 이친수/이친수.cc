#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 93;
ll dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}
