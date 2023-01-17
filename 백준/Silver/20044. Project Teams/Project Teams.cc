#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,a;
    cin >> n;
    n *= 2;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, v[i] + v[n - i - 1]); // v1 + vn ...
    }
    cout << ans;
    return 0;
}