#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 105;
int n,m,t;
int gcd (int a,int b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << n*m / gcd(n,m) << '\n';
    }
    return 0;
}


