#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 32001;
int n, m, inDegree[MAX];
vector<int> v[MAX];

void topologySort() {
    queue<int> q;
    // 진입 차수가 0인 노드를 큐에 삽입합니다.
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) { // 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문
        // n개를 방문하기 전에 큐가 비어버리면 사이클이 발생한 것
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for (auto nxt : v[cur]) {
            inDegree[nxt]--;
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
        
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }

    topologySort();
    return 0;
}
