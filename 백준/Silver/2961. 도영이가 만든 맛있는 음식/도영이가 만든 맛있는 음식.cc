#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// 신맛은 곱이고 쓴 맛은 합이다.


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s, b;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s >> b;
        v.push_back({s, b});
    }
    int agi = 10000000;
    for (int i = 1; i < (1 << n); ++i) {
        // 1 ~ 모든 조합 수인 2^(n)-1을 조사해야 함
        // 1<<n == 2^n
        int sutpai = 1, nigai = 0;
        for (int j = 0; j < n; ++j) {
            //
            if (i & (1 << j)) {
                sutpai *= v[j].first;
                nigai += v[j].second;
            }
        }
        agi = min(agi, abs(sutpai - nigai));
    }
    cout <<agi;
    return 0;
}


