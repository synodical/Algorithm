#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
using ll = long long;
const int MAX = 16;
const int INF = 17000000;
int n;
int W[MAX][MAX];
int dp[MAX][1 << MAX];
// length of shortest path from vi to v1 passing through each vertex in A exactly once
// MAX = num of node, 1 << 16 = size of A
int TSP(int visit, int now) {
    visit |= (1 << now); // now 번 도시 방문 기록
    if (visit == (1 << n) - 1) { // 모든 도시 방문한 상태라면
        if (W[now][0] > 0) { // now에서 0번 도시까지 가는 길이 있다면
            return W[now][0]; // 총비용
        }
        else return INF;
    }
    
    int& ret = dp[now][visit];
    if (ret != -1) return ret;
    ret = INF;
    
    for (int i = 0; i < n; i++) {
        if (W[now][i] > 0 && (visit&(1 << i)) == 0) { // 방문 안했고 가는 길이 있는 경우
            ret = min(ret, TSP(visit, i) + W[now][i]);
        }
    }
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = TSP(0,0);
    cout << ans;
    return 0;
}
