//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/04.
//

#include <iostream>
#include <vector>
using namespace std;

inline int maximum(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> c = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    string s;
    cin >> s;
    for (int i = 0; i < c.size(); i++) {
        while (1) {
            int idx = s.find(c[i]);
            if(idx == string::npos) break; // found
            s.replace(idx, c[i].length(), "#");
        }
    }
    cout << s.size();
    return 0;
}

