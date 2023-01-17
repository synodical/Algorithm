#include <stdio.h>
int main() {
    int S, K, H, sum;
    scanf("%d %d %d", &S, &K, &H);
    sum = S + K + H;
    if( sum >= 100 ) printf("OK");
    else {
        if ( (S < K) && (S < H) ) printf("Soongsil");
        else if ( (K < S) && (K < H) ) printf("Korea");
        else if ( (H < S) && (H < K) ) printf("Hanyang");
    }
    return 0;
}
