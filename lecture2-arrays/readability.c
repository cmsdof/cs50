#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


float calc_grade(int letters, int words, int sentences);

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    // Prompt for text
    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Get number of letters
        if (islower(text[i]) || isupper(text[i]))
            letters++;

        // Get number of words
        if ((islower(text[i - 1]) || isupper(text[i - 1])) && (text[i] == 44 || text[i] == 46 || text[i] == 63 || text[i] == 33 || text[i] == 58 || text[i] == 59 || text[i] == 32))
            words++;

        // Get number of sentences
        if (islower(text[i-1]) && (text[i] == 46 || text[i] == 63 || text[i] == 33))
        {
            sentences++;
        }
    }


    float grade = calc_grade(letters, words, sentences);
    
    //printf("N of Letters: %i | N of Words: %i | N of Sentences: %i\n", letters, words, sentences);
    //printf("Grade: %f\n", grade);

    if (grade < 1)
    {
        // Grades lower than 1 will be displayed as "Before Grade 1"
        printf("Before Grade 1\n");
    }
    else
    {
        // Grades 16 and above will be displayed as 16+
        if (grade >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            // Other grades will be displayed as an integer
            printf("Grade %i\n", (int) round(grade));
        }
    }

}

float calc_grade(int letters, int words, int sentences)
{
    // Calculating Grade based on the Coleman-Liau index
    float l = (100.0 / words) * letters;
    float s = (100.0 / words) * sentences;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    return index;
}