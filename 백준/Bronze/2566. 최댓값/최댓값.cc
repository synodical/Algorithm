#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 9;
int arr[MAX][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int ans = -1;
    int x,y;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > ans) {
                ans = arr[i][j];
                x = i; y = j;
            }
        }
    }
    cout << ans << '\n' << x+1 << " " << y+1;
    return 0;
}