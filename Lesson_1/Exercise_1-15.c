#include <stdio.h>

// Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

#define LOWER 0
#define UPPER 300
#define STEP 20

double fahrToCelsius(double fahr);
double celsiusToFahr(double celsius);

int main() {
    double fahr = LOWER;
    double celsius = LOWER;

    printf("fahr celsius\n");
    while (fahr <= UPPER) {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr += STEP;
    }

    printf("celsius fahr\n");
    while (celsius <= UPPER) {
        printf("%3.0f %6.1f\n", celsius, celsiusToFahr(celsius));
        celsius += STEP;
    }
}

double fahrToCelsius(double fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

double celsiusToFahr(double celsius) {
    return (celsius / (5.0/9.0)) + 32.0;
}
