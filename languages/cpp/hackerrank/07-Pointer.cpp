#include <stdio.h>

void update(int *a,int *b) {
    int aOriginal = *a, bOriginal = *b;
    *a = aOriginal + bOriginal; *b = aOriginal > bOriginal ? aOriginal - bOriginal : bOriginal - aOriginal; 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}