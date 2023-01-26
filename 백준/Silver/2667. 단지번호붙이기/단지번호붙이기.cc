#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
char arr[25][25];
bool visit[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int bfs(int a, int b) {
    int cnt = 0;
    q.push({a, b});
    visit[a][b] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] || arr[nx][ny] == '0') {
                continue;
            }
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1' && !visit[i][j]) {
                v.push_back(bfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto a : v) {
        cout << a << "\n";
    }
    return 0;
}