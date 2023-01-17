#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, ans = 64; // 8*8 의 최댓값: 64
    cin >> n >> m;
    char c[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    /* 왼쪽 맨 위칸부터 8*8, 왼쪽 맨위를 옮겨줄 수 있는 범위 */
    for(int a = 0; a < n - 7; a++) {
        for(int b = 0; b < m - 7; b++) {
            int n1 = 0; int n2 = 0;

            for(int i = a; i < a + 8; i++) {
                for(int j = b; j < b + 8; j++) {
                    if(c[i][j] == 'W') {
                        if((i + j) % 2 == 0) n1++;
                        else n2++;
                    }
                    else {
                        if((i + j) % 2 == 0) n2++;
                        else n1++;
                    }
                }
            }
            ans = min({ans, n1, n2});
        }
    }
    cout << ans;
    return 0;
}

