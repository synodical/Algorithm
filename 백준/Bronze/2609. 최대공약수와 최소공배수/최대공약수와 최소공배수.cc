//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/04.
//

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n' << a * b / gcd(a, b);
    return 0;
}

