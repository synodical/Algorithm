#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1002;
int box[MAX], dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,cnt=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (box[j] < box[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cnt = max(cnt,dp[i]);
    }
    cout << cnt;
    return 0;
}