#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
    if ( n % 2 == 1) printf("0");
    else if ( (n / 2) % 2 == 0 ) printf("2");
    else printf("1");
    return 0;
}
