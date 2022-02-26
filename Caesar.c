#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char cipher(char plain_text, int k);

int main(int argc, string argv[])
{
    int k; //k is for key
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Usage: ./caesar key\n"); //printing guide
        //to show key <= 0, key > 26 and putting more than one digit and space in key-place are invalid.
        return 1;
    }

    k = atoi(argv[1]);

    if (k <= 0) //get positive integer key
    {
        return 1;
    }


    //formula: c[index] = p[index] + key % 26

    string plain_text = get_string("Plain Text:"); //getting plain text

    printf("ciphertext:"); //this will run after getting plain text and executing function
    for (int i = 0; i < strlen(plain_text); i++)
    {
        printf("%c", cipher(plain_text[i], k)); //returning cipher text
    }
    printf("\n");
}

char cipher(char plain_text, int k)
{
    //lowercase remains as lowercase and uppercase remains as uppercase
    if (isupper(plain_text))
    {
        return ((plain_text - 65) + k) % 26 + 65; //according to ASCII, the uppercase A starts at 65.
        //26 indicates total english alphabets
    }

    else if (islower(plain_text))
    {
        return ((plain_text - 97) + k) % 26 + 97; //according to ASCII, the lowercase a starts at 97.
    }

    else
    {
        return plain_text;
    }
}
