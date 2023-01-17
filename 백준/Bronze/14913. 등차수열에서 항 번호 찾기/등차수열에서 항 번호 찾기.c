#include <stdio.h>
int main() {
    int a, d, k, n;
    scanf("%d %d %d", &a, &d, &k);

    n = (k - a) / d;
 
    if ((k - a) % d || n < 0) printf("X\n");
    else printf("%d\n", n + 1);

    return 0;
}

