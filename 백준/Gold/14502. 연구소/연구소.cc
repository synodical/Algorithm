
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
const int MAX = 9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int m, n, h, ans = -1;
int map[MAX][MAX];
int tmp[MAX][MAX];

void copyMap(int (*from)[MAX], int (*to)[MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            to[i][j] = from[i][j];
        }
    }
    return;
}

void bfs() {
    int virus[MAX][MAX];
    copyMap(tmp, virus);
    
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (virus[i][j] == 2) q.push({i, j});
            
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (virus[nx][ny] == 0) {
                virus[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    int safe = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (virus[i][j] == 0) safe++;
    
    ans = max(ans, safe);
    return;
}
void wall(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                copyMap(map, tmp);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}

