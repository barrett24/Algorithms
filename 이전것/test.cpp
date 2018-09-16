#include "example.h"
#define MAX 100
#define MIN 10.00

void subpro(var int a, float b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}  

int main(void) {
    int a = MAX;
    float b = MIN;
    subpro(a, b);
}
