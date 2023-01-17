//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/14.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, ans = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vector <pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            int resume, interview;
            cin >> resume >> interview;
            v.push_back({resume, interview});
        }
        sort(v.begin(), v.end()); // 작을수록 높은 순위이다.
        auto tmp = v.front();
        for(int i = 1; i < n; i++) {
            if(v[i].second > tmp.second) continue;
            tmp = v[i];
            ans++;
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            v.push_back({0,0});
        }
        ans = 1;
    }
    return 0;
}
