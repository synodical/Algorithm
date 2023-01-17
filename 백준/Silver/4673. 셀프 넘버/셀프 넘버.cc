//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/18.
//
#include <iostream>
#include <cstdio>
#define MAX 10001

using namespace std;

int d(int n){
    int ans = n;
    while(true){
        if(n == 0) break;
        ans += n % 10; //1의자리를 더함
        n /= 10;
    }
    return ans;
}
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool isself[MAX] = {false,};
    int sum = 0;
    
    for(int i=1; i<=10000; i++){
        int x = d(i);
        if(x <= 10001) {
            isself[x] = true;
        }
    }
 
    for(int i=1; i<=10000; i++){
        if(!isself[i])
            printf("%d\n", i);
    }
 
    return 0;
}
