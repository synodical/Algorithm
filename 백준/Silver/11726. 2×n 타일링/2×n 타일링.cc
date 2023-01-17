//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/05/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

int rec[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    rec[1] = 1; rec[2] = 2;
    for (int i = 3; i <= MAX; i++) {
        rec[i] = ( rec[i-1] + rec[i-2] ) % 10007;
    }
    cout << rec[n] % 10007;
}
