//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/05/02.
//
#include <iostream>
using namespace std;

int main(){
    int n, t, c, p, ans = 0;
    cin >> n >> t >> c >> p;
    ans = ((n - 1) / t) * c * p;
    cout << ans;
    
    return 0;
}
