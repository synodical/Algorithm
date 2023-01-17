#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;
int M[51];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, M, m, left, right, index;
    int cnt = 0;
    cin >> n >> M;
    
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for(int i = 0; i < M; i++) {
        cin >> m;
        if(dq.front() == m) dq.pop_front(); // 1번 수행
        else {
            index = std::find(dq.begin(), dq.end(), m) - dq.begin();
            
            left = index;
            right = dq.size() - index;
            if(left < right) {
                for(int j = 0; j < left; j++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    cnt++;
                }
           //     cout << left << " "<< cnt << endl;
                dq.pop_front();
            }
            else {
                for(int j = 0; j < right; j++) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    cnt++;
                }
          //      cout << right << " "<< cnt << endl;
                dq.pop_front(); // 중요, 한번 더 오른쪽으로 가야 1번 수행
            }
        }
    }
    cout << cnt;
    return 0;
}
