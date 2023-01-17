//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//
#include<iostream>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1) {
        string s;
        cin >> s;
        int width = 2;
        if(s.size() == 1 && s[0] == '0') break;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '1') width += 2;
            else if (s[i] == '0') width += 4;
            else width += 3;
        }
        width += s.size() - 1;
        cout << width << '\n';
    }
}
