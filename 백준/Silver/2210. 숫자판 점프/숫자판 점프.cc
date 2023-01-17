#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
const int MAX = 1e6;
int digit[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool check[MAX];
int cnt = 0;

void dfs(int x, int y, int num, int depth) {
    if (depth == 6) {
        if (!check[num]) {
            check[num] = true;
            cnt++;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
           // num = num * 10 + digit[x][y];
            dfs(nx, ny, num * 10 + digit[nx][ny], depth + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> digit[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, digit[i][j], 1);
        }
    }
    cout << cnt;
    
    return 0;
}

