//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/11.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int a, b, c;

ll pow(int x, int y) {
    if (y == 0) return 1;
    else {
        ll half = pow(x, y / 2);
        
        if (y % 2 == 0)
            return (half * half) % c;
        else
            return ((half * half) % c * x) % c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << pow(a, b);
    return 0;
}

 
