#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 101;
int k, n, m;
int main() {
    cin >> k >> n >> m;
    if (k * n > m) {
        cout << k * n - m;
    }
    else cout << "0";
    return 0;
}

