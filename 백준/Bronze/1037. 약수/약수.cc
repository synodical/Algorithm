#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 2'100'000'000;
int n,l=0,s=MAX;
// 진짜 약수가 모두 주어지므로, 약수의 최대 최소가 모두 주어진다.
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        l = max(a, l);
        s = min(a, s);
    }
    cout << l*s;
    return 0;
}


