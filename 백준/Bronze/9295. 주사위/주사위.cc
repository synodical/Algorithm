#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 300001;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b << '\n';
    }
    return 0;
}


