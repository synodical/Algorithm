#include <iostream>
using namespace std;
const int MAX = 10001;
int n, num;
int arr[MAX] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num]++;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < arr[i]; j++)
            cout << i << '\n';
    }
    return 0;
}