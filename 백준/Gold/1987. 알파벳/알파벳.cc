#include <iostream>
using namespace std;
using ll = long long;

const int MAX = 21;
int r, c, ans = 0;
char board[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool visited[27] = {false, };

void dfs(int x, int y, int cnt) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
            if (!visited[board[nx][ny] - 'A']) {
                visited[board[nx][ny] - 'A'] = true;
                dfs(nx, ny, cnt + 1);
                visited[board[nx][ny] - 'A'] = false; // backtrack
            }
        }
    }
    ans = max(ans, cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}

