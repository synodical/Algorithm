#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1001;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0; i <= k; i++) {
        int a = (n-i) / 2;
        int b = m-(k-i);
        if (ans < min(a,b)) {
            ans = min(a,b);
        }
    }
    cout << ans;
    return 0;
}
