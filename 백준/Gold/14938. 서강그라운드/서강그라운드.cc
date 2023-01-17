#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 100;
int n, m, r,sum=0,ans=0;
int map[MAX][MAX];
int item[MAX];
void fw() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = i;
        sum += item[cur];
        for (int j = 1; j <= n; j++) {
            if (cur != j && map[cur][j] <= m) {
                sum += item[j];
            }
            
        }
        ans =max(ans, sum);
        sum = 0;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        item[i] = t;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = INF;
            if (i == j) map[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        map[a][b] = map[b][a] = l;
    }
    fw();
    return 0;
}