// Kruskal Algorithm Using Union & Find
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const int MAX = 1e6;
int Parent[MAX]; // Parent[node] == parent of node
int num_of_friend[MAX];
map<string, int> m;

int getParent(int n) {
    if (Parent[n] == n) return n;
    else return Parent[n] = getParent(Parent[n]);
}
int unionParent(int n1, int n2) {
    n1 = getParent(n1);
    n2 = getParent(n2);
    if (n1 != n2) {
        Parent[n2] = n1;
        num_of_friend[n1] += num_of_friend[n2];
        num_of_friend[n2] = 1;
    }
    return num_of_friend[n1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        m.clear();
        int f, cnt = 1;
        cin >> f;
        for (int i = 1; i <= f*2; i++) {
            Parent[i] = i;
            num_of_friend[i] = 1;
        }
        for (int i = 1; i <= f; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s1) == m.end()) {
                m[s1] = cnt++;
            }
            if (m.find(s2) == m.end()) {
                m[s2] = cnt++;
            }
            cout << unionParent(m[s1], m[s2]) << '\n';
        }
    }
    return 0;
}