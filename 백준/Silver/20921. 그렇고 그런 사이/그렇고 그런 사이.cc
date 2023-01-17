#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }
    if (k == 0) {
        for (int ans : v) {
            cout << ans << " ";
        }
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            swap(v[j], v[j + 1]);
            k--;
            if (k <= 0) {
                for (int ans : v) {
                    cout << ans << " ";
                }
                return 0;
            }
        }
    }
    return 0;
}
