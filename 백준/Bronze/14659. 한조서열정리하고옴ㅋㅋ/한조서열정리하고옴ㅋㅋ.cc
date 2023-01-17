#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, a, cur_max, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> a ;
        v.push_back(a);
    }
    a = 0; // 처치한 적의 수
    for(int i = 0; i < n; i++) {
        if(cur_max <= v[i]){
            cur_max = v[i];
            cnt = max(cnt, a);
            a = 0;
        }
        else a++;
    }
    cnt = max(cnt, a);
    cout << cnt;
    return 0;
}
