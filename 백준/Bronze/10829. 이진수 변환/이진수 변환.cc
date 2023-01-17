//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//

#include <iostream>
using namespace std;
using ll = long long;

int fib[21];
void binary(ll b) {
    if(b > 1) binary(b / 2);
    cout << b % 2;
}

int main() {
    ll n;
    cin >> n;
    binary(n);
    return 0;
}
