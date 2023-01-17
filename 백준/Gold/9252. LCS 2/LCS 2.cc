//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/11.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int len[1001][1001];
int P[1001][1001];
char align_ans[1001];
stack<char> v;
string s1, s2;

inline int Max(int a, int b) {
    return (a > b) ? a : b;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 2; i++) {
        cin >> s1 >> s2;
    }
    
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1])
                len[i][j] = len[i - 1][j - 1] + 1;
            else
                len[i][j] = Max(len[i - 1][j], len[i][j - 1]);
        }
    }
    auto x = s1.length();
    auto y = s2.length();
    cout << len[x][y] << '\n';
    while(x >=1 && y >= 1){
            if(len[x][y] == len[x - 1][y]){
                x--;
            }else if(len[x][y] == len[x][y-1]){
                y--;
            }else{
                v.push(s1[x-1]);
                x--; y--;
            }
        }

    
    while (!v.empty()) {
        cout << v.top();
        v.pop();
    }
    return 0;
}

 
