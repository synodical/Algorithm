#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const int MAX = 10001;
int n;
int d[MAX];
int cnt(int a) { // a의 제곱근의 약수 개수 반환 (약수의 pair 개수)
    int ans = 0;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) { // i가 a의 약수라면
            ans++;
        }
    }
    return ans;
}
int main(void) {
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i-1] + cnt(i);
    }
    cout << d[n];
    return 0;
}
