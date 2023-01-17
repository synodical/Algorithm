#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1002;
int box[MAX], dp[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k,d,a;
    char c;
    cin >> k>> c >>d>>c >>a;
    if (d==0 || k+a<d) cout << "hasu";
    else cout << "gosu";
    return 0;
}