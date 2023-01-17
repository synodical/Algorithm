//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/03.
//

// 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다. = queue
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() != 1) {
        q.pop();
        int f = q.front();
        q.pop();
        q.push(f);
    }
    cout << q.front();
    return 0;
}
