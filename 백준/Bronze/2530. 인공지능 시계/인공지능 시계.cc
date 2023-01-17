#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100002;
int main(){
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    
    c += d;
    b += c/60;
    a += b/60;

    cout<< a%24 << " " << b%60 << " " << c%60;
}

