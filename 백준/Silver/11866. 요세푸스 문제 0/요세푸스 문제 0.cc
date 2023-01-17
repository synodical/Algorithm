//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/03.
//

#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    cout << "<";
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (1) {
        for(int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
        else break;
    }
    cout << ">";
    return 0;
}
