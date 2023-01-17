#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,stick,ans=1;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stick = arr[n-1];
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > stick) {
            ans++;
            stick = arr[i];
        }
    }
    cout << ans;
    return 0;
}
