// simple temperature conversion program
// celcius to fahrenheit

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    double celcius, fahrenheit;
    printf("CELCIUS FAHRENHEIT TABLE\n");
    printf("------------------------\n");
    for (celcius = UPPER; celcius >= LOWER; celcius -= STEP) {
        fahrenheit = 9.0 / 5.0 * celcius + 32;
        printf("%6.2lf*F   -> %7.2lf*C\n", celcius, fahrenheit);
    }
    return 0;
}
