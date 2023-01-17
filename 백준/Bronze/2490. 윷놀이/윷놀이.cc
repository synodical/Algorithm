#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >>d;
        int sum = a+b+c+d;
        if (sum == 4) cout << "E" <<'\n';
        else if (sum == 3)  cout << "A" <<'\n';
        else if (sum == 2)  cout << "B" <<'\n';
        else if (sum == 1)  cout << "C" <<'\n';
        else cout << "D" <<'\n';
    }
    
    return 0;
}

