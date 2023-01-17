#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> N;
int n, m, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int high = 0, low = 0, mid;
    for(int i = 0; i < n; i++) {
        cin >> a;
        N.push_back(a);
        high = max(high, N[i]);
    }
    
    long long sum;
    int ans = -1;
    while(high >= low) {
        mid = (high + low) / 2;
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(N[i] > mid) sum += N[i] - mid;
        }
        if(sum < m) high = mid - 1;
        else {
            ans = max(ans, mid);
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}

