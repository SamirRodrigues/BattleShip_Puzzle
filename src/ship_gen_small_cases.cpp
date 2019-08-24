#include "../include/ship_generator.h"
#include "../include/board_generator.h"

/* SHIP GENERATOR */

namespace ShipG
{
    void Battleship(std::vector<std::vector<int>> &board, int col, int row)
    {
        std::random_device rand;   // Função geradora de valores randomicos
		std::mt19937 seed(rand()); // Função responsável por alterar a seed dos valores randomicos, para que sejam sempre diferentes

		std::uniform_int_distribution <> picker1(0, col); // Função responsável por sortear um valor entre 0 e o número de colunas 
                                                          // Essa função irá escolher em qual coluna a "cabeça" do Battleship irá spawnar
		
		std::uniform_int_distribution <> picker2(0, row - 3); // Função responsável por definir em qual linha a "cabeça" do Battleship irá spawnar por meio de sorteio
                                                              /* O valor de row é decrescido de 3 pois caso a cabeça do battleship seja um valor maior que row-3,
                                                                 seu corpo irá sair do board, já que ele ocupa 4 espaços */
                                                              /* Dessa forma, o barco será colocado na posição vertical, já que cada parte do corpo subsequente irá
                                                                 spawnar na próxima linha abaixo */
        
        std::uniform_int_distribution <> picker3(0, col - 3); // Acrescento mais um picker para escolher uma coordenada no caso de colocar o barco na Horizontal.

        std::uniform_int_distribution <> V_or_H(0,1); // Define se o barco será spawnado na Vertical(0) ou na Horizontal(1).
		
        
 
        int guidance = V_or_H(seed); // Variável que recebe a orientação dos barcos (Vertical ou Horizontal).
     
        if(guidance == 0) // Orientação Vertical
        {
            // Variáveis responsáveis por definir a coordenada em que a "cabeça" do Battleship irá spawnar, baseado nos valores sorteados pelos pickers.
		    if(row <=9 || col <=9)
            {
                auto posX = 0;
		        auto posY = picker1(seed);
                for(int i(0); i < 4; i++)  // Spawna o Battleship no board na Vertical
                {
                    board[posX+i][posY] = 1; // Coloca cada peça do barco em uma linha inferior a anterior, com origem na coordenada criada anteriormente.
                                            // O número 1 no board significa que aquela casa está ocupada por parte de uma embarcação.
                }
            }
             else 
            {
                auto posX = picker2(seed);
		        auto posY = picker1(seed);
                for(int i(0); i < 4; i++)  // Spawna o Battleship no board na Vertical
                {
                    board[posX+i][posY] = 1; 
                }
            }
            
        } 
        else // Orientação Horizontal
        {
            if(row <=9 || col <=9)
            {
                auto posX = 0;
                auto posY = picker3(seed);

                for(int i(0); i < 4; i++)  // Spawna o Battleship no board na Horizontal
                {
                    board[posX][posY+i] = 1; // Coloca cada peça do barco em uma coluna a direita, com origem na coordenada criada anteriormente.
                }
            }
            else
            {
                auto posX = picker1(seed);
                auto posY = picker3(seed);

                for(int i(0); i < 4; i++)
                {
                    board[posX][posY+i] = 1;
                }
            }		    
        }
        

		BoardG::Print(board,col,row);

        /*Perceba que não existe uma função para verificar se existe barcos ao redor de onde este será spawnado, já que ele será o primeiro a ser colocado no board*/

        std::cout << "BATTLESHIP CREATED" << std::endl;
    }   

