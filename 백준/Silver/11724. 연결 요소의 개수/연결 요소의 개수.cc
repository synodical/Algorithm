#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;
int n, m;
bool adj[MAX][MAX];
bool visited[MAX];
void sol(int a) {
    visited[a] = true;
    for (int i = 1; i <= n; i++) {
        if (adj[a][i] && !visited[i]) {
            sol(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v, cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }
    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt++;
            sol(i);
        }
    }
    cout << cnt;
    return 0;
}
