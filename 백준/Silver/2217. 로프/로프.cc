#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100001;
int n;
vector<int> v;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        v[i] *= i+1;
        ans = max(v[i],ans);
    }
    cout << ans;
    return 0;
}


