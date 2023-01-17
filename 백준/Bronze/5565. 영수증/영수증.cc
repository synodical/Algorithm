// boj 5565.cpp
#include <iostream>
using namespace std;
const int MAX = 1001;
int total, sum;
int arr[9];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> total;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << total - sum;
    return 0;
}