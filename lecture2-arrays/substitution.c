#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int valid(string key);
string encript(string key, string text);
char ALPHABET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    //Prompt user the correct usage of the arguments
    if (argc < 2 || argc >= 3)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Storing key to variable
    string key = argv[1];
    string text;

    //Validating key
    if (valid(key) == 1)
    {
        //Happy Path
        text = get_string("plaintext: ");
        printf("ciphertext: %s\n", encript(key, text));
    }
    else
    {
        //Error handling
        if (valid(key) == 2)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            printf("Invalid Key\n");
            return 1;
        }
    }
}

//Key validation function
int valid(string key)
{
    int size = 0;
    //Checking for size and captalizing all letters
    for (size = 0; key[size] != '\0'; size++)
    {
        if (isalpha(key[size]))
        {
            key[size] = toupper(key[size]);
        }
        else
        {
            //Error 3 is for ivalid chars on key
            return 3;
        }
    }
    if (size != 26)
    {
        //Error 2 is for wrong key size
        return 2;
    }
    else
    {
        //If lenght check passed we validate for repating letters
        int counter = 0;
        for (int i = 0; key[i] != '\0'; i++)
        {
            counter = 0;
            for (int j = 0; key[j] != '\0'; j++)
            {
                if (key[i] == key[j])
                {
                    //If a letter is counter more dan once we return the invalid key error.
                    counter += 1;
                    if (counter > 1)
                    {
                        return 3;
                    }
                }
            }
        }
        //If all passes we return positive
        return 1;
    }
}

string encript(string key, string text)
{
    //The encription functions takes the key and the text
    string compare[] = {key, ALPHABET};
    //It takes the key and store in a array along side the ALPHABET
    bool match = false;
    //Than it takes a loop cheking if the char in the current position is alphabetic
    for (int i = 0; text[i] != '\0'; i++)
    {
        match = false;
        if (isalpha(text[i]))
        {
            //If it is it will scan the ALPHABET for the match
            for (int j = 0; match != true; j++)
            {
                if (toupper(text[i]) == compare[1][j])
                {
                    // In the case of a match the function will use the alphabet position to map the correct key value.
                    // Respecting if its capitalization.
                    if (islower(text[i]))
                    {
                        text[i] = tolower(compare[0][j]);
                    }
                    else
                    {
                        if (isupper(text[i]))
                        {
                            text[i] = compare[0][j];
                        }
                        else
                        {
                            text[i] = text[i];
                        }
                    }
                    match = true;
                }
            }
        }
        else
        {
            //If the char in the position is not alphabetic it won't change.
            text[i] = text[i];
        }
    }
    return text;
}
