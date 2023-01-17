#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100002;
int a,b,c,d,p;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d >> p;
    int m;
    if (p < c) {
        m = b;
    }
    else m = b + d * (p - c);
    cout << min(p * a, m);
    return 0;
}
