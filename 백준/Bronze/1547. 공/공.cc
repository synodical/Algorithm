//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/06.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, loc = 1;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x == loc) loc = y;
        else if(y == loc) loc = x;
    }
    cout << loc;
    return 0;
}

