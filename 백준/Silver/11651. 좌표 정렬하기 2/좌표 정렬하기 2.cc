//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/03/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}
