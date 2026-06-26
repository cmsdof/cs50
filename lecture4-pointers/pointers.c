#include <stdio.h>

int main (void)
{
    int n = 50;

    // Declaring a Pointer 
    // The asterisk (*) defines the variable as a pointer to that data type
    // Examples: int*, float*, struct*
    int* p = &n;

    // Assigning an variable's adress to a Pointer
    // The ampersand (&) make so that the adress of the variable is assigned insted of the value
    p = &n;

    printf("%i\n", n);
    printf("%p\n", &n);

}