#include <stdio.h>

int main(void){
    unsigned a = 1;
    {
        unsigned x = 2;
    }
    printf("%u", *(&a + 1));
}
