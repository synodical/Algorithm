// 결론: 우선순위 큐를 쓰니 코드도 간결하고 정말 이해가 쉽구나!!
// 참고: https://docs16.tistory.com/2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e6;
int n, m;
int W[1000][1000]; // 인접하는 이음선 비용 저장 2차원 배열
int nearest[1000]; // vi와 가장 가까운 집합에 속한 마디의 인덱스
bool visited[1001];
int sum = 0;

vector<pair<int, int> > v[1001];

void prim() {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    visited[1] = true;
    
    for (int i = 0; i < v[1].size(); i++) { // v[1] 인접 노드 pq에 삽입
        int vnext = v[1][i].first;
        int next_cost = v[1][i].second;
        pq.push(make_pair(next_cost, vnext));
        // dist가 적은 순으로 삽입됨 -> visited로 확인하므로 가장 적은 dist만 더함
    }
    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        sum += dist;
        
        for (int i = 0; i < v[cur].size(); i++) { // v[cur] 인접 노드 pq에 삽입
            int vnext = v[cur][i].first;
            int next_cost = v[cur][i].second;
            pq.push(make_pair(next_cost, vnext));
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back(make_pair(b, cost));
        v[b].push_back(make_pair(a, cost));
    }
    
    prim();
    cout << sum;
    return 0;
}

