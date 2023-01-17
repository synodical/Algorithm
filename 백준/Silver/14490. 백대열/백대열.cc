#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // 14490 백대열. 최대공약수로 나누어 출력
    int n, m;
    char c;
    cin >> n >> c >> m;
    cout << n / gcd(n, m) << ":" << m / gcd(n, m);
    return 0;
}
