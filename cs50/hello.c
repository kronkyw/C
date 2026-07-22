#include <stdio.h>

int main (void)
{
    int n=8300000;//approximate max length of int, string can usually take more but I doubt anyone has that big a name
    char str[n];
    printf("Whats your name? ");
    fgets(str, n, stdin);
    printf("Hello, %s\n", str);
}
