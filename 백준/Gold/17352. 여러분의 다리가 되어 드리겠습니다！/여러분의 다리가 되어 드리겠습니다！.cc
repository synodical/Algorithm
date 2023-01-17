#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 300001;
int n,m;
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
    cin >> n;
    for (int i = 0; i <= n; i++) {
        Parent[i] = i;
    }
    for (int i = 0; i < n-2; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
    int parent_of_1 = getParent(1);
    for (int i = 2; i <= n; i++) {
        if (parent_of_1 != getParent(i)) {
            cout << "1 " << i;
            break;
        }
    }
    return 0;
}


