#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1010

using ll = long long;
using namespace std;

int adjacent[MAX][2];
bool visited[MAX];
int dp[MAX];
vector<int> Kvec;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        int l, r;
        cin >> l >> r;
        adjacent[i][0] = l; // left
        adjacent[i][1] = r; // right
    }
    for(int i = 0; i < M; i++) {
        char s;
        cin >> s;
        if(s == 'L') Kvec.push_back(0); // idx 0부터 들어감
        else Kvec.push_back(1);
    }
    
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        for (int j = 0; j < M; j++) { // Kvec이 0부터 이므로 j = 0
            int LR = Kvec[j];
            tmp = adjacent[tmp][LR];
        }
        dp[i] = tmp; // cycle을 dp에 저장, 나중에 % 로 출력
    }
    /*반복되는 구간 길이(len) 반복 구간 시작점(start) 확인 */
    int start = 1;
    int len = 0;
    while (start <= N) {
        visited[start] = true;
        len++;
        start = dp[start]; // dp[start] == K의 결과로 나오는 사이클 값 ex) dp[1] = 2, dp[2] = 3 ...
        if (visited[start]) break; // 전부 순회했으면 len = 4, start = 1
    }
    
    int cur = 1;
    for (int i = 0; i < N; i++) {
        if (cur == start) {
            len -= i;
            break;
        }
        cur = dp[cur];
        K--;
        if (K == 0) break;
    }
    // 반복 구간 시작점까지 K줄여가며 이동, 그 전에 K가 0이면 탈출
    if (K == 0) {
        cout << cur;
        return 0;
    }

    int cycle;
    cycle = K % len;
    for (int i = 0; i < cycle; i++) {
        cur = dp[cur];
    }
    cout << cur;
    // K 를 len으로 나눈 나머지만큼 cur 이동시킨 후 출력

    return 0;
}
