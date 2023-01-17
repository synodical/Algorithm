#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1'000'000'001;
int N, M;
class SegmentTree {
public:
    vector<ll> seg;
    int n;
    SegmentTree(int n) {
        seg.resize(4*n + 5);
        this->n = n;
    }
    ll update(int node, int l, int r, int target, ll val) {
        if (target < l || target > r) {
            return seg[node];
        }
        if (target == l && target == r) {
            return seg[node] = val;
        }
        int mid = (l+r) / 2;
        return seg[node] = min(
                   update(node*2, l, mid, target, val),
                   update(node*2+1, mid+1, r, target, val)
                   );
    }
    ll query(int node, int l, int r, int wl, int wr) {
        if (r < wl || l > wr) {
            return MAX;
        }
        if (r <= wr && wl <= l) {
            return seg[node];
        }
        int mid = (l+r) / 2;
        return min(
                   query(node*2, l, mid, wl, wr),
                   query(node*2+1, mid+1, r, wl, wr)
                   );
    }
};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    SegmentTree seg(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg.update(1, 0, N-1, i, a);
    }
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        cout << seg.query(1, 0, N-1, a, b) << '\n';
    }
    
    return 0;
}


