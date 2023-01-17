#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 1e6;
int n,m,q;
int Parent[MAX]; // Parent[node] == parent of node
int cost[MAX];
int elem[MAX];
ll ans = 0;
vector<pair<int, int>> c;
vector<int> unc;
bool connect[MAX] = {false, };
int getParent(int n1) {
    if (Parent[n1] == n1) return n1;
    else return Parent[n1] = getParent(Parent[n1]);
}
void unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 != n2) {
        Parent[n2] = n1;
     //   elem[n1] += cost[n2] * cost[n1];
        cost[n1] += cost[n2];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        Parent[i] = i;
        cost[i] = 1;
        elem[i] = 1;
    }
    for (int i = 0; i < m; i++) { // 연결할 간선
        int a,b;
        cin >> a >> b;
        c.push_back({a,b});
        connect[i] = true;
    }
    for (int i = 0; i < q; i++) { // 연결 끊을 간선
        int a;
        cin >> a;
        unc.push_back(a-1);
        connect[a-1] = false;
    }
    for (int i = 0; i < m; i++) { // 끊을 간선이 아니라면 union
        if (!connect[i]) continue;
        unionParent(c[i].first, c[i].second);
    }
    for (int i = q-1; i >= 0; i--) {
        int seq_to_connect = unc[i]; // 4 2 3
        auto node_to_connect = c[seq_to_connect];
        int u = getParent(node_to_connect.first);
        int v = getParent(node_to_connect.second);
        if (u != v) {
            ans += cost[u] * cost[v];
        }
        unionParent(u, v);
    }
    cout << ans;
    return 0;
}