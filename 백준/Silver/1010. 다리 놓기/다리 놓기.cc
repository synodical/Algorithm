// https://luv-n-interest.tistory.com/956
#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 105;
int n,m;
// combination
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll ans =1;
        int r = 1;
        for (int i = m; i > m-n; i--) {
            ans *= i;
            ans /= r++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}


