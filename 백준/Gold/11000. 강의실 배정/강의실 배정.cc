#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 현재 거리, 정점 번호/ 작은수부터 나오게 하는 방법

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector< pair<int, int> > v(n); // 간선 정보
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second); // 최소 한개의 강의실
    
    for (int i = 1; i < n; i++) {
        if(pq.top() <= v[i].first) { // 강의실 가장 빨리 끝나는 수업 종료 시간이 i번째 수업 시작시간보다 빠를 때
            pq.pop();
        }
        pq.push(v[i].second);
    }
    cout << pq.size() << '\n';

    return 0;
}
