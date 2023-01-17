#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const int INF = 10001;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        int n, cnt = 0;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        for (int i = n + 1; i <= 2*n; i++) {
            if (isPrime(i)) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}