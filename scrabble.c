#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word); //function initialization

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);//below function's score will be stored in word1
    int score2 = compute_score(word2);//below function's score will be stored in word2

    // TODO: Print the winner
    //comparing scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n"); //when two scores are equal

    }
}

int compute_score(string word)
{
    int score = 0;
    int s, no;
    for (int x = 0; x < strlen(word); x++) //repeating after word's length
    {
        if (isupper(word[x]))
        {
            no = word[x] - 65;
            s = POINTS[no];//s locates points inside point array
        }

        else if (islower(word[x]))
        {
            no = word[x] - 97;
            s = POINTS[no];//s locates points innside point array
        }

        else
        {
            s = 0;
        }

        score = score + s;
    }
    return score; //<--it goes to word1 and words()
}
