#include <stdio.h>
#include <math.h>

// Function defining the equation
double f(double x) {
    return pow(5, x + 1) - 3 * x - 25;
}

// Bisection method
double bisection(double a, double b, double eps) {
    double c;
    while (fabs(b - a) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return (a + b) / 2;
}

// Simple iteration method
double simpleIteration(double x0, double eps) {
    double x1;
    do {
        x1 = (pow(5, x0 + 1) - 25) / 3;
        if (fabs(x1 - x0) <= eps) {
            return x1;
        }
        x0 = x1;
    } while (1);
}

// Chord method
double chord(double x0, double x1, double eps) {
    double x2;
    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) <= eps) {
            return x2;
        }
        x0 = x1;
        x1 = x2;
    } while (1);
}

// Tangent method (Newton-Raphson method)
double tangent(double x0, double eps) {
    double x1;
    do {
        x1 = x0 - f(x0) / (pow(5, x0 + 1) * log(5) - 3);
        if (fabs(x1 - x0) <= eps) {
            return x1;
        }
        x0 = x1;
    } while (1);
}

// Secant method
double secant(double x0, double x1, double eps) {
    double x2;
    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) <= eps) {
            return x2;
        }
        x0 = x1;
        x1 = x2;
    } while (1);
}

int main() {
    double a = 1, b = 3; // Initial interval for bisection
    double eps = 1e-6; // Precision

    printf("Bisection method root: %lf\n", bisection(a, b, eps));
    printf("Simple iteration method root: %lf\n", simpleIteration(1.0, eps));
    printf("Chord method root: %lf\n", chord(1.0, 1.5, eps));
    printf("Tangent method root: %lf\n", tangent(1.0, eps));
    printf("Secant method root: %lf\n", secant(1.0, 1.5, eps));

    return 0;
}