#include <stdio.h>

long power(long x,long y);
int card_len(long card);
void card_type(long card, int n);
int card_valid(long card, int n);

int main(void)
{
    long card;
    printf("Enter card number: "); // Asks the user for card number
    scanf("%li", &card);
    int len = card_len(card); // Assigns length of card number to len
    if (card_valid(card, len) == 1) card_type(card, len); // Checks if card is valid, if it is prints card type,
    else printf("INVALID\n");                          // otherwise prints invalid
}

int card_valid(long card, int n) //Checks if card is valid
{
    int sum = 0, num;
    for (int i = 1; i < n; i++)
    {
        num = (card / power(10, (n - i))); // Gets the first digit of the card
        card = card % (long)(power(10, (n - i))); //Removes first digit of the card
        if ((i % 2 != 0 && n % 2 == 0) || (i % 2 == 0 && n % 2 != 0)) // Checks length of card,
                                                                      // depending on the length, 
        {                                                             // adds every second digit starting from the first or second digit
            if (num < 5)
            {
                sum += num * 2;
            }
            else 
            {
                sum += (num * 2 / 10) + (((num * 2) % 10));
            }
        }
        else sum += num;
    }
    sum += card;
    if (sum % 10 == 0) return 1;
    else return 0;
}

int card_len(long card)
{
    int n = 0;
    while (card>100)
    {
        n++;
        card /= 10;
    }
    return (n+2);
}

void card_type(long card, int n)
{
    card /= power(10,(n-2));
    if (n == 15 && (card == 34 || card == 37))
    {
        printf ("AMEX\n");
    }
    else if (n == 16 && card > 50 && card < 56)
    {
        printf ("MASTERCARD\n");
    }
    else if ((n == 13 || n == 16) && card / 10 == 4)
    {
        printf ("VISA\n");
    }
    else printf ("INVALID\n");
}

long power(long x,long y)
{
    long z = x;
    for (int i = 1; i < y; i++) z *= x;
    return z;
}