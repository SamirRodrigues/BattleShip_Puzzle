#include "../include/puzzle_generator.h"

void puzzle_generator (int c, int r, int np)
{
    int val = 0;
    int spawner[c][r];

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            spawner[i][j] = val;
            val +=1;
            std::cout << spawner[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}