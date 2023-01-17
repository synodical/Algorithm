#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
const int MAX = 101;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, c, tot_c = 0;
        double g, tot_g = 0.0, GPA = 0.0;
        cin >> n;
        while (n--) {
            cin >> c >> g;
            tot_c += c;
            tot_g += g * c;
        }
        cout << fixed;
        cout.precision(1);
        cout << tot_c << " " << tot_g / tot_c << '\n';
    }
    return 0;
}