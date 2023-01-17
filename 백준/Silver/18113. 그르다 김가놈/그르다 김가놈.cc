#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
int n,k,m,max_length=0, arr[MAX];

bool dnc(int p){
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        //if(arr[i] < p) break;
        cnt += (arr[i] / p);
    }
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 2 * k) {
            if (arr[i] <= k) arr[i] = 0;
            else arr[i] -= k;
        }
        else arr[i] -= 2 * k;
        max_length = max(max_length,arr[i]);
        
    }
    sort(arr, arr + n, greater<int>());
    int low = 1, high = max_length, ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (dnc(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
