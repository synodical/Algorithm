#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 25
using namespace std;
int n;
int graph[MAX][MAX];
bool visit[MAX][MAX] = { false, };
int cnt = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
	cnt++;
	visit[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < n && 0 <= ny && ny < n && !visit[nx][ny] && graph[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main() { 
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!visit[i][j] && graph[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
    return 0; 
}


