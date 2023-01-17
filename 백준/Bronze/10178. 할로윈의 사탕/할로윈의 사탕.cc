#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 100;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        cout << "You get "<< a/b << " piece(s) and your dad gets " << a%b<< " piece(s).\n";
    }
    return 0;
}