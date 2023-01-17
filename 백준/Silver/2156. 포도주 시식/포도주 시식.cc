#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 10002;
int n;
int arr[MAX], dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], max(dp[i-2] + arr[i], dp[i-1]));
    }
    cout << dp[n];
    return 0;
}
