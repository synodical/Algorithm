//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/03/24.
//

#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000000
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int arr[26] = {0, };
    
    int max = -1; // 최대빈도 저장
    int idx = -1; // idx of 최대빈도
    
    for (int i = 0; i < s.length(); i++) {
        if(s[i] < 97) arr[s[i] - 65]++; // Upper case
        else arr[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (max < arr[i]) {
            max = arr[i];
            idx = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (idx == i) continue;
        if (max == arr[i]) {
            cout << '?';
            return 0;
        }
    }
    cout << (char)(idx+65); // 대문자로 출력
    return 0;
}
