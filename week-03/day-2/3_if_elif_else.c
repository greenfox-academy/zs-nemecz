#include <stdio.h>
#include <stdlib.h>

// Define the TOTORO macro which holds a number
#define TOTORO 19

int main()
{
    // Use the #if, #elif, #else macros

    // If the TOTORO macro is greater than 3 print out "Greater than 3"
    #if TOTORO > 3
        printf("Greater than 3");
    // TOTORO
    // If the TOTORO macro is lower than 3 print out "Lower than 3"
    #elif TOTORO < 3
        printf("Lower than 3");
    // TOTORO
	// Else print out "TOTORO is 3"
	#else// TOTORO
        printf("Totoro is 3");
    #endif // TOTORO

    return 0;
}
