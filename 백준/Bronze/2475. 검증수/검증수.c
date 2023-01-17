#include <stdio.h>

int main() {
    int a, b,c,d,e;
    int r = 0;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    r = ( a*a + b*b + c*c+d*d+e*e) % 10;
    printf("%d",r);

    
    return 0;
}