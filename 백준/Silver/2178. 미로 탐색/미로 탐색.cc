#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 102
using namespace std;
int n, m;
int graph[102][102];
bool visit[MAX][MAX] = { false, };
int cnt[MAX][MAX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void bfs(int x, int y) {
	if(x == n && y == m) return;
	queue<pair<int, int>> q;
	q.push({x, y});
	while(!q.empty()) { 
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (!visit[nx][ny] && graph[nx][ny] == 1) {
				//
				visit[nx][ny] = true;
				q.push({ nx, ny });
				cnt[nx][ny] = cnt[xx][yy] + 1;
			}
		}
	}	
}

int main() { 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	bfs(1, 1);
	cout << cnt[n][m] + 1;
    return 0; 
}


