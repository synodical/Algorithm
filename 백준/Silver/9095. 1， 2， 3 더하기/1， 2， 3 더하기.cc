//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
//
#include <iostream>
#define MAX 10000000
using namespace std;
int dp[MAX];

int ans(int n) {
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main() {
    int t,n;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << ans(n) << '\n';
    }
    
    return 0;
}
