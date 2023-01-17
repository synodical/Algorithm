//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//n := ⌊(n1 + 1)(n2 + 1)/(n12 + 1) - 1⌋

int main() {
    int n1, n2, n12, ans;
    cin >> n1 >> n2 >> n12;
    ans = ((n1 + 1)*(n2 + 1) / (n12 + 1)) - 1;
    cout << floor(ans);//내림하는 함수입니다.
}
