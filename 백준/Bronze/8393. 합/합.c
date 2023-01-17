#include <stdio.h>
int main() {
    int n;
    int total=0;
    
    scanf("%d", &n);
    
    for(int i = 0; i <=n;i++) {
        total+=i;

    }
    printf("%d\n", total);
    return 0;
}
