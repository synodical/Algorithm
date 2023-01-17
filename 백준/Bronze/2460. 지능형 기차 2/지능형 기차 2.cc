#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, sum = 0, ans = 0;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        sum -= a;
        sum += b;
        ans=max(sum, ans);
    }
    cout << ans;
    return 0;
}