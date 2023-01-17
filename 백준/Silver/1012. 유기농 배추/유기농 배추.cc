//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/10.
//

#include <iostream>
#include <cstring>
using namespace std;

int map[51][51] = { 0, };
bool visited[51][51] = { false, };
int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};
int M, N, K, cnt;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + nx[i];
        int yy = y + ny[i];
        if (0 <= xx && xx < N && 0 <= yy && yy < M) {
            if (map[xx][yy] == 1 && !visited[xx][yy]) {
                dfs(xx, yy);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        cnt = 0;
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            map[Y][X] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
    }
    return 0;
}

 
