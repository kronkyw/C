// Simple chess game
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

void invert_player(void);
char notation_to_num(void);
void move_piece(void);
bool check_if_valid(void);
bool general_valid(void);
bool blocked(void);
bool blocked_up(int diff);
bool blocked_down(int diff);
bool pawn_valid(void);
bool check_pawn_capture (void);
bool rook_valid(void);
bool bishop_valid(void);
bool queen_valid(void);
bool knight_valid(void);
void populate_board(void);
void populate_row(int row, char colour);
void populate_colour(void);
void print_board(void);

board Board[8][8];

char current_player;
char other_player;

char move[4];

void invert_player(void)
{
    if (current_player == 'W')
    {
        current_player = 'B';
        other_player = 'W';
    }
    else 
    {
        current_player = 'W';
        other_player = 'B';
    }
}

// Converts the notation into position
char notation_to_num(void)
{
    move[1] = move[1] - '1';
    move[3] = move[3] - '1';
    move[0] = move[0] - 'A';
    move[2] = move[2] - 'A';
    return *move;
}

// Actually moves the pieces
void move_piece(void)
{
    Board[move[3]][move[2]].piece = Board[move[1]][move[0]].piece;
    Board[move[3]][move[2]].colour = Board[move[1]][move[0]].colour;
    Board[move[1]][move[0]].piece = ' ';
    Board[move[1]][move[0]].colour = 'X';
}

// Checks if the move is valid
bool check_if_valid(void)
{
    if (!general_valid()) return false;
    if (Board[move[1]][move[0]].piece == 'P') return pawn_valid();
    if (Board[move[1]][move[0]].piece == 'R') return rook_valid();
    if (Board[move[1]][move[0]].piece == 'B') return bishop_valid();
    if (Board[move[1]][move[0]].piece == 'Q') return queen_valid();
    if (Board[move[1]][move[0]].piece == 'N') return knight_valid();
    return true;
}

// Checks if the move fit general rules: no going off the board, moving an empty square etc...
bool general_valid(void)
{
    if (move [0] == move[2] && move[1] == move[3]) return false;
    if (Board[move[1]][move[0]].colour != current_player) return false;
    for (int i = 0; i < 4; i++) if (move[i] > 7 || move[i] < 0) return false;
    if (Board[move[3]][move[2]].colour == current_player) return false;
    return blocked();
}

bool blocked(void)
{
    int diff[] = {move[2] - move[0], move[3] - move[1]};
    if (diff[0] == 0 && diff[1] != 0)
    {
        for (int i = 1; i < abs(diff[1]); i++)
        {
            if (diff[1] > 0)
            {
                if (Board[move[1] + i][move[0]].colour == current_player) return false;
            }
            else
            {
                if (Board[move[1] - i][move[0]].colour == current_player) return false;
            }
        }
    }
    else
    {
        for (int i = 1; i < abs(diff[0]); i++)
        {
            if (diff[0] > 0)
            {
                if (Board[move[1]][move[0] + i].colour == current_player) return false;
            }
            else
            {
                if (Board[move[1]][move[0] - i].colour == current_player) return false;
            }
        }
    }
    return true;
}

// Checks if the pawn move is valid
bool pawn_valid(void)
{
    if (move[3] == (move[1] + 2) && move[1] == 1 && Board[move[3]][move[4]].colour == 'X' && current_player == 'W')
    {
        return true;
    }
    else if (move[0] == move[2] && move[3] == (move[1] + 1) && Board[move[3]][move[4]].colour == 'X' && current_player == 'W')
    {
        return true;
    }
    else if (move[3] == (move[1] - 2) && move[1] == 6 && Board[move[3]][move[4]].colour == 'X' && current_player == 'B')
    {
        return true;
    }
    else if (move[0] == move[2] && move[3] == (move[1] - 1) && Board[move[3]][move[4]].colour == 'X' && current_player == 'B')
    {
        return true;
    }
    else
    {
        return check_pawn_capture();
    }
}

bool check_pawn_capture (void)
{
    if (Board[move[2]][move[3]].colour == other_player && move[3] == (move[1] + 1) && (move[0] == move[2] + 1 || move[0] == move[2] - 1))
    {
        return true;
    }
    else return false;
}

// Checks if the rook move is valid
bool rook_valid(void)
{
    if (move[0] != move[2] && move[1] != move[3]) return false;
    else return true;
}

// Checks if the bishop move is valid
bool bishop_valid(void)
{
    if (move[0] - move[2] == move[1] - move[3]) return true;
    else if (move[0] + move[1] == move[2] + move[3]) return true;
    else return false;
}

// Checks if the queen move is valid
bool queen_valid(void)
{
    if (bishop_valid() || rook_valid()) return true;
    else return false;
}

// Checks if the knight move is valid
bool knight_valid(void)
{
    if (move[0] + 1 == move[2] && move[1] + 2 == move[3]) return true;
    if (move[0] - 1 == move[2] && move[1] + 2 == move[3]) return true;
    if (move[0] + 1 == move[2] && move[1] - 2 == move[3]) return true;
    if (move[0] - 1 == move[2] && move[1] - 2 == move[3]) return true;
    if (move[0] + 2 == move[2] && move[1] + 1 == move[3]) return true;
    if (move[0] - 2 == move[2] && move[1] + 1 == move[3]) return true;
    if (move[0] + 2 == move[2] && move[1] - 1 == move[3]) return true;
    if (move[0] - 2 == move[2] && move[1] - 1 == move[3]) return true;
    return false;
}

// Checks if the king move is valid
bool king_valid(void)
{
    int diff[] = {move[0] - move[2], move[1] - move[3]};
    if (diff[0] > 1 || diff[0] < -1 || diff[1] > 1 || diff[1] < -1) return false;
    else return true;
}

// Populates the board, this should only be done once
void populate_board(void)
{
    for (int i = 0; i < 8; i++)
    {
        Board[1][i].piece = 'P';
        Board[1][i].colour = 'W';
        Board[6][i].piece = 'P';
        Board[6][i].colour = 'B';
    }
    populate_row(0, 'W');
    populate_row(7, 'B');
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Board[i][j].piece = ' ';
            Board[i][j].colour = 'X';
        }
    }
}

// Helper function for populating the board
void populate_row(int row, char colour)
{
    Board[row][0].piece = 'R';
    Board[row][1].piece = 'N';
    Board[row][2].piece = 'B';
    Board[row][3].piece = 'Q';
    Board[row][4].piece = 'K';
    Board[row][5].piece = 'B';
    Board[row][6].piece = 'N';
    Board[row][7].piece = 'R';
    for (int i = 0; i < 8; i++)
    {
        Board[row][i].colour = colour;
    }
}

// Prints the board to the screen
void print_board(void)
{
    system("clear");
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c",Board[i][j].piece);
            if (j < 7) printf("|");
        }
        printf("\n");
        for (int j = 0; j < 16; j++) if (i > 0) printf("-");
        printf("\n");
    }
    if (current_player == 'W')
    {
        printf("Current player: White\n");
    }
    else
    {
        printf("Current player: Black\n");
    }
    printf("Move: ");
}