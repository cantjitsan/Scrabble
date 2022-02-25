#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//seperating functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:"); //getting input
    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sentences = count_sentences(text);

    int L = total_letters * 100 / total_words; //formulas
    int S = total_sentences * 100 / total_words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int letter = 0;
    for (int i = 0; i < strlen(text); i ++)
    {
        if (isalnum(text[i]))
        {
            letter++;
        }
    }
    return letter; //assigned to total_letter
}

int count_words(string text)
{
    int word = 0;
    for (int i = 0; i < strlen(text); i ++)
    {
        if (isspace(text[i])) //is there a space, consider a word is finished
        {
            word++;
        }
    }
    return word + 1; //assigned to total_words
}

int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0; i < strlen(text); i ++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')//counting sentences when those end with !, . and ?
        {
            sentence++;
        }
    }
    return sentence; //assigned to total_sentences
}
