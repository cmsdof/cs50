#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
    }

    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext
    string text = get_string("plaintext: ");

    // For each character in the plaintext:
    for (int i = 0; i < strlen(text); i++)
    {
        // Rotate the character if it's a letter
        // if (text[i] ==  char) {}
    }

    printf("cyphertext: %s\n", text);

    return 0;
}
