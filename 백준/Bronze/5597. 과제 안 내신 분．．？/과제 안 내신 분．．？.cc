#include <iostream>
using namespace std;
using ll = long long;
int arr[31];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 28; i++) {
        int a;
        cin>> a;
        arr[a] = 1;
    }
    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}


