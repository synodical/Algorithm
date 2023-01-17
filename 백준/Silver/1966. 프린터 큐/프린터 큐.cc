#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t, n, m, a; // 중요도 a
    cin >> t;
    while(t--) {
        /* 큐와 우선순위 큐는 while문 안의 지역변수로 둬야 그 값이 매 케이스마다 초기화 됨 */
        queue<pair<int, int>> q; // 위치, 중요도 담는 큐
        priority_queue<int> pq; // 우선순위 큐로 가장 큰 값을 찾음
        
        cin >> n >> m;
        for(int j = 0; j < n; j++) {
            cin >> a;
            q.push(make_pair(j, a));
            pq.push(a);
        }
        
        int cnt = 1;
        while(1) {
            int max = pq.top();
            if(q.front().second == max) { // 큐의 맨 앞에 가장 큰 값이 있음
                if(q.front().first == m) { // 드디어 찾음
                    cout << cnt << '\n';
                    break;
                }
                else { // 큐의 맨 앞에 가장 큰 값이 있지만 찾는 중요도가 아님
                    q.pop();
                    pq.pop();
                    cnt++;
                }
            }
            else { // 큐의 맨 앞에 가장 큰 값이 없음
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}
