#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt++;
            if (cnt == k + 1) {
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}