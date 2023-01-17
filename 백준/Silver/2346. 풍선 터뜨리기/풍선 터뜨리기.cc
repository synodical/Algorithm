//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/10.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    deque<pair<int, int>> dq;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        dq.push_back({a, i});
    }
    while (!dq.empty()) {
        auto balloon = dq.front();
        cout << balloon.second << " ";
        dq.pop_front();
        /* when balloon > 0 */
        for (int i = 1; i < balloon.first; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        /* when balloon < 0 */
        for (int i = 0; i > balloon.first; i--) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
    return 0;
}

 
