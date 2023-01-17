#include <iostream>
#include <vector>
using namespace std;

int pre[1000002];
int d[1000202];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k, g, x;
    int ans = 0;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> g >> x;
        pre[x] = g;
    }
    d[0] = pre[0];
    for (int i = 1; i <= 1000000; i++) {
        d[i] = d[i - 1] + pre[i];
    }
    if (k <= 1000000) {
        for (int i = 0; i <= 1000000; i++) {
            if (i + k <= 1000000 && i-k >=1) ans = max(ans, d[i + k] - d[i - k - 1]);
        }
        cout << ans << '\n';
    }
    else cout << d[1000000] << '\n';


    /*
    int i = 0;
    while (i + k <= 1000000 && i - k >= 1) {
        ans = max(ans, pre[i + k] - pre[i - k - 1]);
        i++;
    }
    
    cout << ans;
     */
    return 0;
}