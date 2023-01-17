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
    if (n < 2) cout << "Before";
    
    else if (n > 2) cout << "After";
    else {
        if (m < 18)
            cout << "Before";
        else if (m > 18) cout << "After";
    
        else cout << "Special";
    }
    return 0;
}
