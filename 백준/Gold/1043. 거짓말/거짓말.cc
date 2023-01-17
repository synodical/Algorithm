#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 51;
const int INF = 987654321;
int n, m, t, ans = 0;
int Parent[MAX]; // Parent[node] == parent of node
vector<int> party[MAX];
vector<int> truth;

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
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a; cin >> a;
        truth.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int cur, next;
        for (int j = 0; j < p; j++) {
            if (j == 0) {
                cin >> next;
                party[i].push_back(next);
                continue;
            }
            cur = next;
            cin >> next;
            party[i].push_back(next);
            unionParent(cur, next);
        }
        
    }
    if (t == 0) {
        cout << m;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < t; j++) {
            if (getParent(truth[j]) == getParent(party[i][0])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
