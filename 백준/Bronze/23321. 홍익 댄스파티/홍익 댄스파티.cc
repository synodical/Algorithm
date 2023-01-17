#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
vector<string> v;

int state[10000]; // 현재 상태(준비, 도약중, 착석)
char ready[5] = {'.','o','m','l','n'}; // 준비 배열
char ing[5] = {'o','w','l','n','.'}; // 도약중 배열
char sit[5] = {'.','.','o','L','n'}; // 착석 배열
char ans[5][10000]; // 답안 출력 이차원 배열

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    for (int i = 0; i < v[0].size(); i++) {
        if (v[1][i] == 'o') { // 현 상태가 도약 준비
            state[i] = 0;
        }
        else if (v[1][i] == 'w') {
            state[i] = 1;
        }
        else if (v[1][i] == '.') {
            state[i] = 2;
        }
    }
    
    // ing -> ready, ready -> ing
    for (int i = 0; i < v[0].size(); i++) {
        if (state[i] == 0) { // 현 상태가 도약 준비라면
            for (int j = 0; j < 5; j++) {
                ans[j][i] = ing[j];
            }
        }
        else if (state[i] == 1) {
            for (int j = 0; j < 5; j++) {
                ans[j][i] = ready[j];
            }
        }
        else {
            for (int j = 0; j < 5; j++) {
                ans[j][i] = sit[j];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}


