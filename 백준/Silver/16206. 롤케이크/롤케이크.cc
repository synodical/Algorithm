#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a, cut, ans, tmp;
vector<int> v;

bool compare(int a, int b) // 길이가 10의 배수이며 작을수록 먼저 선택되어야 함
{
    if (a % 10 == 0 && b % 10 == 0) return a < b;
    else if (a % 10 == 0 && b % 10 != 0) return true;
    else if (a % 10 != 0 && b % 10 == 0) return false;
    else return a < b;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), compare);
    
    ans = 0; tmp = 0; // v[i]가 10보다 큰 경우 10씩 빼가면서 ans를 카운트할 임시 변수 tmp
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 10) ans++;
        else if(v[i] > 10)
        {
            if(m == 0) continue;
            tmp = v[i];
            while (1)
            {
                if(tmp < 10) break;
                else if(tmp == 10)
                {
                    ans++; break;
                }
                else
                {
                    if(m == 0) break;
                    tmp -= 10;
                    ans += 1;
                    m -= 1;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}

