//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//

#include <iostream>
using namespace std;

int n;
int fib[21];
int fac(int n) {
    if(n <= 1) return 1;
    n *= fac(n-1);
    return n;
}

int main() {
    cin >> n;
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n];
    return 0;
}
