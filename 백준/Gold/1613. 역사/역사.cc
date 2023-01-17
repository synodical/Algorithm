#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
const int INF = 1e8;
int n, k, ans = INF;

int map[402][402];

void fw() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = INF;
        }
    }
    for (int i = 0; i < k; i++) {
        int s,e,c;
        cin >> s >> e;
        map[s][e] = 1;
    }
    fw();
    int S;
    cin >> S;
    while (S--) {
        int s,e;
        cin >> s >> e;
        if (map[s][e] < INF) {
            cout << "-1" << '\n';
        }
        else if (map[e][s] < INF) {
            cout << "1" << '\n';
        }
        else cout << "0" << '\n';
    }
    return 0;
}