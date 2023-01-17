// 16563  어려운 소인수분해
// TLE -> 에라토스테네스의 체 사용

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;

const int MAX = 5000000 + 1;
ll n;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<ll> PrimeN(MAX);
    for(ll i = 2; i <= MAX; ++i) {
        if (PrimeN[i]) continue;
        for(ll j = i * i; j <= MAX; j+=i)
            if (!PrimeN[j]) PrimeN[j] = i;
    }
    
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        while(PrimeN[k]) {
            cout << PrimeN[k] << ' ';
            k /= PrimeN[k];
        }
        cout << k << '\n';
    }
    return 0;
}
