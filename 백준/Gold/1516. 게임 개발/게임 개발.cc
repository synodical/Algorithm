#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 511;
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
        // cout << cur << " ";
        for (auto nxt : v[cur]) {
            inDegree[nxt]--;
            result[nxt] = max(result[nxt], result[cur] + d[nxt]);
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << result[i] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        
        while (1) {
            int a;
            cin >> a;
            if (a == -1) {
                break;
            }
            v[a].push_back(i);
            inDegree[i]++;
        }
    }
    topologySort();
    return 0;
}
