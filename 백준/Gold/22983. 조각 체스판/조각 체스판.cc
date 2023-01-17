#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 3001;
int n,m;
char arr[MAX][MAX]; // i,j 안 체스판 개수 = 변 길이
int col[MAX][MAX];
int row[MAX][MAX];
int dp[MAX][MAX];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (arr[i][j] != arr[i-1][j])
                    col[i][j] = col[i-1][j] + 1;
                if (arr[i][j] != arr[i][j-1])
                    row[i][j] = row[i][j-1] + 1;
            }
        }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0 && arr[i-1][j-1] == arr[i][j]) { // 바로 전 대각전과 같음->dp 값계산
                dp[i][j] = min({row[i][j], col[i][j], dp[i-1][j-1]}) + 1;
                // 정사각형 -> r < c이면 r가 한 변 최대 길이
                ans += dp[i][j];
            }
            else {
                dp[i][j] = 1;
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
