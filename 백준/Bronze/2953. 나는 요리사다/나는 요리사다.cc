// boj 2953.cpp
#include <iostream>
using namespace std;
const int MAX = 1001;
int ans = 0;
int arr[5][4];
int sum[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            sum[i] += arr[i][j];
        }
        ans = max(ans, sum[i]);
    }
    for (int i = 0; i < 5; i++) {
        if (sum[i] == ans) {
            cout << i + 1 << " ";
            break;;
        }
    }
    cout << ans;
    return 0;
}