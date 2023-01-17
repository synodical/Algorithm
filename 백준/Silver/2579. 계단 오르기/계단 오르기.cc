//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
//
#include <iostream>
#define MAX 1001
#define match 3
#define mismatch 2 // gap or mismatch
using namespace std;
int stair[MAX];
int dp[MAX];
int Max(int a, int b) { return (a > b ? a : b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int s;
    cin >> s;
    for (int i = 1; i <= s; i++) {
        cin >> stair[i];
    }
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = Max(stair[1] + stair[3], stair[2] + stair[3]);
    for (int i = 4; i <= s; i++) {
        dp[i] = Max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    }
    cout << dp[s];
    return 0;
}
