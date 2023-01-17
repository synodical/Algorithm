#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int n, m, K;
int A[101][101], B[101][101];
int ans[101][101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    cin >> m >> K;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < m; k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}


