//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/17.
//
#include <iostream>
using namespace std;
int main () {
    int a, ans = 0;
    for (int i = 0; i < 6; i++) {
        cin >> a;
        ans += a;
    }
    cout << ans * 5;
    return 0;
}
