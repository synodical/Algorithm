#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, a, b, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    /* n 쌍 입력받고 종료 시간 기준으로 오름차순 정렬함*/
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ b, a });
    }
    sort(v.begin(), v.end());
    
    a = 0, cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second < a) continue;
        a = v[i].first;
        cnt++; // 최대 회의실 개수
    }
    cout << cnt;
    return 0;
}
