#include "../include/board_generator.h"

/* BOARD GENERATOR */

namespace BoardG
{
    void Water(int board[MAX_COL][MAX_ROW], int row, int col) //Reset de board. Put 0 in all Quads
    {		
		for(int i(0); i < row; i++)
        {
			for(int j(0); j < col; j++)
            {
				board[i][j] = 0;
			}
		}
	}

    void ReflectBoardVertical(int board[MAX_COL][MAX_ROW], int row, int col)
    {
		
		for(int i(0); i < row; i++)
        {
			for(int j(0); j < col/2; j++)
            {
				int temp=board[i][j];
				board[i][j]=board[i][row-1-j];
				board[i][row-1-j]=temp;
			}
		}
	}

    void ReflectBoardHorizontal(int board[MAX_COL][MAX_ROW], int row, int col){
		for(int i(0); i < row/2; i++)
        {
			for(int j(0); j < col; j++)
            {
				int temp=board[i][j];
				board[i][j]=board[row-1-i][j];
				board[row-1-i][j]=temp;
			}
		}
	}

    void Print(int board[MAX_COL][MAX_ROW], int row,int col){
	
		std::cout << std::endl << std::endl << std::endl;

		for (int i(0); i < row; i++)
        {
			for(int j(0); j < col; j++)
            {
				if(board[i][j] == 1 /*Ele = 1*/ && board[i+1][j] == 1 /*Inferior = 1*/ && board[i-1][j] != 1 /*Superior != 1*/) // Se o elemento for barco e ponta vertical superir
                {
					std::cout<<"▲ ";
				}
                else if(board[i][j] == 1 /*Ele = 1*/ && board[i+1][j] != 1 /*Inferior != 1*/ && board[i-1][j] == 1 /*Superior = 1*/) // Se o elemento for barco e ponta vertical inferior
                {
					std::cout<<"▼ ";
				}
                else if((board[i][j] == 1 /*Ele = 1*/ && board[i+1][j] == 1 /*Inferior = 1*/ && board[i-1][j] == 1 /*Superior = 1*/) // Se as laterais tiverem elemento barco
					 || (board[i][j] == 1 /*Ele = 1*/ && board[i][j+1] == 1 /*Direita = 1*/ && board[i][j-1] == 1 /*Esquerda = 1*/)) // Ou Se as partes superior e inferior tiverem elemento barco
                {
					std::cout<<"◼ ";
				}
                else if(board[i][j] == 1 /*Ele = 1*/ && board[i][j+1] == 1 /*Direita = 1*/ && board[i][j-1] != 1 /*Esquerda != 1*/) // Se o elemento for barco e ponta horizontal esquerda
                {
					std::cout<<"◀︎ ";
				}
                else if(board[i][j] == 1 /*Ele = 1*/ && board[i][j+1] != 1 /*Direita != 1*/ && board[i][j-1] == 1 /*Esquerda = 1*/) // Se o elemento for barco e ponta horizontal direita
                {
					std::cout<<"▶︎ ";
				}
                else if (board[i][j] == 2) // Se o elemento for um submarino
                {
					std::cout<<"● ";
				}
                else if(board[i][j] == 0) // Se o elemento for água
                {
					std::cout<<". ";
				}
			}
			std::cout << std::endl;
		}
	}
}