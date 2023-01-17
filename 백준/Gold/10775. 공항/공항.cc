#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 1e6;
int G, P;
int Parent[MAX];
int getParent(int n1) {
    if (Parent[n1] == n1) return n1;
    else return Parent[n1] = getParent(Parent[n1]);
}
void unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 != n2) {
        Parent[n2] = n1;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> G >> P;
    for (int i = 1; i <= G; ++i) {
        Parent[i] = i;
    }
    int gate, empty_gate;
    for (int i = 1; i <= G; i++) Parent[i] = i;
    int cnt = 0;
    for (int i = 0; i < P; ++i) {
        cin >> gate;
        empty_gate = getParent(gate);
        if (empty_gate != 0) {
            cnt++;
            unionParent(empty_gate - 1, empty_gate);
        }
        else break;
    }
    cout << cnt << '\n';
    return 0;
}


