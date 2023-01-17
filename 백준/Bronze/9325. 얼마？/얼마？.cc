#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 1002;
int n, k;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t,n,s,op,ans=0;
    cin >> t;
    while (t--) {
        ans=0;
        cin >> s;
        cin >> n;
        ans+=s;
        while (n--) {
            int p,q;
            cin >> p >> q;
            ans+=p*q;
        }
        cout << ans <<'\n';
    }
    return 0;
}