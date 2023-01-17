#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
typedef long long ll;
#define maxx 200001

int n;
int rumor[maxx]; // 루머를 믿은 시간
vector<int> adjacent_list[maxx];
queue<pair<int, int>> q; // 최초 유포자의 번호, 믿기 시작한 시간
/* 왜 틀렸는지 모르겠음... 다시 보기
void input() {
    int a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while(1) {
            cin >> a;
            if (!a) break;
            adjacent_list[i].push_back(a); // adjacent list
        }
    }
    memset(rumor, -1, sizeof(rumor));
    int m;
    cin >> m;
    while (m--) {
        cin >> a;
        rumor[a] = 0;
        q.push({a, 0});
    }
}

void bfs() {
    while (q.size()) {
        int cur = q.front().first;
        int t = q.front().second; // 현재 시간?
        q.pop();
        for(int nx : adjacent_list[cur]) { // adjacent list를 순회하는 range based for
            if(rumor[nx] == -1) {
                int cnt = 0; //
                for(int _nx : adjacent_list[nx]) {
                    if(!rumor[_nx] && rumor[_nx] <= t)
                        cnt++;
                }
                int _size = adjacent_list[nx].size(); //
                int half = ceil(_size / 2);
                if(cnt >= half) {
                    q.push({nx, t++});
                    rumor[nx] = t++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << rumor[i] << " ";
}
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while(1) {
            int a;
            cin >> a;
            if (!a) break;
            adjacent_list[i].push_back(a); // adjacent list
        }
    }
    memset(rumor, -1, sizeof(rumor));
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        rumor[num] = 0;
        q.push({num, 0});
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second; // 현재 시간?
        q.pop();
        for(auto nx : adjacent_list[cur]) { // adjacent list를 순회하는 range based for
            if(rumor[nx] == -1) {
                int cnt = 0; //
                for(auto _nx : adjacent_list[nx]) {
                    if(~rumor[_nx] && rumor[_nx] <= t) {
                        cnt += 1;
                    }
                }
                int _size = adjacent_list[nx].size(); //
                int half = _size / 2 + (_size & 1 ? 1 : 0);
                if(cnt >= half) {
                    rumor[nx] = t + 1;
                    q.push({nx, t + 1});
                    
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << rumor[i] << " ";

   // return 0;
}

/*
int n;
vector<int> v[200001];
int r[200001];
queue<pair<int, int> > q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while(1){
            int a;
            cin >> a;
            if (!a) break;
            v[i].push_back(a);
        }
    }
    memset(r, -1, sizeof(r));
    int m;
    cin >> m;
    for (; m--;) {
        int num;
        cin >> num;
        r[num] = 0;
        q.push({ num,0 });
    }
    while (!q.empty()) {
        int node = q.front().first;
        int t = q.front().second;
        q.pop();
        for (auto nxt : v[node]) {
            if (r[nxt] == -1) {
                int cnt = 0;
                for (auto _nxt : v[nxt]) {
                    if (~r[_nxt] && r[_nxt] <= t) {
                        cnt += 1;
                    }
                }
                int _size = v[nxt].size();
                int half = _size / 2 + (_size & 1 ? 1 : 0);
                if (cnt >= half) {
                    r[nxt] = t + 1;
                    q.push({ nxt,t + 1 });
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
}
 
*/
