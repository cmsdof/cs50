#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    pyramid(height);
}

void pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i + j < height)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  ");

        for (int j = 0; j < height; j++)
        {
            if (j < i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
