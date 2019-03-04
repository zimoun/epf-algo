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
dual add(dual, dual);
dual sub(dual, dual);
dual div(dual, dual);

#define NEXP 20
dual exponential(dual);

int main () {
    /* the value we are interrested in */
    float a = 2.1;

    /* declare dual numbers */
    dual z, c;

    z = newvar(a, "x");
    c = newcst(1.2, "c");

    /* display the dual number */
    print(z);
    print(c);

    print(exponential(z));
    print(exponential(add(mul(mul(c, z), z), c)));

    printf("Bye.");
    return  0;
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

dual add(dual z1, dual z2) {
    dual z;
    sprintf(z.name, "(%s+%s)", z1.name, z2.name);

    z.value = z1.value + z2.value;
    z.deriv = z1.deriv + z2.deriv;

    return z;
}

dual sub(dual z1, dual z2) {
    dual z;
    sprintf(z.name, "(%s-%s)", z1.name, z2.name);

    z.value = z1.value - z2.value;
    z.deriv = z1.deriv - z2.deriv;

    return z;
}

dual div(dual z1, dual z2) {
    dual z;
    sprintf(z.name, "(%s/%s)", z1.name, z2.name);

    z.value = z1.value / z2.value;
    z.deriv = ((z1.deriv * z2.value) - (z1.value * z2.deriv)) / (z2.value * z2.value);

    return z;
}

dual exponential(dual x) {

    /* temporary variables */
    dual expx  = newcst(1., "");
    dual xk    = newcst(1., "");
    dual kfac  = newcst(1., "");

    float k;
    for (k=1; k<=NEXP; k++) {
        dual kk = newcst(k, "");

        xk   = mul(xk, x);      /* x, x*x, x*x*x, etc. => eval x^k */
        kfac = mul(kfac, kk);   /* 1, 1*2, 1*2*3, etc. => eval k!  */

        dual term_k = div(xk, kfac);

        /* update the Sum with another term */
        expx = add(expx, term_k);

        /* to avoid segmentation fault (because of ugly C)   */
        /* instead of accumalating all the ( and ) and +,*,/ */
        sprintf(expx.name, "");
        sprintf(xk.name, "");
        sprintf(kfac.name, "");
        sprintf(kk.name, "");
    }

    /* pretty print the name */
    sprintf(expx.name, "~(e^(%s))", x.name);
    return expx;
}
