#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> N;
long long sum, ans, high, low, mid, n, m, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    static_cast<void>(high = 1e18), static_cast<void>(low = 0), mid;
    for(int i = 0; i < n; i++) {
        cin >> a;
        N.push_back(a);
    }

    while (high >= low) {
        mid = (high + low) / 2;
        sum = 0; // 몇 명을 할 수 있는지
        for(int i = 0; i < n; i++) {
            sum += mid / N[i];
            if(sum >= m) break;
        }
        if(sum >= m) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}

