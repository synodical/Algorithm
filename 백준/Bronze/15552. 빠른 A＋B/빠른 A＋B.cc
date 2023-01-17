//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/06.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}
