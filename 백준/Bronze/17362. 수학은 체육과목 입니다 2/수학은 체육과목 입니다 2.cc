#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int n;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if(n % 8 >= 1 && n%8 <= 5){
        cout << n%8;
    }
    else if(n%8 == 6){
        cout << "4";
    }
    else if(n%8 == 7){
        cout << "3";
    }
    else if(n%8 == 0){
        cout << "2";
    }
    return 0;
}


