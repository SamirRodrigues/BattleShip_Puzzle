#include "../include/board_generator.h"

/* BOARD GENERATOR */

namespace BoardG
{
    void Water(std::vector<std::vector<int>> &board, int row, int col) /* Preenche a matriz com números 0,
																 		  que foi o elemento escolhido para representar a água nesse puzzle.*/
    {		
		for(int i(0); i < row; i++)
        {
			for(int j(0); j < col; j++)
            {
				board[i][j] = 0;
			}
		}
	}

    void ReflectBoardVertical(std::vector<std::vector<int>> &board, int row, int col) /*Reflete a matriz de maneira vertical*/
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

    void ReflectBoardHorizontal(std::vector<std::vector<int>> &board, int row, int col){ /*Reflete a matriz de maneira horizontal*/
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

	void testPrint(std::vector<std::vector<int>> &board, int row,int col)
	{
		for (int i(1); i <= row; i++)
        {
			for(int j(1); j <= col; j++)
            {
				std::cout << board[i][j];
			}
                
			std::cout<<std::endl;
		}
	}
    void Print(std::vector<std::vector<int>> &board, int row,int col)/*Responsável por mostrar o resultado gerado*/
	{ 	
		for (int i(1); i <= row; i++)
        {
			for(int j(1); j <= col; j++)
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
                else if (board[i][j] == 3) // Se o elemento for um submarino
                {
					std::cout<<"● ";
				}
                else if(board[i][j] == 0 || board[i][j] == 2) // Se o elemento for água
                {
					std::cout<<". ";
				}
				/*
				else if(board[i][j] == 2) // Se o elemento for sombra
                {
					std::cout<<"* ";
				}
				*/
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}
