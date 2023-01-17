//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/03/30.
//

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
const int MAX = 1001;
 
int n;
string s[MAX];
 
bool cmp(string a, string b) {
    // 숫자가 같다면 continue;
    if (a == b) return false;
 
    // 숫자가 다르다면 글자를 a b 순으로 붙여보고, b a 순으로 붙여본다.
    // 그래서 ab 혹은 ba 중에 큰 것 경우의 숫자를 앞으로 배치.
    string ab = a + b;
    string ba = b + a;
    if (ab > ba) return true;
    else return false;
}
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> n;
 
   // cin.ignore();
 
    //입력 값이 모두 0인 경우 체크 해주는 flag...
    bool isZero = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] != "0") isZero = false;
    }
 
    if (isZero) cout << 0;
    else {
        sort(s, s + n, cmp);
        for (int i = 0; i < n; i++) cout << s[i];
    }
    return 0;
}
