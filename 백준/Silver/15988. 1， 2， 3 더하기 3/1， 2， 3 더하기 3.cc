#include <cstring>
#include <iostream>
using namespace std;

long long sol[10000000], t, n, mod = 1000000009;

int main() {
    
    sol[1] = 1; sol[2] = 2; sol[3] = 4;
    for(int i = 4; i <= 1000000; i++) {
        sol[i] = sol[i - 1] + sol[i - 2] + sol[i - 3];
        sol[i] %= mod;
    }
    cin >> t;
    while(t--) {
        cin >> n;
        cout << sol[n] << endl;
    }
}
