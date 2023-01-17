#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10

int n, m;
int answer[MAX];

void solve(int num, int level) {
    if(level == m) {
        for(int i = 0; i < m; i++) cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++) {
        answer[level] = i;
        solve(i + 1, level + 1);
    }
}

int main() { // 8*8 의 최댓값: 64
    cin >> n >> m;
    solve(1, 0);

    return 0;
}

