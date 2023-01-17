#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 301;
int arr[MAX][MAX] = {0, };
int sum[MAX][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int i,j,x,y;
        cin >> i >> j>>x>>y;
        cout << sum[x][y] - sum[i-1][y] -sum[x][j-1] + sum[i-1][j-1] << '\n';
    }
    return 0;
}