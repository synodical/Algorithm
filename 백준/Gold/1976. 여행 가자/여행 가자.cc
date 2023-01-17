#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 210;
const int INF = 987654321;
int n, m;
int Parent[MAX]; // Parent[node] == parent of node
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
    for (int i = 1; i <= n; i++) {
        Parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                unionParent(i, j);
            }
        }
    }
    int s,e;
    cin >> s;
    for (int i = 0; i < m-1; i++) {
        cin >> e;
        if (getParent(s) != getParent(e)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    return 0;
}
