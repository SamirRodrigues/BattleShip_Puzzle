#include <iostream>

void puzzle_generator (int c, int r, int np);

int main (void)
{
int c, r, np;
c = 16;
r = 16;
np = 100;

puzzle_generator(c,r,np);

    return 0;
}


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