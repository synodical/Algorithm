#include<iostream>
using namespace std;
int main(){
    int n, a, b, c;
    cin >> n;

    if(n == 2) cin >> a >> b;
    else cin >> a >> b >> c;
    	
    for(int i = 1; i <= a; i++)
    	if(a % i == 0 && b % i == 0 && c % i == 0) //a와 b만 입력받았을 때, c는 0이므로 c%i==0 조건에 충족 
    		cout << i << '\n';
}