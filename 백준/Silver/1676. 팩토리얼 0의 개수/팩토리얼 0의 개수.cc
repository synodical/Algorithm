// https://luv-n-interest.tistory.com/957 참고
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, ans = 0;
int dp[501];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = n; i > 1; i--) {
        int cnt = 0; // number of 5
        int cur = i;
        while (1) {
            if (cur % 5 == 0) {
                cnt++;
                cur /= 5;
            }
            else break;
        }
        ans += cnt;
    }
    cout << ans;
    return 0;
}
