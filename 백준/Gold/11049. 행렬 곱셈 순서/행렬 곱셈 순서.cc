#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 501;
const int INF = 987654321;
int n, trash;
int M[MAX][MAX]; // M[i][j] = i<j일때 i번째 행렬~j번째 행렬까지 곱하는 원소단위 곱셈의 최소 횟수
int d[MAX];
// 답 = M[1][n]
// M[1][n] = M[1][k] + M[k+1][n] + d0dkdn
// M[i][j] = i<=k<=j-1일때 min(M[i][k] + M[k+1][j] + di-1dkdj)
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
   // cin >> d[0]; cin >> trash;
    for (int i = 0; i < n-1; i++) {
        cin >> d[i]; cin >> trash;
    }
    cin >> d[n-1] >> d[n];
   //for (int i = 0; i < n+1; i++) cout << d[i] << " ";
    
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }
    for (int diagonal = 1; diagonal <= n-1; diagonal++) { // diagonal - 1은 주 대각선의 바로위에 있는 대각선
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal; // j - i = diagonal = 몇번째 대각선인지 나타냄
            M[i][j] = INF;
            for (int k = i; k <= j-1; k++) {
                M[i][j] = min(M[i][j], M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]);
            }
        }
    }
    cout << M[1][n];
    return 0;
}
