#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
#define inf 987654321 // infinite number
#define MAX 20010
vector<pair<int, int>> vt[MAX]; // 간선 정보
int dist[MAX]; // 거리
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 현재 거리, 정점 번호/ 작은수부터 나오게 하는 방법

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int V, E; // 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000)
    cin >> V >> E;
    int k; // 둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다.
    cin >> k;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w; //  u에서 v로 가는 가중치 w인 간선이 존재
        vt[u].push_back({v, w});
    }
    fill(dist, dist + V + 1, inf); // 큰 수로 초기화
    dist[k] = 0; // 시작점 거리 = 0
    pq.push({0, k}); // 현재 거리 = 0, 정점 시작 번호 k
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.second] < cur.first) continue; // 방문체크 대신, is visited == true
        for(auto nxt : vt[cur.second]) {
            if(dist[nxt.first] <= cur.first + nxt.second) continue;
            else {
                dist[nxt.first] = cur.first + nxt.second;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == inf) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}
