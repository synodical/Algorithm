#include <iostream>
using namespace std;
using ll = long long;

const int MAX = 1002;
int n, m, map[MAX][MAX] = {0, }, dp[MAX][MAX];

int _max(int a, int b, int c) {
    int max = 0;
    if (max < a) max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            dp[i][j] = _max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + map[i][j];
        }
    }
    cout << dp[n][m];
    
    return 0;
}

