#include <cs50.h>
#include <stdio.h>

/*
    This program will take a long input and use the function 'checksum' to return if the checksum passes or not.
    When passed the program will test the input number against the credit card number formats for the chosen companies.

    Each company has its individual function which returns if the the tests passes or not.
    If none of this tests pass, the card will be considered invalid.

*/

int checksum(long);
int visa(long);
int master(long);
int amex(long);

int main(void)
{
    long example = 378282246310005;
    int validation = 0;

    long number = get_long("Number: ");

    validation = checksum(number);
    if (validation == 1)
    {
        validation = 0;
        validation = validation + visa(number);
        validation = validation + master(number);
        validation = validation + amex(number);
        if (validation == 0)
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int amex(long number)
{
    long operator= 1;
    long digit = 999;

    for (int i = 0; i < 14; i++)
    {
        operator= operator* 10;
    }
    digit = (number / operator) % 10;

    if (digit == 3)
    {
        operator= operator/ 10;
        digit = (number / operator) % 10;
        if (digit == 4 || digit == 7)
        {
            printf("AMEX\n");
            return 1;
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}
int master(long number)
{
    long operator= 1;
    long digit = 999;

    for (int i = 0; i < 15; i++)
    {
        operator= operator* 10;
    }
    digit = (number / operator) % 10;

    if (digit == 5)
    {
        operator= operator/ 10;
        digit = (number / operator) % 10;
        if (digit == 5 || digit == 4 || digit == 3 || digit == 2 || digit == 1)
        {
            printf("MASTERCARD\n");
            return 1;
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}

int visa(long number)
{
    long operator= 1;
    long digit = 999;

    for (int i = 0; i < 15; i++)
    {
        operator= operator* 10;
    }
    digit = (number / operator) % 10;

    if (digit == 4)
    {
        printf("VISA\n");
        return 1;
    }
    else
    {
        operator= 1;
        for (int i = 0; i < 12; i++)
        {
            operator= operator* 10;
        }
        digit = (number / operator) % 10;
        if (digit == 4)
        {
            printf("VISA\n");
            return 1;
        }
        else
        {

            return 0;
        }
    }
}

int checksum(long number)
{
    long digit = 999;
    long operator = 1;
    long sum = 0;

    for (int i = 0; i < 17; i++)
    {
        if (i % 2 == 0)
        {
            digit = (number / operator) % 10;
            sum = sum + digit;
        }
        else
        {
            digit = (number / operator) % 10;
            sum = sum + (digit * 2) % 10 + (digit * 2 / 10) % 10;
        }

        operator= operator* 10;
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
