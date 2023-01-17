#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1001;
int d1, d2;
const double pi = 3.14159265358979;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> d1 >> d2;
    printf("%.6f",2*d1 + 2*d2*pi);
    return 0;
}


