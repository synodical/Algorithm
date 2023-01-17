#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 500003;
int n,m;
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
   // else Parent[n1] = n2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        Parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (getParent(a) == getParent(b)) {
            cout << i;
            return 0;
        }
        unionParent(a, b);
    }
    cout << "0";
    return 0;
}

