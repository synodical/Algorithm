#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
using ll = long long;

struct cmp {
    bool operator() (ll a, ll b) {
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

priority_queue<ll, vector<ll>, cmp> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if(!x) {
            if(pq.empty()) cout << "0" << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}
