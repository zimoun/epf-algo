/* provide printf/scanf and other */
#include <stdio.h>

/* Length maximum for some "string" (array of char) */
#define MAXCHAR 1000

typedef struct {
    char name[MAXCHAR];
    float value;
    float deriv;
} dual;

int main () {
    printf("Hi");

    /* the value we are interrested in */
    float a = 2.1;

    /* declare a dual number */
    dual z;

    /* fill the fields                                 */
    /*                                                 */
    /* sprintf is similar to printf                    */
    /*  instead of output to the console               */
    /*  sprintf store the output to its first argument */
    /*     (here z.name)                               */
    sprintf(z.name, "%s", "LE nom bien");
    z.value = a;
    z.deriv = 1.;

    /* display the dual number */
    printf("\n");
    printf("\tName : %s\n", z.name);
    printf("\tValue: %f\n", z.value);
    printf("\tDeriv: %f\n", z.deriv);

    printf("Bye.");
    return 0;
  }
