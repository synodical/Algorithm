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

bool cmp(char a, char b) {
    if (a > b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    
    ll sum = 0;
    bool isZero = false;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0');
        if (s[i] - '0' == 0) { // s[i] is zero
            isZero = true;
        }
    }
    if (sum % 3 || !isZero) {
        cout << "-1";
    }
    else {
        sort(s.begin(), s.end(), cmp);
        cout << s;
    }
    return 0;
}

