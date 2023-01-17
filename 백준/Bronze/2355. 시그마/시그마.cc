#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll a,b,ans=0;
    cin >> a >> b;
    if(a<b)cout << b * (b + 1) / 2 - (a) * (a - 1) / 2;
    else cout << a * (a + 1) / 2 - (b) * (b - 1) / 2;
    return 0;
}