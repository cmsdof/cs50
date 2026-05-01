#include <stdio.h>
#include <cs50.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = 0;
    int coins = 0;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    coins += calculate_quarters(cents);
    cents = cents % 25;

    coins += calculate_dimes(cents);
    cents = cents % 10;

    coins += calculate_nickels(cents);
    cents = cents % 5;

    coins += calculate_pennies(cents);

    printf("%i\n", coins);
}

int calculate_quarters(int cents)
{
    int quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = cents / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = cents / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = cents / 1;
    return pennies;
}
