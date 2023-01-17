//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/05/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10

int main() {
    vector<int> v, v2;
    for (int i = 0; i < 3; i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 2; i++) {
        int c;
        cin >> c;
        v2.push_back(c);
    }
    sort(v2.begin(), v2.end());
    cout <<v.front() +v2.front() - 50;
}
