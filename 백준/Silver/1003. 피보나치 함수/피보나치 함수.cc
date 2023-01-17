//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
// 시간초과->dp
#include <iostream>
#define MAX 42
using namespace std;

int dp0[MAX] = {1, 0};
int dp1[MAX] = {0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i <= 40; i++) {
        dp0[i] = dp0[i-1] +dp0[i-2];
        dp1[i] = dp1[i-1] +dp1[i-2];
    }
    int t,a;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a;
        cout << dp0[a] << ' ' << dp1[a] << '\n';
    }
    
    return 0;
}
