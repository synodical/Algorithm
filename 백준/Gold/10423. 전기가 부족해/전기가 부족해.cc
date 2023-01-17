#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 1000;
int Parent[MAX];
int N,M,K;
class Edge {
public:
    int s,e,cost;
    Edge(int a, int b, int c) {
        this->s = a;
        this->e = b;
        this->cost = c;
    }
    bool operator<(const Edge &ed) const {
        return this->cost < ed.cost;
    }
};
vector<Edge> v;
int getParent(int n) {
    if (Parent[n] == n) return n;
    else return Parent[n] = getParent(Parent[n]);
}
void unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 != n2) Parent[n2] = n1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    int station;
    for (int i = 1; i <= N; i++) Parent[i] = i;
    for (int i = 1; i <= K; i++) {
        cin >> station;
        Parent[station] = -1;
    }
    for (int i = 1; i <= M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(Edge(a,b,c));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto cur : v) {
        if (getParent(cur.s) != getParent(cur.e)) {
            unionParent(cur.s, cur.e);
            ans += cur.cost;
        }
    }
    cout << ans << '\n';
   // for (int i = 1; i <= N; i++) cout << Parent[i] << " ";
    return 0;
}