#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 52;
int map[MAX][MAX];
bool visited[MAX][MAX] ={false,};
int w, h, cnt = 0;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void sima(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
            continue;
        }
        if (map[nx][ny] == 1 && !visited[nx][ny]) {
            sima(nx, ny);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    visited[i][j] = true;
                    sima(i, j);
                }
            }
        }
        cout << cnt << '\n';
        
    }
    return 0;
}