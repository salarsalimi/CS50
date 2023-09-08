#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user input
    string text = get_string("Text: ");
    int letters = 0;
    int word = 0;
    int sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentence++;
        }
        char c = text[i];
        if (isalpha(c) != 0)
        {
            letters++;
        }
    }
    word++; // last word count
    float l = (float) letters * 100 / word;
    float s = (float) sentence * 100 / word;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);

    // Printinmg results

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
