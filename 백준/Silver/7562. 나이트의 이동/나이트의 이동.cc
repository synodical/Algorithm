#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 302;
int t, l, i, j, di, dj;
int map[MAX][MAX];
int ans[MAX][MAX];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool visit[MAX][MAX];
queue<pair<int, int> > q;

void bfs(int a, int b) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == di && y == dj) {
            cout << ans[x][y] << '\n';
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            
            if(!visit[nx][ny]) {
                visit[nx][ny] = true;
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        memset(visit, false, sizeof(visit));
        while(!q.empty()) q.pop();
        
        cin >> l;
        cin >> i >> j;
        cin >> di >> dj;
        
        q.push({i, j});
        visit[i][j] = true;
        bfs(i, j);
    }
    return 0;
}