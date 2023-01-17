#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define MAX 1005
#define INF 987654321
using namespace std;

int arr[MAX][MAX];
int cost[MAX][MAX];
int check[MAX][MAX]; // (1,1)에서 (2,3) 지점까지 갔을때의 최솟값을 check[2][3]에 저장해줌. 가장 처음 m,n에 도착했을때가 무조건 최솟값이다. 따라서, 처음 m,n에 도착했다면 바로 탐색을 종료해줘야한다.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // dist, i, j

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n; // 첫 번째 줄에 도시를 표현하는 격자의 행과 열의 크기를 각각 나타내는 두 개의 양의 정수 m, n (1 ≤ m, n ≤ 1,000, 1 < m×n)이 주어진다.
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            cost[i][j] = INF;
        }
    } // 다음 m개의 각 줄에 격자의 각 열의 정보를 나타내는 n개의 숫자가 주어진다.
    if (arr[1][1] == -1) {
        cout << "-1";
        return 0;
    }
    cost[1][1] = arr[1][1];
    pq.push({cost[1][1], 1, 1});
    while (!pq.empty()) {
        auto cur = pq.top();
        int x = get<1>(cur); // 2번째 원소, i
        int y = get<2>(cur); // 3번째 원소, j
        int now = get<0>(cur);
        pq.pop();

        if(check[x][y]) continue;
        check[x][y] = 1;
        
        if(x == m && y == n) break;
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if(tmpx > m || tmpy > n) continue;
            if(tmpx <= 0 || tmpy <= 0) continue;
            if(arr[tmpx][tmpy] == -1) continue;
            if(check[tmpx][tmpy]) continue;
            if(arr[tmpx][tmpy] + cost[x][y] < cost[tmpx][tmpy]) {
                cost[tmpx][tmpy] = arr[tmpx][tmpy] + cost[x][y];
                pq.push({cost[tmpx][tmpy], tmpx, tmpy});
            }
        }
    }
    if(cost[m][n] == INF) cout << "-1";
    else cout << cost[m][n];
    
    /*
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
     */
    return 0;
}
