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

int main () {
    printf("Hi");

    /* the value we are interrested in */
    float a = 2.1;

    /* declare a dual number */
    dual z;


    /* fill the fields */
    z = newvar(a, "LE nome bien");

    /* display the dual number */
    printf("\n");
    printf("\tName : %s\n", z.name);
    printf("\tValue: %f\n", z.value);
    printf("\tDeriv: %f\n", z.deriv);

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
