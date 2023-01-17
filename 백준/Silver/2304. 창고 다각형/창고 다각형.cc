#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

stack<int> st;
int arr[1001], MAX_H, Left[1000], Right[1000], sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, h;
        cin >> l >> h;
        arr[l] = h;
    }
    for (int i = 0; i < 1000; i++) {
        MAX_H = max(arr[i], MAX_H);
        Left[i] = MAX_H;
    }
    MAX_H = 0;
    for (int i = 1000; i >= 0; i--) {
        MAX_H = max(arr[i], MAX_H);
        Right[i] = MAX_H;
    }
    for (int i = 0; i < 1000; i++) {
        sum += min(Left[i], Right[i]);
    }
    cout << sum;
    return 0;
}

 
