#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_sum_of_letters(char *word);
int letter_value(char letter);
void winner(int *points);

// Defines the number of players, the program can be used with multiple players
// if there is multiple people with the highest amount of points the first one is the winner, them's the rules
const int N_of_players = 2;

int main(void)
{
    string player_word[N_of_players];
    int points[N_of_players];
    // Gets the word of every player and gets points for every players word
    for (int i = 0; i < N_of_players; i++)
    {
        player_word[i] = get_string("Player %i: ", i + 1);
        points[i] = get_sum_of_letters(player_word[i]);
    }
    winner(points);
}

int get_sum_of_letters(char *word)
{
    int sum = 0;
    // Runs for every letter in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Adds the value of the letter to sum
        sum+=letter_value(word[i]);
    }
    return sum;
}

void winner(int *points)
{
    // The winner variable holds 2 things, the points of the current winner, and the place of the current winner
    int winner[2] = {points[0], 1};
    // The n variable is here to check if everyone has the same score
    int n = 0;
    for (int i = 0; i < N_of_players; i++)
    {
        if (winner[0] == points[i])
        {
            n++;
        }
        // If the current winner has less points than the next player, the next player becomes the winner
        else if (winner[0] < points[i])
        {
            winner[0] = points[i];
            winner[1] = i + 1;
        }
    }
    // If n is equal to the number of players, that means that everyones scores were equal
    if (n == N_of_players)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", winner[1]);
    }
}

// Returns the value of the letter by checking which one it is
int letter_value(char letter)
{
    // Makes letter lower so the program just has to check lower letters
    letter = tolower(letter);
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'l' || letter == 'n' || letter == 'o' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u')
    {
        return 1;
    }
    else if (letter == 'd' || letter == 'g')
    {
        return 2;
    }
    else if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
    {
        return 3;
    }
    else if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' || letter == 'y')
    {
        return 4;
    }
    else if (letter == 'k')
    {
        return 5;
    }
    else if (letter == 'j' || letter == 'x')
    {
        return 8;
    }
    else if (letter == 'q' || letter == 'z')
    {
        return 10;
    }
    // If its none of those, its not a letter
    else
    {
        return 0;
    }
}