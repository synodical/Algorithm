#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 102;
ll sum = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m,n,tmp,tmp2,i=1;
    vector<ll> v;
    cin >> m >> n;
    while (i*i <= n) {
        if (i*i >= m) {
            sum += i*i;
            v.push_back(sum);
        }
        i++;
    }
    if (v.size()) cout << sum << '\n' << v[0];
    else cout << "-1";
    return 0;
}
