#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1516;
const int MOD = 1'000'000'007;
int dp[3][MAX];
int t;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        int minn = 100; int sum = 0;
        for (int i = 0; i < 7; i++) {
            int n;
            cin >> n;
            if (n%2 == 0) {
                sum += n;
                minn = min(minn, n);
            }
        }
        cout << sum << " " << minn << '\n';
    }
    return 0;
}
