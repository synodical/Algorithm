#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, n3 = 0, n5 = 0;
    
    cin >> n;
    /* 3kg를 최대한 적게 쓰자. 5의 배수가 될때까지 3kg씩 빼자 */
    while(n % 5 != 0 && n >= 0) {
        n -= 3;
        n3++;
    }
    if(n < 0) {
        cout << "-1";
    }
    else {
        n5 = n / 5;
        cout << n3 + n5;
    }
    return 0;
}

