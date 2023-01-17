#include <iostream>
using namespace std;

int n, dp[1000000];
int main() {
    cin >> n;

    dp[1] = 0; //dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 3; dp[6] = 2; dp[7] = 3;
    /* bottom-up 작은 것에서 원하는 큰 것으로, 반복문 */
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1); // memoize
    }
    cout << dp[n];
}
