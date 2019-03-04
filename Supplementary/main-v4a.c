/* provide printf/scanf and other */
#include <stdio.h>

/* Length maximum for some "string" (array of char) */
#define MAXCHAR 1000

typedef struct {
    char name[MAXCHAR];
    float value;
    float deriv;
} dual;

      /* signature of the function */
      /* defined after the main    */
dual newvar(float, char*);
dual newcst(float, char*);
void print(dual);

dual mul(dual, dual);

int main () {
    printf("Hi");

    /* the value we are interrested in */
    float a = 2.1;

    /* declare a dual number */
    dual z;


    /* fill the fields */
    z = newvar(a, "x");

    /* display the dual number */
    print(z);

    dual zz = mul(z, z);
    print(zz);

    printf("Bye.");
    return 0;
  }


/*  DEFINITION of the functions/subprogram */

dual newvar(float val, char* avoile) {
    dual z;
    sprintf(z.name, "%s", avoile);
    z.value = val;
    z.deriv = 1.;
    return z;
}

dual newcst(float val, char* avoile) {
    dual z;
    sprintf(z.name, "%s", avoile);
    z.value = val;
    z.deriv = 0.;
    return z;
}

void print(dual z) {
    printf("\n");
    printf("\tName : %s\n", z.name);
    printf("\tValue: %f\n", z.value);
    printf("\tDeriv: %f\n", z.deriv);
}

dual mul(dual z1, dual z2) {
    dual z;
    sprintf(z.name, "(%s*%s)", z1.name, z2.name);

    z.value = z1.value * z2.value;
    z.deriv = (z1.deriv * z2.value) + (z1.value * z2.deriv);

    return z;
}
