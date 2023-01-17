#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 102;
int sum = 0;
int arr[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cur_score = 1;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i]) {
            if (arr[i-1]) cur_score++;
            sum += cur_score;
        }
        else if(arr[i] == 0) cur_score = 1;
    }
    cout << sum;
    return 0;
}