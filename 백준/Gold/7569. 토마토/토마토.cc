#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;
const int MAX = 101;
const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};
int m,n,h;
int map[MAX][MAX][MAX];

queue<tuple<int, int, int>> q;
void bfs() {
    while (!q.empty()) {
        
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        
        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;

            if (map[nx][ny][nz]) continue;
            map[nx][ny][nz] = map[x][y][z] + 1;
            q.push(make_tuple(nx, ny, nz));
            
        }
        
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
             //   day[i][j][k] = -1;
                if (map[i][j][k] == 1) {
                 //   day[i][j][k] = 0;
                    q.push(make_tuple(i,j,k));
                }
            }
            
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
                ans = max(ans, map[i][j][k]);
            }
        }
    }
    cout << ans-1;
    return 0;
}
