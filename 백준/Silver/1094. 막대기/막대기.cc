#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 16;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, ans = 0;
    cin >> x;
    for (int i = 0; i <= 6; i++) {
        if (x & (1 << i)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
