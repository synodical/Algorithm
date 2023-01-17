#include <stdio.h>
int main() {
    int n;
    int min = 1000001;
    int max = -1000001;
    int t= 0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);

        if(min > t) {
            min = t;
        }
        if(max < t)
            max = t;
    }
    
    printf("%d %d", min, max);
    
return 0;
}