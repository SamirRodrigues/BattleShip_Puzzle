#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include <iostream>
#include <random>
#include <vector>

/* BOARD GENERATOR */

namespace BoardG
{
	void Water(std::vector<std::vector<int>> &board, int row, int col);

    void ReflectBoardVertical(std::vector<std::vector<int>> &board, int row, int col);

    void ReflectBoardHorizontal(std::vector<std::vector<int>> &board, int row, int col);

    void Print(std::vector<std::vector<int>> &board, int row,int col);
}

#endif