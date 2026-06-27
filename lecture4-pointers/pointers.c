#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char* string;

int main (void)
{
    int number = 50;

    // Declaring a Pointer
    // The asterisk (*) defines the variable as a pointer to that data type
    // Examples: int*, float*, struct*
    int* p;

    // Assigning an variable's adress to a Pointer
    // The ampersand (&) make so that the adress of the variable is assigned insted of the value
    p = &number;

    printf("%i\n", number);
    printf("%p\n", &number);
    printf("%p\n", p);

    // Strings in C are sequences of Char Pointers
    char* s = "hi!";
    printf("%p\n", s);

    // We can see that each character comes after the other in memory as well.
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);

    // And since adresses are numbers, we can also do pointer arithmetic with them.
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2));

    // It is the exact fact that they are Pointers that:
    char* t = s;
    // Iterating t is the same as iterating s, simply because they're the same adress points to the same place in memory

    // To solve that issue we must assign t to a different memory location.
    // And to do it we must before allocate in memory then copy the values of s

    t = malloc(strlen(s) + 1);

    // It is also common practice to test for NULL after allocating memory.
    if (t == NULL)
    {
        return 1;
    }

    // Copying values
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}