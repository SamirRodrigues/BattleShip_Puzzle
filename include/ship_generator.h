#ifndef SHIPGENERATOR_H
#define SHIPGENERATOR_H

#include <iostream>
#include <random>


/* SHIP GENERATOR */

namespace ShipG 
{
    void Battleship(int np/*board[MAX_COL][MAX_ROW]*/, int col, int row);
    
    void Crouiser(int np/*board[MAX_COL][MAX_ROW]*/, int col, int row);

    void Destroyer(int np/*board[MAX_COL][MAX_ROW]*/, int col, int row);

    void Submariner(int np/*board[MAX_COL][MAX_ROW]*/, int col, int row);
}

#endif