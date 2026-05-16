#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int sumscore(string s);

int main(void)
{
    // Prompt for words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Parse each word
    // Test each letter
    int score1 = 0;
    int score2 = 0;
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Store points for letters
    score1 = sumscore(word1);
    score2 = sumscore(word2);

    // Compare player's scores
    if (score1 > score2)
    {
        // printf("Player 1:%i | Player 2:%i\n", score1, score2);
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        // printf("Player 1: %i | Player 2: %i\n", score1, score2);
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int sumscore(string s)
{
    string word = s;
    int score = 0;
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if ((islower(word[i])))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}