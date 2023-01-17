#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
int n;
int cur_dir; // 0=east, 1=west, 2=south, 3=north
char c;
int board[100][100];
queue <pair<int, char> > q;
deque <pair<int, int> > d;

void debug() {
    deque<pair<int, int>>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
        board[it->first][it->second] = 2;
    }
    
    for (it = d.begin(); it != d.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }
    cout << '\n';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void change_dir(int& dir, char cmd) {
    if (dir == 0) {
        if (cmd == 'D') dir = 2;
        else if (cmd == 'L') dir = 3;
    }
    else if (dir == 1) {
        if (cmd == 'D') dir = 3;
        else if (cmd == 'L') dir = 2;
    }
    else if (dir == 2) {
        if (cmd == 'D') dir = 1;
        else if (cmd == 'L') dir = 0;
    }
    else if (dir == 3) {
        if (cmd == 'D') dir = 0;
        else if (cmd == 'L') dir = 1;
    }
    return;
}

void move_one_block(int &x, int &y, int cur_dir) {
    switch (cur_dir) {
        case 0:
            y++;
            break;
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            x--;
            break;
        default:
            break;
    }
    d.push_front({x, y});
    return;
}

void go(int x, int y) {
    int time = 0;
    while (1) {
        
        // if 벽에 부딪힘, 자기 몸
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << time;
            return;
        }
        if (time == q.front().first) {
            change_dir(cur_dir, q.front().second); // call by ref로 cur_dir을 cmd에 따라 바꿈
            q.pop();
        }
        
        move_one_block(x, y, cur_dir);
        
        // push 된 머리와 몸통이 닿았는지 검사해야 함
        int a = d.front().first;
        int b = d.front().second; // 뱀의 머리 좌표
        // 머리 좌표를 pop해서 현재 머리 좌표가 deque에 있는지 find
        d.pop_front();
        deque<pair<int, int>>::iterator it;
        for (it = d.begin(); it != d.end(); it++) {
            if (it->first == a && it->second == b) {
                cout << time+1;
                return;
            }
        }
        d.push_front({a, b}); // pop한 머리 좌표는 다시 넣어주기
        
        if (board[x][y] != 1) {
            board[d.back().first][d.back().second] =0;
            d.pop_back();
        }
        board[x][y] = 0; // 먹은 사과는 사라짐
        // debug();
        time++;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k, l, x;
    char c;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        q.push({ x, c });
    }
    d.push_back({ 0,0 });
    cur_dir = 0;
    go(0, 0);

    return 0;
}