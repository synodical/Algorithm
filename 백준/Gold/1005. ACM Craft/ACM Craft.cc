#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 1001;
int t, n, k, w;
int inDegree[MAX];
vector<int> v[MAX];
int d[MAX];

void topologySort() {
    int result[MAX];
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
        result[i] = d[i];
    }
    for (int i = 1; i <= n; i++) {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur]) {
            inDegree[nxt]--;
            result[nxt] = max(result[nxt], result[cur] + d[nxt]);
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    cout << result[w] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            inDegree[y]++;
        }
        cin >> w;
        topologySort();
        memset(inDegree, 0, sizeof(inDegree));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
    }
    return 0;
}
