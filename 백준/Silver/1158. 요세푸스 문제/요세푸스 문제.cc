//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/06.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << "<";

    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}

