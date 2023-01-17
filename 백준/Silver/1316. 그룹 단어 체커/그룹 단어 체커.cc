//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[26];

inline int maximum(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, cnt = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        bool flag = true;
                
        for(int j = 0; j < s.length(); j++){
            for(int k = 0; k < j; k++){
                if(s[j] != s[j - 1] && s[j] == s[k]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cnt++;
    }
    cout << cnt;
    return 0;
}

