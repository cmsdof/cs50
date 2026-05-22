#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int population = 0;
    int years = 0;
    int startSize;
    int endSize;
    do
    {
        // TODO: Prompt for start size
        startSize = get_int("Start Size: ");
    }
    while (startSize < 9);
    do
    {
        // TODO: Prompt for end size
        endSize = get_int("End Size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    population = startSize;
    for (int i = 0; population < endSize; i++)
    {
        population = population + population / 3 - population / 4;
        //years = (endSize - startSize) / (population - startSize);
        years = i + 1;
    }

    // TODO: Print number of years

    printf("%i\n", population);
    printf("Years: %i\n", years);
}
