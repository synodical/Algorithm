#include <iostream>
#include <stdlib.h> 
//절대값 함수 abs를 위해서 
using namespace std;
int main() { 
    int n[4]; //4명의 스킬레벨 
    for (int i = 0; i < 4; i++) 
        scanf("%d", &n[i]);
    printf("%d", abs((n[3] + n[0]) - (n[2] + n[1])));
    return 0;
}

//출처: https://greenteacreamfrappuccino.tistory.com/306 [Jeonil_Dev_log]