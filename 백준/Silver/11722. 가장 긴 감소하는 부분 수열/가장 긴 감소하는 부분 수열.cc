#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;

int n, arr[1001], dp[1001], sum = 1, v[1001], idx;
//vector<int> v;

void back(int x) {
    if (x == -1) return;
    back(v[x]);
    cout << arr[x] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        v[i] = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    v[i] = j;
                }
            }
        }
        if (sum < dp[i]) {
            sum = dp[i];
            idx = i;
        }
    }
    cout << sum << '\n';
   // back(idx);
 
    return 0;
}