    void Crouiser(std::vector<std::vector<int>> &board, int col, int row)
    {
        std::random_device rand;
		std::mt19937 seed(rand());
		
		std::uniform_int_distribution <> picker1(0, col);

		std::uniform_int_distribution <> picker2(0, row - 2);

		std::uniform_int_distribution <> picker3(0, col - 2); 

        std::uniform_int_distribution <> V_or_H(0,1);
		
        
        int checker(0); /* Variável auxiliar que irá chegar se os arredores de onde o barco irá spawnar possui um barco. 
                         Perceba que está variável irá percorrer os locais onde as "sombras" do barco estarão.*/
		
		// Coordenadas com valores base
		int posX(0);
		int posY(0);
        int guidance(0);

        int qtdBoat(2); // Quantidade de barcos que serão spawnados

        for (size_t i = 0; i < qtdBoat; i++)
        {   
            guidance = V_or_H(seed);
            
            if(guidance == 0) 
            {   
                do  //Verificador de embarcações nos arredores da coordenada selecionada	
                {   //Este verificador analiza os barcos que serão colocados na Vertical                  

                    posX = picker2(seed);
                    posY = picker1(seed);

                    checker = 0;    // Reseta o Verificador		
                    
                    for(int i(posX-1); i <= (posX+3); i++)
                    {
                        for (int j (posY-1); j <= (posY+1); j++)
                        {
                            if(board[i][j] == 1){
                                checker = board[i][j];
                                break;
                                /*O elemento 0 na matriz representa a água, se o verificador achar algum elemento que não seja água nos arredores da embarcação,
                                    para a verificação e procura outra coordenada*/
                            }
                        }
                    }
                } while(checker != 0); // Enquanto não for água;
            

                //Spawna um Cruiser na posição Vertical.
                for(int i(0); i < 3; i++)
                {
                    board[posX+i][posY] = 1;
                }

            } 
            else
            {
                do
                {  //Este verificador analiza os barcos que serão colocados na Horizontal

                    posX = picker1(seed);
                    posY = picker3(seed);

                    checker = 0;

                    for(int i(posX-1); i <= (posX+1); i++)
                    {
                        for (int j (posY-1); j <= (posY+3); j++)
                        {
                            if(board[i][j] == 1){
                                checker = board[i][j];
                                break;
                            }
                        }
                    }
                } while(checker != 0);

                //Spawna um Cruiser na posição Horizontal.
                for(int i(0); i < 3; i++)
                {
                    board[posX][posY+i] = 1;
                }                
            }            
        }

        std::cout << "CROUISER CREATED" << std::endl;
    }

    void Destroyer(std::vector<std::vector<int>> &board, int col, int row)
    {
        std::random_device rand;
		std::mt19937 seed(rand());
		
		std::uniform_int_distribution <> picker1(0, col);

		std::uniform_int_distribution <> picker2(0, row - 1);

		std::uniform_int_distribution <> picker3(0, col - 1); 

        std::uniform_int_distribution <> V_or_H(0,1);
		
        
        int checker(0);
		int posX(0);
		int posY(0);
        int guidance(0);

        int qtdBoat(3); 

        for (size_t i = 0; i < qtdBoat; i++)
        {   
            guidance = V_or_H(seed);
            
            if(guidance == 0) 
            {   
                do  
                {                 

                    posX = picker2(seed);
                    posY = picker1(seed);

                    checker = 0;    
                    
                    for(int i(posX-1); i <= (posX+2); i++)
                    {
                        for (int j (posY-1); j <= (posY+1); j++)
                        {
                            if(board[i][j] == 1){
                                checker = board[i][j];
                                break;
                            }
                        }
                    }
                } while(checker != 0);
            
                for(int i(0) ; i < 2; i++)
                {
                    board[posX+i][posY] = 1;
                }

            } 
            else
            {
                do
                {  
                    posX = picker1(seed);
                    posY = picker3(seed);

                    checker = 0;

                    for(int i(posX-1); i <= (posX+1); i++)
                    {
                        for (int j (posY-1); j <= (posY+2); j++)
                        {
                            if(board[i][j] == 1){
                                checker = board[i][j];
                                break;
                            }
                        }
                    }
                } while(checker != 0);
               
                for(int i(0); i < 2; i++)
                {
                    board[posX][posY+i] = 1;
                }                
            }            
        }
        std::cout << "DESTROYER CREATED" << std::endl;
    }

    void Submarine(std::vector<std::vector<int>> &board, int col, int row)
    {
        std::random_device rand;
		std::mt19937 seed(rand());		
		std::uniform_int_distribution <> picker1(0, col);
		std::uniform_int_distribution <> picker2(0, row);
		std::uniform_int_distribution <> picker3(0, col); 
        std::uniform_int_distribution <> V_or_H(0,1);
		
        
        int checker(0);
		int posX(0);
		int posY(0);
        int qtdBoat(4); 

        for (size_t i = 0; i < qtdBoat; i++)
        { 
            do  
            { 
                posX = picker2(seed);
                posY = picker1(seed);

                checker = 0;    
                
                for(int i(posX-1); i <= (posX+1); i++)
                {
                    for (int j (posY-1); j <= (posY+1); j++)
                    {
                        if(board[i][j] == 1 || board[i][j] == 3){
                            checker = board[i][j];
                            break;
                        }
                    }
                }
            } while(checker != 0);        
            
            board[posX][posY] = 3; // Usamos uma nomenclatura diferente para o Submarine para facilitar o print com os símbolos.

            /*Perceba que não usamos a orientação no caso do Submarine, já que ele ocupa somente uma casa no board*/                         
        }            
        
        std::cout << "SUBMARINER CREATED" << std::endl;
    }
}