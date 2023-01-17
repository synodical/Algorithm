//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b;
    vector<int> v(21);
    for (int i = 0; i < 21; i++) {
        v[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;

        for (int j = 0; j < (b - a) / 2 + 1; j++) {
            swap(v[a + j], v[b - j]);
        }
    }
    
    for (int i = 1; i < 21; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

