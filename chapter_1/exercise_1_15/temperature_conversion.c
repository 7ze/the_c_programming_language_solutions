// program for temperature conversion using functions

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double get_fahrenheit(double celcius);
void display_temperature_table(void);

int main() {
    display_temperature_table();
    return 0;
}

double get_fahrenheit(double celcius) {
    return 9.0/5.0 * celcius + 32;
}

void display_temperature_table(void) {
    double celcius, fahrenheit;
    printf("CELCIUS FAHRENHEIT TABLE\n");
    printf("------------------------\n");
    for (celcius = UPPER; celcius >= LOWER; celcius -= STEP) {
        fahrenheit = get_fahrenheit(celcius);
        printf("%6.2lf*F   -> %7.2lf*C\n", celcius, fahrenheit);
    }
}
