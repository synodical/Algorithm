#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 10001;
int n, m, k, v, w, ans = 0;
int Parent[MAX]; // Parent[node] == parent of node
int A[MAX];
bool visited[MAX];
int getParent(int n1) {
    if (Parent[n1] == n1) return n1;
    else return Parent[n1] = getParent(Parent[n1]);
}
void unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (A[n1] < A[n2]) {
        Parent[n2] = n1; // 비용이 낮은 노드가 부모가 됨
    }
    else Parent[n1] = n2;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        visited[i] = false;
        Parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> v >> w;
        unionParent(v, w);
    }
    // 0번째 노드 = 준석
    for (int i = 1; i <= n; i++) {
        int cur = getParent(i);
        if (cur != getParent(0)) {
            ans += A[cur];
            unionParent(0, cur);
        }
        if (ans > k) {
            cout << "Oh no";
            return 0;
        }
    }
    cout << ans;
    return 0;
}
