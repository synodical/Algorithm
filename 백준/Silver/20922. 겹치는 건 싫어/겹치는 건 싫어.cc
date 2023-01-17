#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 200001;
int n,k;
int arr[MAX];
int cnt[MAX];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int l = 1, r = 1;
    while (l <= r && r <= n) {
        if (cnt[arr[r]] < k) {
            cnt[arr[r++]]++;
            ans = max(ans, r-l);
        }
        else if (cnt[arr[r]] == k) {
            cnt[arr[l++]]--;
        }
    }
    cout << ans;
    return 0;
}
