#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        cout << n+m <<'\n';
    }
    return 0;
}