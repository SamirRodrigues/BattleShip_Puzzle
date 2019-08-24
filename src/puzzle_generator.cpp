#include "../include/puzzle_generator.h"
#include "../include/ship_generator.h"
#include "../include/board_generator.h"

namespace PuzzleG
{
    void spawn_board(std::vector<std::vector<int>> &board, int c, int r)
    {
        BoardG::Water(board,c,r); // Put water in all board
        ShipG::Battleship(board,c,r); // Spawn Battleship
        ShipG::Crouiser(board,c,r); // Spawn Crouiser
        ShipG::Destroyer(board,c,r);   // Spawn Destroyer
        ShipG::Submarine(board,c,r); // Spawn Submarine
        BoardG::Print(board,c,r);
    }

    void ReflectBoard(std::vector<std::vector<int>> &board, int c, int r)
    {
        BoardG::ReflectBoardVertical(board,c,r);
        BoardG::Print(board,c,r);
        BoardG::ReflectBoardHorizontal(board,c,r);
        BoardG::Print(board,c,r);
        BoardG::ReflectBoardVertical(board,c,r);
        BoardG::Print(board,c,r);
    }

    void puzzle_generator (int c, int r, int np)
    {
        std::vector<std::vector<int>> board;
        std::vector<int> single_row(c+2);
        board.resize(r+2, single_row);

        int aux(0); // O auxiliar serve para informar quantos puzzles ja foram feitos

        while(aux < np)
        {
            std::cout << aux+1 << std::endl;
            PuzzleG::spawn_board(board,r,c);
            aux++;
        }
        

        /*
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
			    PuzzleG::spawn_board(board,r,c); // Gera um puzzle base
			    PuzzleG::ReflectBoard(board,r,c); // Cria 3 novos puzzles com base no anterior
			    aux++;
		    }

		    if((Dif_num % 4) != 0) // Se a quantidade de puzzles pedidos não for divisível por 4, será necessário gerar a quantidade de puzzles que faltar
            {                      
                int rest = np - (Dif_num * 4); // Pego o resto da divisão 

			    while(rest > 0) // Gera a quatidade igual ao resto da divisão acima
                {
				    PuzzleG::spawn_board(board,r,c); 
				    rest --;
			    }
		    }	    
        }
        */
    }
}
