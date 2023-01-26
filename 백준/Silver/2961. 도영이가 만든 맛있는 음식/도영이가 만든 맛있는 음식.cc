#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// 신맛은 곱이고 쓴 맛은 합이다.

int main() {
    int n, s, b;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s >> b;
        v.push_back({s, b});
    }
    sort(v.begin(), v.end());
    int azi = 10000000;
    for (int i = 0; i < n; ++i) {
        vector<int> visit;
        for (int j = 0; j < i; ++j) {
            visit.push_back(0);
        }
        for (int j = n-i; j > 0; --j) {
            visit.push_back(1);
        }

        do{
            int sutpai = 1;
            int nigai = 0;
            for(int i=0; i<v.size(); i++) {

                if (visit[i] != 0) {
//                    cout << " " <<  v[i].first << " " << v[i].second << " ";
                    sutpai *= v[i].first;
                    nigai += v[i].second;
                }

            }
            azi = min(azi, abs(sutpai - nigai));
//            cout << '\n';
        }while(next_permutation(visit.begin(),visit.end()));

    }
    cout << azi;
    return 0;
}


