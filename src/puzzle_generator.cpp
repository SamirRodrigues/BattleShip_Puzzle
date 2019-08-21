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
        int aux(0); // O auxiliar serve para informar quantos puzzles ja foram feitos

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
            int Dif_num = np/4; //Divide o número de puzzles (np) por 4, pois a função de ReflectBoard consegue gerar 3 novos puzzles com base no primeiro (3+1=4)
            

		    while(aux < Dif_num)
            {
			    spawn_board(board,r,c); // Gera um puzzle base
			    ReflectBoard(board,r,c); // Cria 3 novos puzzles com base no anterior
			    aux++;
		    }

		    if((Dif_num % 4) != 0) // Se a quantidade de puzzles pedidos não for divisível por 4, será necessário gerar a quantidade de puzzles que faltar
            {                      
                int rest = np - (Dif_num * 4); // Pego o resto da divisão 

			    while(rest > 0)
                {
				    spawn_board(board,r,c); // Gera os remanecentes
				    rest --;
			    }
		    }	    
        }
    }
}