#include <stdio.h>

void loopprint(int end, char *word);
void create_piramid(int n);

int main(void)
{
    int n;
    do
    {
        printf("How tall should the piramids be? ");
        scanf("%i", &n); // Gets piramid height
        getchar();       // Clears the scanf buffer
    }
    while (n > 8 || n < 1); // Checks if n satisfies conditions,
                            // if a letter is typed n will equal 0
                            // which will continue the loop
    create_piramid(n); // Creates piramids
}

void create_piramid(int n) // Function to create piramids
{
    loopprint((n - 1), " "); // Make it so that the first row doesnt create newlines and spaces
    printf("#\n");
    for (int i = 2; i <= n; i++)
    {
        loopprint((n - i), " ");
        loopprint(i, "#");
        printf("\n");
    }
}

void loopprint(int number, char *word) // function to printf word number times
{
    for (int i = 0; i < number; i++)
    {
        printf("%s", word);
    }
}