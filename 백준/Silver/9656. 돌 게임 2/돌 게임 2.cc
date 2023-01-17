#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 2'100'000'000;
int n, sum = 0;
int dp[1001];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    for (int i = 5; i <= n; i++) {
        if (dp[i-1] == 1 && dp[i-3] == 1) {
            dp[i] = 0;
        }
        else dp[i] = 1;
    }
    if (dp[n]) {
        cout << "SK";
        return 0;
    }
    else cout << "CY";
    return 0;
}


