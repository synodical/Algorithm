//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/10.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        
        string tmp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(tmp.begin(), tmp.end());
                cout << tmp << " ";
                tmp.clear();
            }
            else {
                tmp += s[i];
            }
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << '\n';
    }
    return 0;
}

