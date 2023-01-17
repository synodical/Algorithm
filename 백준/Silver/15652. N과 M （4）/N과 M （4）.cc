#include<iostream>
using namespace std;
#define MAX 10

int N, M;
int answer[MAX]; 

void solve(int level, int num) { // DFS와 유사
    if (level == M) {
        for (int i = 0; i < M; i++)cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++) {
        answer[level] = i;
        solve(level + 1, i);
    }
}

int main() {
    cin >> N >> M;
    solve(0, 1);
}
