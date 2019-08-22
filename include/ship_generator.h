#ifndef SHIPGENERATOR_H
#define SHIPGENERATOR_H

#include <iostream>
#include <random>
#include <vector>


/* SHIP GENERATOR */

namespace ShipG 
{
    void Battleship(std::vector<std::vector<int>> &board, int col, int row);
    
    void Crouiser(std::vector<std::vector<int>> &board, int col, int row);

    void Destroyer(std::vector<std::vector<int>> &board, int col, int row);

    void Submarine(std::vector<std::vector<int>> &board, int col, int row);
}

#endif