#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

vector<int> v;
int cnt[4], p[3] = { 1,2,3 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        cnt[a]++;
    }

    int mn = INF;
    do {
        int arr[4][4] = { 0, }; //p[i]번 위치의 j의 개수

        int sp = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[p[i]]; j++)
                arr[p[i]][v[sp + j]]++;
            sp += cnt[p[i]];
        }

        mn = min(mn, arr[1][2]+arr[1][3]+max(arr[2][3],arr[3][2]));
    } while (next_permutation(p, p+3));

    cout << mn << '\n';
}
