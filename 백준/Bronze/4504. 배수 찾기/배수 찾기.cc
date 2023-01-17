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
    cin >> n;
    while (1) {
        cin >> k;
        if (k == 0) {
            break;
        }
        cout << k << " is ";
        if (k % n != 0) {
            cout << "NOT ";
        }
        cout << "a multiple of " << n << ".\n";
    }
    return 0;
}