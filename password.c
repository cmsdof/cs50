// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
// Creating Requirement variables
    bool number = false;
    bool upper = false;
    bool lower = false;
    bool punct = false;

//Testing each char against its value on the ASCII table
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 48 && password[i] <= 57)
        {
            number = true;
        }
        else
        {
            if (password[i] >= 65 && password[i] <= 90)
            {
                upper = true;
            }
            else
            {
                if (password[i] >= 97 && password[i] <= 122)
                {
                    lower = true;
                }
                else
                {
                    punct = true;
                }
            }
        }
    }
// Testing if password has at least 1 of each of the requirements.
    if (number == true && upper == true && lower == true && punct == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
