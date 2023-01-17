#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1000;
const int INF = 1e6;
int v, e, ans = 0;
bool adj[MAX][MAX];
bool visited[MAX] = {false, };
void dfs(int node) {
    visited[node] = true;
    
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (adj[node][i]) {
                ans++;
                dfs(i);
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }
    dfs(1);
    cout << ans;
    return 0;
}

