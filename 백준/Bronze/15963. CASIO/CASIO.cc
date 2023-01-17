#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 13;
ll n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    if (n==m) {
        cout << "1";
    }
    else cout << "0";
    
    return 0;
}
