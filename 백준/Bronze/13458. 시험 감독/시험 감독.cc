//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/15.
//
#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int b, c;
    ll ans = 0;
    cin >> b >> c;
    for (int i = 0; i < n; i++) {
        arr[i] -= b;
        ans++;
        if (arr[i] > 0) {
            if(arr[i] % c) ans += (arr[i] / c) + 1;
            else ans += arr[i] / c;
        }
    }
    cout << ans;
}
