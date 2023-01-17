#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100002;
ll n, ans, total_road;
ll Min = MAX, b[MAX], a[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        total_road += b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Min = min(Min, a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == Min) {
            ans += total_road * a[i];
            break;
        }
        else {
            ans += a[i] * b[i];
            total_road -= b[i];
        }
    }
    cout << ans;
    return 0;
}

