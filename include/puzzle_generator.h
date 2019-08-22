#ifndef PUZZLEGENERATOR_H
#define PUZZLEGENERATOR_H

#include <iostream>
#include <vector>


namespace PuzzleG
{
    void puzzle_generator (int c, int r, int np);

    void spawn_board(std::vector<std::vector<int>> &board, int c, int r);
    
    void ReflectBoard(std::vector<std::vector<int>> &board, int c, int r);
}

#endif