#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100002;
int main(){
    int l,a,b,c,d, hw, hw1, hw2;
    cin >> l >> a>>b>>c>>d;
    if (a%c == 0) hw1 = a/c;
    else hw1=a/c + 1;
    if (b%d == 0) hw2 = b/d;
    else hw2 =b/d + 1;
    hw = max(hw1, hw2);
    cout << l - hw;
    
}

