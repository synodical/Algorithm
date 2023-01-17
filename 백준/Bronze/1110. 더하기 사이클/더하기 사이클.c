#include <stdio.h>
int main() {
    int a, b, c, d, n, re;
    int count = 0;
    scanf("%d", &n);

    re = n;
    while(1) {
        a = n / 10;
        b = n % 10;
        c = (a + b) % 10;
        d = b * 10 + c;
        n = d;
        count++;
        if(d == re) break;
    }
    printf("%d", count);
    return 0;
}