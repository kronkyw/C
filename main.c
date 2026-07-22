#include <stdbool.h>
#include <stdio.h>
#include "chess.h"

int main(void)
{
    current_player = 'W';
    populate_board();
    print_board();
    while (true)
    {
        scanf("%s", move);
        if (move[0] == 'e') return 0;
        *move = notation_to_num();
        if (!check_if_valid())
        {
            print_board();
            printf("Invalid move!\n");
            continue;
        }
        invert_player();
        move_piece();
        print_board();
    }
    return 0;
}