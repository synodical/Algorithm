#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MAX 1001
#define INF 987654321
using namespace std;

int dist[MAX]; // 현재 정점까지의 최소비용을 저장하는 배열
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
// 현재 거리, 정점 번호/ 작은수부터 나오게 하는 방법
int N, M, X;

void dijkstra(int start_node, vector<pair<int, int>> map[]) {
    fill(dist, dist + N + 1, INF);
    pq.push({0, start_node});
    dist[start_node] = 0;
    
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (auto nxt : map[cur_node]) {
            if (dist[nxt.first] <= nxt.second + cur_cost) {
                continue;
            }
            dist[nxt.first] = nxt.second + cur_cost;
            pq.push({dist[nxt.first], nxt.first});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> X;
    vector<pair<int, int> > v[N+1];
    
    vector<int> ans(N);
    for (int i = 0; i < M; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        v[from].push_back({to, w});
    }
    // X까지 가는 길
    for (int i = 1; i <= N; i++) {
        dijkstra(i, v);
        ans[i-1] += dist[X];
    }
    // X에서 오는 길
    dijkstra(X, v);
    for (int i = 1; i <= N; i++) {
        ans[i-1] += dist[i];
    }
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}
