//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + 1 < v[i]) break;
        sum += v[i];
    }
    cout << sum + 1;
    return 0;
}

