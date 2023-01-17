#include <iostream>
#include <string>
#include <stack>
using namespace std;
using ll = long long;
const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, num, arr[MAX], card[MAX] = {0, };
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int i1 =0; int i2 =1; int i3 = n -1;
    num = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            card[i1] = num;
            if (card[i1 + 1] == 0) i1++; // 다음 칸 비면 i1증가
            else i1 = i2 + 1;
        }
        else if (arr[i] == 2) {
            if (card[i1 + 1] == 0) i2 = i1 + 1;
            else i2 += 1;
            card[i2] = num;
        }
        else {
            card[i3] = num;
            i3--;
        }
        num--;
    }
    for (int i = 0; i < n; i++) cout << card[i] << ' ';
}

 
