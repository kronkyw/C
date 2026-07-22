// Gets a text and prints the reading level of the text

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

float letter_complexity(char *text, int words);
float sentence_complexity(char *text, int words);
int n_of_words(char *text);
void print_grade(int index);

int main(void)
{
    char *text = get_string("Text: ");
    int words = n_of_words(text);
    // Index is the reading level of the text, it is a float for more precise calculations
    float index = letter_complexity(text, words);
    index -= sentence_complexity(text, words);
    // Sends the int of the rounded index to be printed
    print_grade((int) (round(index)));
}

int n_of_words(char *text)
{
    // The sum is the sum of all words, it is initialised as 1 because the first word doesnt have a space before it
    int i = 0, sum = 1;
    while (text[i] != 0)
    {
        // If the current character is a space, sum is increased by 1
        if (text[i] == ' ')
        {
            sum++;
        }
        i++;
    }
    return sum;
}

float letter_complexity(char *text, int words)
{
    int sum = 0, i = 0;
    while (text[i] != 0)
    {
        // If the current char is a letter, sum is increased by 1
        if (isalpha(text[i]))
        {
            sum++;
        }
        i++;
    }
    // avg is the average number of letters per 100 words
    float avg = 0.0588 * ((float) sum / words) * 100;
    return avg;
}

float sentence_complexity(char *text, int words)
{
    int sum = 0, i = 0;
    while (text[i] != 0)
    {
        // If the current char is ., ! or ?, it means the sentence has ended and sum is increased by 1
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sum++;
        }
        i++;
    }
    // avg average number of sentences per 100 words
    float avg = (0.296 * sum / words) * 100;
    // Returns avg + 15.8, as an additional 15.8 is removed from the index of the reading level
    return avg + 15.8;
}

void print_grade(int index)
{
    // If index is smaller then 1, prints before Grade 1
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    // Else if index is greater than 16, prints Grade 16+
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    // Otherwise prints Grade followed by the index
    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}