#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 100001;
int n, m, k;
int Parent[MAX];
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
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
        Parent[i] = i;
    }
    int node;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (i == k) {
            node = a;
            continue;
        }
        unionParent(a, b);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (getParent(i) == getParent(node)) {
            ans++;
        }
    }
    cout << ans * (n-ans);
    return 0;
}


