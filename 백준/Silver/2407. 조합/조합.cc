//https://codecollector.tistory.com/977 참고
// n-1,r-1 + n-1,r = n,r
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 102;
string dp[MAX][MAX];

string ntos(string a, string b) {
    ll sum = 0;
    string ret;
    while (a.size() || b.size() || sum) {
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string pascal(int n, int r) {
    if (r == 0 || n == r) {
        return "1";
    }
    string &ret = dp[n][r];
    if (ret != "") {
        return ret;
    }
    ret = ntos(pascal(n-1, r-1), pascal(n-1, r));
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    cout << pascal(n, m);
    return 0;
}

