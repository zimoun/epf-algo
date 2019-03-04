#include <stdio.h>
#include <math.h>
#include <limits.h>
int main () {
    float x=1., f=1., ff;
    while (!isinf(f)) {
        ff = f;

        f = f * x;

        x = x + 1.;
        printf("%.0f!  \t= %f\n", x-1, f);
    }
    return 0;
}
