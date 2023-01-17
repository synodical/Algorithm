#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int n;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        double a;
        cin >> a;
        cout << fixed;
        cout.precision(2);
        cout << "$" << a*0.8 << '\n';
    }
    return 0;
}


