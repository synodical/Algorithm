//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//
#include<iostream>
#include<string>

using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        arr[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << arr[i]<<" ";
    }
}
