// https://raw.githubusercontent.com/jeonggyunkim/problemsolving/master/boj/fa4ead893e02.cpp 참고
// https://en.wikipedia.org/wiki/Josephus_problem
#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 5000001;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    //cout << josephus(n, k);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (ans + k) % i;
    }
    cout << ans + 1;
    return 0;
}
