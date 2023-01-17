#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 10001;
int queue[MAX];
int front = 0;
int back = 0;
int n;
int size();
void push(int x) {
    queue[back] = x;
    back++;
}
void pop() {
    if (size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << queue[front] << '\n';
    front++;
}
int size() {
    return back - front;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int a;
            cin >> a;
            push(a);
        }
        else if (cmd == "pop") {
            pop();
        }
        else if (cmd == "size") {
            cout << size() << '\n';
        }
        else if (cmd == "empty") {
            if (size() == 0) {
                cout << "1\n";
            }
            else cout << "0\n";
        }
        else if (cmd == "front") {
            if (size() == 0) {
                cout << "-1\n";
            }
            else cout << queue[front] <<'\n';
        }
        else {
            if (size() == 0) {
                cout << "-1\n";
            }
            else cout << queue[back-1] <<'\n';
        }
    }
    return 0;
}


