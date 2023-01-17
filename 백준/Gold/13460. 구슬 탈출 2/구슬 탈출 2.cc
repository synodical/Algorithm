#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
char board[11][11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[11][11][11][11] = {false, };

struct Bead {
    int rx, ry;
    int bx, by, count = 0;
};

queue<Bead> q;

void go(int &x, int &y, int &i, int &count) {
    // 이동하려는 위치가 벽이면 안됨, 현재 위치가 구멍이면 안됨
    while (board[x + dx[i]][y + dy[i]] != '#' && board[x][y] != 'O') {
        x += dx[i];
        y += dy[i];
        count++;
    }
}

int bfs() {
    int ret = 0;
    while (!q.empty()) {
        Bead cur = q.front();
        q.pop();
        if (cur.count >= 10) {
            return -1;
        }
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
            return cur.count;
        }
        for (int i = 0; i < 4; i++) {
            int next_rx = cur.rx, next_ry = cur.ry, count_r = 0;
            int next_bx = cur.bx, next_by = cur.by, count_b = 0;
            
            go(next_rx, next_ry, i, count_r);
            go(next_bx, next_by, i, count_b);
            
            if (board[next_bx][next_by] == 'O') { // Blue와 동시에 도착하면 안되므로 먼저 체크해야함
                continue;
            }
            if (board[next_rx][next_ry] == 'O') {
                return cur.count + 1;
            }
            if (next_rx == next_bx && next_ry == next_by) {
                if (count_r > count_b) {
                    next_rx -= dx[i];
                    next_ry -= dy[i];
                }
                else {
                    next_bx -= dx[i];
                    next_by -= dy[i];
                }
            }
            if (visit[next_rx][next_ry][next_bx][next_by]) {
                continue;
            }
            visit[next_rx][next_ry][next_bx][next_by] = true;
            Bead next = {next_rx, next_ry, next_bx, next_by, cur.count + 1};
            q.push(next);
        }
    }
    return -1;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Bead start;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
            }
            if (board[i][j] == 'B') {
                start.bx = i;
                start.by = j;
            }
        }
    }
    q.push(start);
    cout << bfs();
    return 0;
}