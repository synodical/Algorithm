// 정규식과 일치->대체
// FSM, 유한 오토마타로도 해결 가능
#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin>>s;
	cout<<(regex_match(s,regex("(100+1+|01)+"))?"SUBMARINE":"NOISE");
}