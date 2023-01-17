#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 101;
int N, M, arr[MAX][MAX] = {0, };
ll ans = -1;

ll sum(int x1, int y1, int x2, int y2) {
    ll area = 0;
    for (int i = y1; i <= y2; i++)
        for (int j = x1; j <= x2; j++)
            area += arr[i][j];
        
    return area;
}

int main() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp-'0';
        }
    }
    
    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            ll sq1 = sum(0, 0, i, N - 1);
            ll sq2 = sum(i + 1, 0, j, N - 1);
            ll sq3 = sum(j + 1, 0, M - 1, N - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            ll sq1 = sum(0, 0, M - 1, i);
            ll sq2 = sum(0, i + 1, M - 1, j);
            ll sq3 = sum(0, j + 1, M - 1, N - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }

    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            ll sq1 = sum(0, 0, i, N - 1);
            ll sq2 = sum(i + 1, 0, M - 1, j);
            ll sq3 = sum(i + 1, j + 1, M - 1, N - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }
    
    for (int i = M - 1; i > 0; i--) {
        for (int j = 0; j < N - 1; j++) {
            ll sq1 = sum(i, 0, M - 1, N - 1);
            ll sq2 = sum(0, 0, i - 1, j);
            ll sq3 = sum(0, j + 1, i - 1, N - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            ll sq1 = sum(0, 0, M - 1, i);
            ll sq2 = sum(0, i + 1, j, N - 1);
            ll sq3 = sum(j + 1, i + 1, M - 1, N - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }
    
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < M - 1; j++) {
            ll sq1 = sum(0, i, M - 1, N - 1);
            ll sq2 = sum(0, 0, j, i - 1);
            ll sq3 = sum(j + 1, 0, M - 1, i - 1);
            if(ans < sq1 * sq2 * sq3) ans = sq1 * sq2 * sq3;
        }
    }

    cout << ans << '\n';
    return 0;
}

