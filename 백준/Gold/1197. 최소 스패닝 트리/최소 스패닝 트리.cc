// Kruskal Algorithm Using Union & Find
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 10001;
int V,E;
int Parent[MAX]; // Parent[node] == parent of node

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int dist) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = dist;
    }
    bool operator<(Edge const &edge) {
        return this->distance < edge.distance;
    }
};

vector<Edge> vt;

bool compare(Edge &e1, Edge &e2) {
    return e1.distance < e2.distance;
}
int getParent(int node) {
    if (Parent[node] == node) return node;
    else return Parent[node] = getParent(Parent[node]);
}
void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 != node2) Parent[node2] = node1;
}
void kruskal() {
    ll ans = 0;
    sort(vt.begin(), vt.end());
    for (int i = 0; i < E; i++) {
        if ( getParent(vt[i].node[0]) != getParent(vt[i].node[1]) ) {
            unionParent(vt[i].node[0], vt[i].node[1]);
            ans += vt[i].distance;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vt.push_back(Edge(a,b,c));
    }
    for (int i = 1; i <= V; i++) Parent[i] = i;
    kruskal();
    return 0;
}
