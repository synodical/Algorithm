#include <cstring>
#include <iostream>
using namespace std;

long long dp[100], n;

long long fibo(int n) {
    if (n <= 1) return dp[n] = n;
    if (dp[n] > 0) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    for(int i = 0; i < 100; i++) dp[i] = -1;
    cin >> n;
    cout << fibo(n);
}
