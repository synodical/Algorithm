#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 15;
int t, k,n;
int arr[MAX][MAX];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 1; i <= 14; i++) {
        arr[0][i] = i;
    }
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            for (int k = 1; k <= j; k++) {
                arr[i][j] += arr[i-1][k];
            }
        }
    }
    while (t--) {
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }
    return 0;
}


