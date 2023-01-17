#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a;
int dp[10005][505][2]; //x초, y의 지침지수, z 달리고 있는가에서 달린 거리의 최댓값
int N[10001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> N[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if (j != 1) {
                if (j) { // j != 1,0
                    dp[i][j][1] = dp[i - 1][j - 1][1] + N[i]; // 지침지수가 2 이상이고 달리고 있을 때, 달리다가 달리는 경우
                    dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]); // 달리다 쉬거나, 쉬다가 쉬고 있음
                }
                else { // j = 0
                    dp[i][j][0] = max( {dp[i - 1][j + 1][0], dp[i - 1][j + 1][1], dp[i - 1][j][0]} );
                }
            }
            else { // j = 1
                dp[i][j][1] = max(dp[i - 1][j - 1][0] + N[i], dp[i - 1][j - 1][1]); // 쉬다가 달리는 경우
                dp[i][j][0] = max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]); // 24줄 유사
            }
        }
    }
    cout << dp[n][0][0];
    
    return 0;
}

