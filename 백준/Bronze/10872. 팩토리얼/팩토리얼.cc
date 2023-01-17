//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//

#include <iostream>
using namespace std;

int n;
int fac(int n) {
    if(n <= 1) return 1;
    n *= fac(n-1);
    return n;
}

int main() {
    cin >> n;
    cout << fac(n);
    return 0;
}
