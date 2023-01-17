//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/17.
//

#include <iostream>
#include <stdio.h>
using namespace std;
using ll = long long;

const int Max = 33;
ll N, L, I, memo[Max][Max];

ll dp(ll x, ll y) { // 길이 i, 1이 j개인 prefix를 가진 2진수 개수
    if (x == N || y == L)
        return 1;
    if (memo[x][y]) {
        return memo[x][y];
    }
    return memo[x][y] = dp(x + 1, y) + dp(x + 1, y + 1);
}

int main() {
 //   ios::sync_with_stdio(false);
 //   cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L >> I;
    
    for (ll i = 1, j = 0; i <= N; i++) {
        if (dp(i, j) >= I) {
            printf("0");
        }
        else {
            printf("1");
            I -= dp(i, j);
            j++;
        }
    }
    return 0;
}

