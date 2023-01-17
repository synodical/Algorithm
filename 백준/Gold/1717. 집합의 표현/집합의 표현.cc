// Kruskal Algorithm Using Union & Find
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1e7;
int n,m;
int Parent[MAX]; // Parent[node] == parent of node

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) Parent[i] = i;
    for (int i = 0; i < m; i++) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 1) {
            if (getParent(a) == getParent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else unionParent(a, b);
    }
    return 0;
}