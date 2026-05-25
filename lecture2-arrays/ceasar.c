#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    int key;
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (only_digits(argv[1]))
    {
        // Convert argv[1] from a `string` to an `int`
        key = atoi(argv[1]);
    } else
    {
        return 1;
    }

    // Prompt user for plaintext
    string text = get_string("plaintext: ");
    string cipher = text;

    // For each character in the plaintext:
    for (int i = 0; i < strlen(text); i++)
    {
        cipher[i] = rotate(text[i], key);
    }

    printf("ciphertext: %s\n", text);

    return 0;
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}


char rotate(char letter, int key)
{
    char c = letter;
    if (isalpha(letter))
    {
        if (islower(letter))
        {
            if (letter + (key % 26) > 122)
            {
                c = '`' + (letter + (key % 26) - 'z');
            } else
            {
                c = letter + (key % 26);
            }
        }

        if (isupper(letter))
        {
            if (letter + (key % 26) > 90)
            {
                c = '@' + (letter + (key % 26) - 'Z');
            } else
            {
                c = letter + (key % 26);
            }
        }
    }
        // if (isdigit(letter) || ispunct(letter)) {}

    return c;
}
