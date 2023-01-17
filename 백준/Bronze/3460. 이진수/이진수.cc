#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 46;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int d=0;
        while (n > 0) {
            if (n % 2 == 1) {
                cout <<d << " ";
            }
            n /= 2;
            d++;
        }
        cout << '\n';
    }
    return 0;
}
