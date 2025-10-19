/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "taylor_sine.h"
#include <stdbool.h>
#include <assert.h>

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
double taylor_sine(double x, int n) {
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series
    assert(n > 0);

    double result = x; // 1st term of tailor series is already x
    double numerator = result;
    double denominator = 1;
    bool even = true; // alternates between - and +
    for (int i=1 ; i<n ; i++) { // calculates 2nd term onwards
        numerator *= x * x;
        denominator *= 2*i * (2*i+1);
        if (even) {
            result -= numerator/denominator;
            even = false;
        }
        else {
            result += numerator/denominator;
            even = true;
        }
    }
        
    return result;
}


// int main() {
//     taylor_sine(3.14159265358979323846 / 6.0, 10);

//     return 1;
// }