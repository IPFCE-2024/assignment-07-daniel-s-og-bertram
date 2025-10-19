#include <math.h>
#include <stdio.h>
#include "./include/taylor_sine.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double  input; //the input into sin() and taylor_sine()
    int     terms; //how many taylor terms to use
    
    //the big picture conclusion here is that each successive taylor term ideally creates a more and more accurate result. For larger values of x though, a huge number of terms are needed, and for large enough values of x, we hit the ceiling on double float's accuracy.

    // here, sin() and taylor_sine() match at 20 terms. For 5 terms, taylor_sine() is accurate only to 2 decimals, and for 10 terms it prints the same result as sin(), but is negative, so sin(pi) = 0.000000, whereas taylor_sine(pi) = -0.000000
    // taylor_sine(pi) for 20 terms is the same as sin(), at least in what it prints.
    input = M_PI; terms = 5;        printf("input = pi              terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = M_PI; terms = 10;       printf("input = pi              terms = 10      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = M_PI; terms = 20;       printf("input = pi              terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    // here, they match at 5 terms already, probably because sin(x) is approximately x for small values, so taylor_sine() would actually be very close even at 1 term, where the output is just x.
    input = 1.0E-5; terms = 5;      printf("input = 1.0 x 10^-5     terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1.0E-5; terms = 10;     printf("input = 1.0 x 10^-5     terms = 10      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1.0E-5; terms = 20;     printf("input = 1.0 x 10^-5     terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    // here, they don't match at all. The size of the numbers in the taylor terms become too large, and eventually result in taylor_sine() returning nan.
    input = 1.0E20; terms = 5;      printf("input = 1.0 x 10^20     terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1.0E20; terms = 10;     printf("input = 1.0 x 10^20     terms = 10      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1.0E20; terms = 20;     printf("input = 1.0 x 10^20     terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));

    // same as above, but the result is instead negative for taylor_sine with 5 terms. The others, 10 terms and 20 terms, remain nan.
    input = -1.0E20; terms = 5;     printf("input = -1.0 x 10^20    terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = -1.0E20; terms = 10;    printf("input = -1.0 x 10^20    terms = 10      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = -1.0E20; terms = 20;    printf("input = -1.0 x 10^20    terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    // these are small values (1 to 1000) that are each ran with 5 terms and then with 20.
    // for 1.0, 5 terms already match with sin(), but for sin(2.0) we need more than 5 terms if we want more than 3 accurate decimals.
    // 20 terms are identical to sin() up until sin(20.0), where the result hasn't converged yet. Beyond that, they just diverge more and more.
    input = 1.0;    terms = 5;      printf("input =  1.0            terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1.0;    terms = 20;     printf("input =  1.0            terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 2.0;    terms = 5;      printf("input =  2.0            terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 2.0;    terms = 20;     printf("input =  2.0            terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 5.0;    terms = 5;      printf("input =  5.0            terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 5.0;    terms = 20;     printf("input =  5.0            terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 10.0;   terms = 5;      printf("input =  10.0           terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 10.0;   terms = 20;     printf("input =  10.0           terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 20.0;   terms = 5;      printf("input =  20.0           terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 20.0;   terms = 20;     printf("input =  20.0           terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 50.0;   terms = 5;      printf("input =  50.0           terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 50.0;   terms = 20;     printf("input =  50.0           terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 100.0;  terms = 5;      printf("input =  100.0          terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 100.0;  terms = 20;     printf("input =  100.0          terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 200.0;  terms = 5;      printf("input =  200.0          terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 200.0;  terms = 20;     printf("input =  200.0          terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 500.0;  terms = 5;      printf("input =  500.0          terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 500.0;  terms = 20;     printf("input =  500.0          terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    
    input = 1000.0; terms = 5;      printf("input =  1000.0         terms = 5       math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));
    input = 1000.0; terms = 20;     printf("input =  1000.0         terms = 20      math.h sin = %f     taylor_sine = %f\n", sin(input), taylor_sine(input, terms));

    return 0;
}