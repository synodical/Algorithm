#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using ll = long long;
const int MAX = 10001;
const ll INF = 9999987654321;
ll n,m,d,ans = -INF;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    vector<vector<ll> > arr(n, vector<ll>(m,0));
    vector<vector<ll> > dp(n, vector<ll>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -INF;
        }
    }
    for (int j = 0; j < m; j++) dp[0][j] = 0;
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int i = x + 1; i <= x + d; i++) {
                for (int j = y - d; j <= y + d; j++) {
                    if (j < 0 || i >= n || j >= m) continue;
                    int cur = arr[x][y];
                    int next = arr[i][j];
                    if (abs(i - x) + abs(j - y) <= d) {
                        dp[i][j] = max(dp[i][j], dp[x][y] + cur*next);
                    }
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        ans = max(ans, dp[n-1][j]);
    }
    cout << ans;
    return 0;
}