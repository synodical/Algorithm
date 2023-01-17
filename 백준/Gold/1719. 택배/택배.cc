#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> v[n+1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    int dist[202];
    int from[202];
    
    vector<vector<int>> ans(n, vector<int>(n, 0));
    
    while (m--) {
        int from, to, w;
        cin >> from >> to >> w;
        v[from].push_back({to, w});
        v[to].push_back({from, w});
    }
    
    for (int i = 1; i <= n; i++) {
        fill(dist, dist + n + 1, INF);
        dist[i] = 0;
        pq.push({0,i});
        
        while (!pq.empty()) {
            int cur_cost = pq.top().first;
            int cur_node = pq.top().second;
            pq.pop();
            
            for (auto nxt : v[cur_node]) { // cur node에 삽입된 to와 w pair 벡터
                // 즉 cur_node로부터 갈수있는 노드와 그의 cost 탐색
                if (dist[nxt.first] <= nxt.second + cur_cost) {
                    continue;
                }
                dist[nxt.first] = nxt.second + cur_cost;
                pq.push({dist[nxt.first], nxt.first});
                from[nxt.first] = cur_node; // nxt.first is from cur_node
            }
        }
         
        for (int j = 1; j <= n; j++) {
            if (j == i) { // 대각선, 나에서 나
                cout << "- ";
            } else {
                int cur = j;
                while (1) {
                    if (from[cur] == i) {
                        cout << cur << " ";
                        break;
                    } else {
                        cur = from[cur];
                    }
                }
            }
        }
        cout << '\n';
    }
    
    return 0;
}
