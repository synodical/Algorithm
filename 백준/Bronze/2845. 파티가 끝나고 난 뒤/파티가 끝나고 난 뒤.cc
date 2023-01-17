//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
//
#include <iostream>
using namespace std;

int main() {
    int l, p;
    int arr[5];
    cin >> l >> p;
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        arr[i] -= l * p;
    }
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
