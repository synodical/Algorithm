#include <iostream>
#include <vector>
using namespace std;

int pre[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k, t, ans = -100000000;
    cin >> n >> k;
    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        pre[i] = pre[i - 1] + t;
    }
    for(int i = 0; i <= n - k; i++) {
        ans = max(ans, pre[i + k] - pre[i]);
    }
    cout << ans;
    return 0;
}
