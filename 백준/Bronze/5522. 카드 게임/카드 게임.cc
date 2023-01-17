//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/16.
//
#include <iostream>
using namespace std;
int main () {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans;
}