// Kruskal Algorithm Using Union & Find
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
const int MAX = 101;
int n;
int Parent[MAX]; // Parent[node] == parent of node
class XY {
public:
    double x;
    double y;
};
class GPS {
public:
    int n1;
    int n2;
    double distance;
    GPS(double n1, double n2, double dist) {
        this->n1 = n1;
        this->n2 = n2;
        this->distance = dist;
    }
    bool operator<(GPS const &d) const{
        return this->distance < d.distance;
    }
};

vector<XY> v;
vector<GPS> star;

int getParent(int node) {
    if (Parent[node] == node) return node;
    else return Parent[node] = getParent(Parent[node]);
}
void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 != node2) Parent[node2] = node1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x,y});
        Parent[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = sqrt((v[i].x - v[j].x) * (v[i].x - v[j].x) +
                               (v[i].y - v[j].y) * (v[i].y - v[j].y));
            star.push_back(GPS(i, j, dist));
        }
    }
    sort(star.begin(), star.end());
    // kruscal algorithm
    double ans = 0;
    for (auto e : star) {
        if (getParent(e.n1) != getParent(e.n2)) {
            unionParent(e.n1, e.n2);
            ans += e.distance;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}