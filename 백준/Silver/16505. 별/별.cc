//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//
#include <iostream>
#define MAX 1024 // 2^10
using namespace std;

char star[MAX][MAX];

void solve(int a, int i, int j){
    if(a == 1) {
        star[i][j] = '*';
        return;
    }
    solve(a / 2, i, j);
    solve(a / 2, i + a / 2, j);
    solve(a / 2, i, j + a / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    solve((1<<n), 0, 0);
    for (int i = 0, a = 0; i < (1<<n); i++, a++) {
        for (int j = 0; j < (1<<n) - a; j++) {
            if(star[i][j] == '*') cout << star[i][j];
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
