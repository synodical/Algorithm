#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = min(b+c, a+d);
    cout << ans << '\n';
}