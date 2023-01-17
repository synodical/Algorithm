#include <iostream>
using namespace std;
using ll = long long;
int n,ans = 0;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (!cin.eof()) {
        cin >> n;
        ans+=n;
    }
    cout << ans-n;
    return 0;
}


