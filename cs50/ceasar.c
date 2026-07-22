// Takes a key as an argument, and then offsets all letters in a given text by key
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(int key, char *text);
int check_validity(int argc, char **argv);
int is_num(char *s);

int main(int argc, char *argv[])
{
    // Checks if valid arguments have been passed
    if (check_validity(argc, argv) == 1)
    {
        return 1;
    }
    string text = get_string("plaintext: ");
    text = encrypt(atoi(argv[1]), text);
    printf("ciphertext: %s\n", text);
    return 0;
}

// Encrypts a given text by offsetting all letters by key
char *encrypt(int key, char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 'A' + key) % 26 + 'A';
            }
            else 
            {
                text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
    return text;
}

// Checks if a valid number of arguments was passed and if the argument was valid
int check_validity(int argc, char **argv)
{
    // Checks if the number of arguments is valid
    if (argc != 2)
    {
        printf("There should only be one command-line argument\n");
        return 1;
    }
    // Checks if the argument was zero or not a number
    else if (atoi(argv[1]) == 0 || is_num(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checks string for anything other than digits
int is_num(char *s)
{
    for (int i = 1; i < strlen(s); i++)
    {
        // If the current character is not a digit, returns 1
        if (!(s[i] >= '0') || !(s[i] <= '9'))
        {
            return 1;
        }
    }
    return 0;
}