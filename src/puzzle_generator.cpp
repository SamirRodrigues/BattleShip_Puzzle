#include "../include/puzzle_generator.h"
#include "../include/ship_generator.h"
#include "../include/board_generator.h"

namespace PuzzleG
{
    void spawn_board(int board[MAX_COL][MAX_ROW], int c, int r)
    {
        BoardG::Water(board,c,r); // Put water in all board
        ShipG::Battleship(board,c,r); // Spawn Battleship
        ShipG::Crouiser(board,c,r); // Spawn Crouiser
        ShipG::Destroyer(board,c,r);   // Spawn Destroyer
        ShipG::Submarine(board,c,r); // Spawn Submarine
        BoardG::Print(board,c,r);
    }

    void ReflectBoard(int board[MAX_COL][MAX_ROW], int c, int r)
    {
        BoardG::ReflectBoardVertical(board,c,r);
        BoardG::Print(board,c,r);
        BoardG::ReflectBoardHorizontal(board,c,r);
        BoardG::Print(board,c,r);
        BoardG::ReflectBoardVertical(board,c,r);
        BoardG::Print(board,c,r);
    }

    void puzzle_generator (int c, int r, int np, int board[MAX_COL][MAX_ROW])
    {
        int aux(0);

        if(np < 4)
        {
            while(aux < np)
            {
                spawn_board(board,r,c);
                aux++;
            }
        }
        else
        {
            int Dif_num = np/4;//Divide the number of boards by four, as they need to generate only one-quarter of the boards ordered
            

		    while(aux < Dif_num)
            {
			    spawn_board(board,r,c);
			    ReflectBoard(board,r,c);
			    aux++;
		    }

		    //if the number requested by the user is not divisible by 4, the program creates more boards to complete
		    if((Dif_num%4) != 0)
            {
                int tam = np - (Dif_num*4);

			    while(tam > 0)
                {
				    spawn_board(board,r,c);
				    tam --;
			    }
		    }	    
        }

        
    }
}
