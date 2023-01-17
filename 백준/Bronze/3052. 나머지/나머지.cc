#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
int arr[42] = {0, }, ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10; i++) {
        int a;
        cin >> a;
        arr[a % 42]++;
    }
    for (int i = 0; i < 42; i++) {
        if (arr[i] == 0) continue;
        ans++;
    }
    cout << ans;
    return 0;
}