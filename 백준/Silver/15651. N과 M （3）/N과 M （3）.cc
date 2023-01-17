//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/05/09.
//
#include<iostream>
using namespace std;
#define MAX 10

int N, M;
int answer[MAX];

void solve(int level, int num) {
    if (level == M) {
        for (int i = 0; i < M; i++) cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        answer[level] = i;
        solve(level + 1, i);
    }
}
int main() {
    cin >> N >> M;
    solve(0, 1);
}
