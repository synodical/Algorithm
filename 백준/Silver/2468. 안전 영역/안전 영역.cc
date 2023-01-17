#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;
int N,M,K;
int arr[MAX][MAX];
int rain[MAX][MAX]; // 물에 잠긴 후 시뮬레이션을 위한 배열
bool visited[MAX][MAX] = {false, };
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int it = 0; it < 4; it++) {
            int nx = x + dx[it];
            int ny = y + dy[it];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            if (visited[nx][ny] || rain[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            rain[i][j] = 0;
        }
    }
    for (int k = 0; k <= 100; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] <= k) {
                    rain[i][j] = 1; // 물에 잠기면 1
                }
            }
        } // 이제 rain에 잠긴 곳만 표시되어 있음
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!rain[i][j] && !visited[i][j]) { // 잠긴 곳이 아니라면 탐색
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        ans = max(ans, cnt);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rain[i][j] = 0;
                visited[i][j] = false;
                cnt = 0;
            }
        }
    }
    cout << ans;
    return 0;
}

