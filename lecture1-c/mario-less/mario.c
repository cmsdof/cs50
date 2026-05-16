#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    float letters = 0;
    float words = 0;
    float sentences = 0;
    // Prompt for text
    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Get number of letters
        if (islower(text[i]) || isupper(text[i]))
            letters++;

        // Get number of words
        if (islower(text[i-1]) && text[i] == ' ')
            words++;

        // Get number of sentences
        if (islower(text[i-1]) && ispunct(text[i]))
        {
            sentences++;
            words++;
        }
    }

    printf("N of Letters: %f | N of Words: %f | N of Sentences: %f\n", letters, words, sentences);

    float index = 0.0588 * (100 * (letters / words)) - 0.296 * (100 * (sentences / words)) - 15.8;
    printf("Grade: %f\n", index);

}