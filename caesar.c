#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc >= 3 || argc <= 1)
    {
        printf("Wrong Number of command argument is given\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // printf("%i",argv[1][i]);
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]) % 26;

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int c = 0;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            c = plaintext[i] + key;
            if (c > 122)
            {
                c = 97 + c - 123;
                printf("%c", c);
            }
            else
            {
                printf("%c", c);
            }
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            c = plaintext[i] + key;
            if (c > 90)
            {
                c = 65 + c - 91;
                printf("%c", c);
            }
            else
            {
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
