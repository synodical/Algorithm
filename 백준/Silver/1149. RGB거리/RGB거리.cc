//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

int house[1000][3];
int dp[1000][3];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n; // n houses
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> house[i][j];
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}

