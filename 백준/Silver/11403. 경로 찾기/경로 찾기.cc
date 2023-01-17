#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 101;
int n, m, r, ans=0;
int adj[MAX][MAX];
int item[MAX];
void fw() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] >= INF) {
                cout << "0 ";
            }
            else cout << "1 ";
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 0) {
                adj[i][j] = INF;
            }
        }
    }
    fw();
    return 0;
}
