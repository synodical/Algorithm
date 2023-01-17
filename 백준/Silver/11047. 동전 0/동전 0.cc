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

vector<int> coin;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        coin.push_back(a);
    }
    sort(coin.begin(), coin.end(), greater<>());
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        while (k >= coin[i]) {
            k -= coin[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}

