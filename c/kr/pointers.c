// clang pointers.c -o bin/pointers && ./bin/pointers
#include <stdio.h>

int main() 
{
    int x = 1;
    int *ip;
    ip = &x;


    printf("x: %d\n", x);
    printf("*ip: %d\n", *ip);
    printf("&x: %p\n", &x);
    printf("ip: %p\n", ip);
   
    printf("\n(*ip)++\n");
    (*ip)++;
    printf("x: %d\n", x);
    printf("*ip: %d\n", *ip);
    printf("&x: %p\n", &x);
    printf("ip: %p\n", ip);
    
    printf("\n*ip++\n");
    *ip++;
    printf("x: %d\n", x);
    printf("*ip: %d\n", *ip);
    printf("&x: %p\n", &x);
    printf("ip: %p\n", ip);
    
    return 0;
}
