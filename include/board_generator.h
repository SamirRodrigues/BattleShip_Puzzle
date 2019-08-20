#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <iostream>
#include <random>

#define MAX_COL 16
#define MAX_ROW 16

/* BOARD GENERATOR */

namespace BoardG
{
	void Water(int board[MAX_COL][MAX_ROW], int row, int col);

    void ReflectBoardVertical(int board[MAX_COL][MAX_ROW], int row, int col);

    void ReflectBoardHorizontal(int board[MAX_COL][MAX_ROW], int row, int col);

    void Print(int board[MAX_COL][MAX_ROW], int row,int col);
}

#endif