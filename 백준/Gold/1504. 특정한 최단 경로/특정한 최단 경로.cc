#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
#define INF 987654321
#define MAX 801
vector<pair<int, int> > v[MAX];
int dist[MAX];
bool visited[MAX];
int N, E, v1, v2; // 첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다.
int ans = INF;
void dij(int s) {
    for(int i = 1; i <= MAX; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 현재 거리, 정점 번호/ 작은수부터 나오게 하는 방법
    pq.push({0, s}); // 현재 거리, 시작 정점 s
    while (!pq.empty()) {
        int curd = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        visited[curr] = true;
        for(auto nxt : v[curr]) { // 인접 정점 nxt
            int next = nxt.first; int nextd = nxt.second;
            if(dist[next] > curd + nextd && !visited[next]) {
                dist[next] = curd + nextd;
                pq.push({dist[next], next});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> E;
    
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c; //  a에서 b로 가는 가중치 c인 간선이 존재
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;
    
    dij(1);
    int stov1 = dist[v1];
    int stov2 = dist[v2];
    
    dij(v1);
    int v1tov2 = dist[v2];
    int v1ton = dist[N];
    
    dij(v2);
    int v2tov1 = dist[v1];
    int v2ton = dist[N];
    ans = min(ans, stov1 + v1tov2 + v2ton);
    ans = min(ans, stov2 + v2tov1 + v1ton);
    
    if (v1tov2 == INF || ans == INF) cout << -1;
    else cout << ans << '\n';
    
    return 0;
}
// https://chosh95.tistory.com/419 참고