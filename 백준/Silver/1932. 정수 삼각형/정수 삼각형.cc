#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX = 501;
int n, m, map[MAX][MAX] = {0, }, dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    int sum_max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> map[i][j];
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + map[i][j];
            sum_max = max(sum_max, dp[i][j]);
        }
    }
    cout << sum_max;
    
    return 0;
}

