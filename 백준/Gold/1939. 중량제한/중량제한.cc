#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 10001;
//const int INF = 987654321;
int n, m,ans = 0;
int Parent[MAX]; // Parent[node] == parent of node
//int W[MAX][MAX];
struct Edge {
    int s,e,cost;
    bool operator<(const Edge &e) const {
        return cost > e.cost;
    }
};
vector<Edge> v;
int getParent(int n1) {
    if (Parent[n1] == n1) return n1;
    else return Parent[n1] = getParent(Parent[n1]);
}
void unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 != n2) {
        Parent[n2] = n1;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        Parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(Edge{a,b,c});
    }
    sort(v.begin(), v.end());
    
    int from, to;
    cin >> from >> to;
    for (auto cur : v) {
        unionParent(cur.s, cur.e);
        if (getParent(from) == getParent(to)) {
            cout << cur.cost;
            break;
        }
        //W[cur.e][cur.s] = W[cur.s][cur.e] = max(W[cur.s][cur.e], cur.cost);
    }
    //cout << W[from][to];
    return 0;
}
