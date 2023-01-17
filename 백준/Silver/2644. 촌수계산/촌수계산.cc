#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
const int MAX = 100;
int n,a,b,m;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false, };

int bfs() {
    queue<pair<int, int>> q;
    q.push({a,0});
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        if (cur == b) {
            return cnt;
        }
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (visited[cur][i] || visited[i][cur]) {
                continue;
            }
            if (arr[cur][i] == 1) {
                visited[cur][i] = visited[i][cur] = 1;
                q.push({i, cnt+1});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    cout << bfs();
    return 0;
}

