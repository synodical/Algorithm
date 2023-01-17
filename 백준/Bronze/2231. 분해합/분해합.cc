#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    int sum, tmp = 0;
    int m;
    
    cin >> n;
    m = n; // 임시값 m
    
    /* n의 자릿수를 구하는 반복문*/
    while(1) {
        m /= 10;
        tmp++;
        if(m == 0) break;
    }
    
    /* 생성자는 n값 - 자릿수*9 ~ n값 사이이다 */
    for(int i = (n - tmp * 9); i < n; i++) {
        sum = i;
        tmp = i;
        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if(n == sum) {
            cout << i;
            return 0;
        }
    }
    cout << 0; // 생성자가 없을 경우 0 출력
    return 0;
}

