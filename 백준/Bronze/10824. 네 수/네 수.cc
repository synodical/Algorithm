#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << stoll(a+b) + stoll(c+d);
    return 0;
}
