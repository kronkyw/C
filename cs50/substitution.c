// Gets a key as a CLI argument and encrypts a given text
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *encrypt(char *text, char *key);
int check_validity(int argc, char *argv);
int check_key(char *key);
int check_duplicates(char *key);

int main(int argc, char *argv[])
{
    // The check validity function checks if the given key is valid
    int valid = check_validity(argc, argv[1]);
    if (valid == 1)
    {
        return 1;
    }
    string text = get_string("plaintext: ");
    text = encrypt(text, argv[1]);
    printf("ciphertext: %s\n", text);
    return 0;
}

// Checks the validity of the CLI argument and prints error messages and returns 1
// if invalid, otherwise returns 0
int check_validity(int argc, char *key)
{
    if (argc != 2)
    {
        printf("One CLI argument should be passed.\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("CLI argument should be a 26 letter key.\n");
        return 1;
    }
    else if (check_key(key) == 1)
    {
        printf("Key should only contain letters.\n");
        return 1;
    }
    else if (check_duplicates(key) == 1)
    {
        printf("No duplicates should be in key.\n");
        return 1;
    }
    return 0;
}

char *encrypt(char *text, char *key)
{
    // For every character in the text
    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is a letter
        if (isalpha(text[i]))
        {
            // If the letter is capitalised
            if (isupper(text[i]))
            {
                // Makes the letter the capitalised equivalent to the corresponding letter in the key
                text[i] = toupper(key[text[i] - 'A']);
            }
            // If the letter isns capitalised
            else
            {
                // Makes the letter the non capitalised equivalent to the corresponding letter in the key
                text[i] = tolower(key[text[i] - 'a']);
            }
        }
    }
    return text;
}

// Checks if every character in the key is a letter
int check_key(char *key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }
    return 0;
}

// Checks the key for duplicates by comparing every all letters
int check_duplicates(char *key)
{
    for (int i = 0; i < strlen(key) - 1; i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}