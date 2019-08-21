#ifndef PUZZLEGENERATOR_H
#define PUZZLEGENERATOR_H

#include <iostream>

#define MAX_COL 16
#define MAX_ROW 16

namespace PuzzleG
{
    void puzzle_generator (int c, int r, int np, int board[MAX_COL][MAX_ROW]);

    void spawn_board(int board[MAX_COL][MAX_ROW], int c, int r);
    
    void ReflectBoard(int board[MAX_COL][MAX_ROW], int c, int r);
}

#endif