// 사이클은 d[i][i]를 구하는 것과 같다.
// 답은 d[i][i] 중 최솟값
// 전부 연결되었다고 가정했으므로, 사이클이 없다는 것은 거리가 무한이라는 뜻
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e9;
int v, e, ans = INF;
int map[402][402];
void fw() {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        ans = min(map[i][i], ans);
    }
    if (ans >= INF) cout << "-1";
    else cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            map[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++) {
        int s,e,c;
        cin >> s >> e >> c;
        map[s][e] = c;
    }
    fw();
    return 0;
}
