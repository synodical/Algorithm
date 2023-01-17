#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100002;
int m, n, arr[MAX];

int dnc(int mid) { // 등분한 길이 반환
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == mid || sum + arr[i + 1] > mid) {
            sum = 0;
            cnt++;
        }
    }
    if (sum != 0) cnt++;
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        low = max(low, arr[i]);
        high += arr[i];
    }
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int cur_m = dnc(mid);
        if (cur_m <= m) high = mid - 1;
        else low = mid + 1;
    }
    cout << low;
    return 0;
}
