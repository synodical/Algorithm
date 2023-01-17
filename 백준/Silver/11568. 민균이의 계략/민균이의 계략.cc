// LIS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int MAX = 1001;
int n, m, arr[MAX], dp[MAX], ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans + 1;
    return 0;
}

