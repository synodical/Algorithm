#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1002;
int n, arr[MAX], dp[MAX], sum = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+arr[i]);
        }
        sum = max(dp[i], sum);
    }
    cout << sum;
    return 0;
}