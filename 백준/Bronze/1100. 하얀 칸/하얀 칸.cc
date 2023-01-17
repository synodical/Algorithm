#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int ans = 0;
    char chess[8][8];
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
            if(chess[i][j] == 'F' && (i + j) % 2 == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}

