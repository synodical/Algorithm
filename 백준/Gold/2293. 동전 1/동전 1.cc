#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
const int MAX = 10001;
int coin[MAX];
int dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
    return 0;
}

