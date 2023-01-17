//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/17.
//
#include <iostream>
using namespace std;
int main () {
    int ax, ay, az;
    int bx, by, bz;
    cin >> ax >> ay >> az >> bx >> by >> bz;
    cout << bx - az << ' ' << by / ay << ' ' << bz - ax;
    return 0;
}
