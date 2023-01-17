#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max 1002

int n, m, v, x, a, b;
// adjacent matrix
bool visited[max];
bool connected[max][max];

void dfs(int x) {
    visited[x] = true;
    cout << x << ' ';
    for(int i = 1; i <= n; i++) {
        if(connected[x][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (q.size()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(connected[cur][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> v;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        connected[a][b] = true;
        connected[b][a] = true;
    }
    dfs(v);
    cout << '\n';
    
    fill(visited, visited+max, false);
    bfs(v);
    return 0;
}
