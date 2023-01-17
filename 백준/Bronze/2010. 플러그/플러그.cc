#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1001;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans - n + 1;
    return 0;
}