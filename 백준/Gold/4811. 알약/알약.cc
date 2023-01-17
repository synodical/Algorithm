//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/03.
//

#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const int MAX = 33;

ll dp[MAX][MAX];
ll dfs(int W, int H) {
    if(W == 0) return 1; // 반으로 조각난 알약이 한개도 없음
    if(dp[W][H]) return dp[W][H];
    if(H > 0) dp[W][H] += dfs(W, H - 1) + dfs(W - 1, H + 1); // 현재 반 조각 뽑을 경우 + 완전한 것 뽑을 경우(h++)
    else dp[W][H] += dfs(W - 1, H + 1);
    return dp[W][H];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(1) {
        cin >> n;
        if(!n) return 0;
        cout << dfs(n, 0) << '\n';
    }
    return 0;
}
