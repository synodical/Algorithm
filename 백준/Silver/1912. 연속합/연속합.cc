#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;

int n, sum, arr[100001], dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    dp[0] = -1000; sum=-1000;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        sum = max(sum, dp[i]);
    }
    cout << sum << '\n';
 
    return 0;
}

