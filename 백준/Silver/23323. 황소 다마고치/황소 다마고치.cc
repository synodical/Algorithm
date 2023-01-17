#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        while (1) {
            if (n / 2 == 0) {
                //ans++;
                break;
            }
            n /= 2;
            ans++;
        }
        cout << ans + m + 1 << '\n';
    }
    
    return 0;
}

