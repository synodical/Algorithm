#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 5000001;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int y, k, sum_y = 0, sum_k = 0;
        for (int i = 0; i < 9; i++) {
            cin >> y >> k;
            sum_y += y;
            sum_k += k;
        }
        if (sum_y < sum_k) cout << "Korea\n";
        else if(sum_y > sum_k) cout << "Yonsei\n";
        else cout << "Draw\n";
    }
    return 0;
}
