//
//  main.cpp
//  boj14928
//
//  Created by LeeYeEun on 2021/12/18.
//

#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int ans = 0;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ans = (ans * 10 + (s[i] - '0')) % 20000303;
    }
    cout << ans;
    return 0;
}
