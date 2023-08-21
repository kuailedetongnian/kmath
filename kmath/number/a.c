#include <stdio.h>
#include <stdlib.h>
#include <math.h>

signed main() {
    int i;
    for(i = 0b0100000; i <= 65; i++) {
        printf("%.14f,", log2(i));
        if(i % 8 == 0 && i != 0)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
