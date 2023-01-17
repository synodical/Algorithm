#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define MAX 20010
#define inf 987654321
using namespace std;

int dist[MAX]; // 거리
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 현재 거리, 정점 번호/ 작은수부터 나오게 하는 방법

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v[n+1];
    for (int i = 0; i < m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        v[from].push_back({to, w});  //  s에서 e로 가는 가중치 w인 간선이 존재
    }
    int S, E;
    cin >> S >> E;
    
    fill(dist, dist + n + 1, inf);
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.second] < cur.first) continue;
        for(auto nxt : v[cur.second]) {
            if(dist[nxt.first] <= cur.first + nxt.second) continue;
            dist[nxt.first] = cur.first + nxt.second;
            pq.push({dist[nxt.first], nxt.first});
        }
    }
    cout << dist[E];
    return 0;
}
