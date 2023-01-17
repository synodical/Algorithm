#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 10001;
int ans = 0;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m, prime_min = INF;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            prime_min = min(i, prime_min);
            ans += i;
        }
    }
    if (prime_min == INF) {
        cout << "-1";
        return 0;
    }
    cout << ans << '\n' << prime_min;
    return 0;
}
