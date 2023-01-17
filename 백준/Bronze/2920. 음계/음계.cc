#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int arr[10];
int asc=0,dsc=0;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 8; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= 8; i++) {
        if (arr[i] == i) {
            asc++;
        }
        else if (arr[i] == 8-i+1) {
            dsc++;
        }
    }
    if (asc == 8) {
        cout << "ascending";
    }
    else if (dsc == 8) {
        cout << "descending";
    }
    else cout << "mixed";
    return 0;
}


