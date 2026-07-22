#ifndef CHESS_H_
#define CHESS_H_

// This global variable stores the whole board,
// the first 2 square brackets hold the position
typedef struct
{
    char colour;
    char piece;
}board;

// The player variables store the colour of the current and other player
extern char current_player;
extern char other_player;

// The move variable stores the current move in a format of:
// move[0] and move[1] storing the x and y position of the piece that is being moved
// move[2] and move[3] storing the x and y position to where the piece will be moved
extern char move[4];

extern board Board[8][8];

void invert_player(void);
char notation_to_num(void);
void move_piece(void);
bool check_if_valid(void);
bool general_valid(void);
bool pawn_valid(void);
bool rook_valid(void);
bool bishop_valid(void);
bool queen_valid(void);
void populate_board(void);
void populate_row(int row, char colour);
void populate_colour(void);
void print_board(void);


#endif