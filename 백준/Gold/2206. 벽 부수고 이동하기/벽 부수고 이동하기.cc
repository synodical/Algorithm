#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1001;
int n, m;
char arr[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[MAX][MAX][2];
void bfs(int a, int b) {
    queue<tuple<int, int, int, int>> q;
    q.push({a, b, 0, 1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int block = get<2>(cur);
        int cnt = get<3>(cur);
        
        if (x == n-1 && y == m-1) {
            cout << cnt;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (arr[nx][ny] == '1' && block == 0) {
                visited[nx][ny][block+1] = true;
                q.push({nx, ny, block+1, cnt+1});
            }
            else if (!visited[nx][ny][block] && arr[nx][ny] == '0') {
                visited[nx][ny][block] = true;
                q.push({nx, ny, block, cnt+1});
            }
        }
    }
    cout << "-1";
    return;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    bfs(0, 0);
    return 0;
}


