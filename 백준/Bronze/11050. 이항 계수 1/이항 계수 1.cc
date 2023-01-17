#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int bino(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return bino(n-1, r-1) + bino(n-1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    cout << bino(n, k);
    return 0;
}