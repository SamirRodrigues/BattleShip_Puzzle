#ifndef SHIPGENERATOR_H
#define SHIPGENERATOR_H

#include <iostream>
#include <random>
#include <vector>

#define MAX_COL 16
#define MAX_ROW 16


/* SHIP GENERATOR */

namespace ShipG 
{
    void Battleship(int board[MAX_ROW][MAX_COL], int col, int row);
    
    void Crouiser(int board[MAX_ROW][MAX_COL], int col, int row);

    void Destroyer(int board[MAX_ROW][MAX_COL], int col, int row);

    void Submarine(int board[MAX_ROW][MAX_COL], int col, int row);
}

#endif