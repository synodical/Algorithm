#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int a;
int memo[100] = { 0, };

int fibo(int n) {
    if (n <= 1) return n;
    if (memo[n] > 0) return memo[n];
    memo[n] = fibo(n - 1) + fibo(n - 2);
            return memo[n];
}

int main() {
    cin >> a;
    cout << fibo(a);
    
}
