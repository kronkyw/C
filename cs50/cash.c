#include <stdio.h>

const int quarter = 25, dime = 10, nickel = 5, cent = 1; // Gives coins their value in cents

int get_change(void);
int get_quarter(int change);
void print_change_amount(int change);

int main(void)
{
    int change_owed = get_change(); // Gets owed change
    print_change_amount(change_owed); 
}

int get_change(void)
{
    int change_owed;
    do
    {
        printf("Change owed: ");
        scanf("%i", &change_owed); // Gets owed change
        getchar();       // Clears the scanf buffer
    }
    while (change_owed <= 0);
    return change_owed;
}

int get_coin(int change, int coin_value)
{
    int coin = 0;
    for (int i = 1; i * coin_value <= change; i ++)
    {
        coin++;
    }
    return coin;
}

void print_change_amount(int change)
{
    int quart = get_coin(change, quarter);
    change -= quart * quarter;
    int di = get_coin(change, dime);
    change -= di * dime;
    int nick = get_coin(change, nickel);
    change -= nick * nickel;
    int ce = get_coin(change, cent);
    int sum = quart + di + nick + ce;
    printf("%i\n", sum);
}