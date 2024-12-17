#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int score = grade(letters, words, sentences);

    // printf("letters: %d\nwords: %d\nsentences: %d\ngrade: %d", letters, words, sentences, score);

    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (score >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", score);
    }
    return 0;
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {

        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count += 1;
        }
    }
    return count;
}

int grade(int letters, int words, int sentences)
{
    float l = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);
    return index;
}
