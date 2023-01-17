#include <stdio.h>
int main() {
    int x,y;
    scanf("%d %d", &x, &y);
    
    if(y < 45) {
        y = y + 60;
        x = x - 1;
        if(x < 0) x = 23;
    }
    printf("%d %d", x, y - 45);

return 0;
}