#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 1001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int m,n;
int map[MAX][MAX];
int day[MAX][MAX] = { };

queue<pair<int, int>> q;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            
            if (map[nx][ny] == 0 && day[nx][ny] == -1) {
                day[nx][ny] = day[x][y] + 1;
                q.push({nx, ny});
            }
            
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            day[i][j] = -1;
            if (map[i][j] == 1) {
                day[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0 && day[i][j] == -1) {
                cout << "-1";
                return 0;
            }
            ans = max(ans, day[i][j]);
        }
    }
    cout << ans;
    return 0;
}
