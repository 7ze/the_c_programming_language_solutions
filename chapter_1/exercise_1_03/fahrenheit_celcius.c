// simple temperature conversion program
// fahrenheit to celcius

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    double celcius, fahrenheit;
    printf("FAHRENHEIT CELCIUS TABLE\n");
    printf("------------------------\n");
    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP) {
        celcius = (5.0 / 9.0) * (fahrenheit - 32);
        printf("%6.2lf*F   -> %7.2lf*C\n", fahrenheit, celcius);
    }
    return 0;
}
