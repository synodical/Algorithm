#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> N;
long long sum, ans, high, low, mid, n, m, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        N.push_back(a);
        high = max(high, N[i]);
    }
    low = 1; // 0으로 할 경우 0으로 나뉘는 경우가 생겨서 런타임 에러가 남
    while (high >= low) {
        mid = (high + low) / 2;
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(N[i] >= mid) sum += N[i] / mid; // 뺄셈이 아닌 몫으로 계산하면 테케의 15도 가능
        }
        if(sum >= m) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}

