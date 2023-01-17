//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/05/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 102

int dp[MAX][100000];
int weight[MAX];
int value[MAX];

inline int max1(int a,int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if(j >= weight[i]) dp[i][j] = max1(dp[i-1][j], dp[i-1][j - weight[i] ] + value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}

