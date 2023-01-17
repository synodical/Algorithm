//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/09.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmp, ans = 0;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        tmp += v[i];
        ans += tmp;
    }
    cout << ans;
    return 0;
}