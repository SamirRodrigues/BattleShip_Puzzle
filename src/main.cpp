// Example program
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "../include/puzzle_generator.h"
#include "../include/ship_generator.h"
#include "../include/board_generator.h"

#define MAX_COL 16
#define MAX_ROW 16
#define MAX_NPUZZLE 100
#define MIN_COL 7
#define MIN_ROW 7
#define MIN_NPUZZLE 1
// valores padrao
#define DEF_COL 10
#define DEF_ROW 10
#define DEF_NPUZZLE MIN_NPUZZLE

void message( std::string msg="" )
{
    if ( msg != "" )
        std::cout << "   bpg ERROR: \"" << msg << "\"\n\n";
        
        std::cout <<
"   Usage: [<options>] <number_of_puzzles>\n" <<
"   Program options are:\n" <<
"        --rows <num>	Specify the number of rows for the matrix, with `<num>` in the range [7, 16]. The default value is 10.\n" <<
"        --cols <num>	Specify the number of columns for the matrix, with `<num>` in the range [7,16]. The default value is 10.\n" <<
"   Requested input is:\n" <<
"       number_of_puzzles	The number of puzzles to be generated, in the range [1,100].\n";

    exit( 0 );
}
/// Converte uma string para minusculas
std::string str_tolower( std::string str )
{
    for ( char & c : str )
        c = std::tolower( c );
        
        return str;
}

int main( int argc, char *argv[] )
{
    // Default values.
    int r{DEF_ROW}, c{DEF_COL}, np{DEF_NPUZZLE};
    int board [MAX_COL][MAX_ROW];
    
    
    if ( argc == 1 )
    {
        message();
    }        
        
    if ( argc > 6 )
    {
        message("Too many argumnents!");
        
    }
    
    //Processar os argumentos

    for ( auto i{1} ; i < argc ; ++i )
    {
        // convert the current argument to lower case.
        auto s_arg = str_tolower( argv[i] );
        
        if ( s_arg == "-r" or s_arg == "--row" or s_arg == "-row" or s_arg == "--r" or s_arg == "--rows" or s_arg == "-rows" )
        {
            int nrows{0};
            if ( (i+1) == argc )
                message("Missing number of rows!");
                
            try {
                nrows = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for row!");
            }
            if ( nrows < MIN_ROW or nrows > MAX_ROW )
                message("Number of rows out of the acceptable range!");
                
            r = nrows;
        }
        else if ( s_arg == "-c" or s_arg == "--col" or s_arg == "-col" or s_arg == "--c" or s_arg == "-cols" or s_arg == "--cols" )
        {
            int ncols{0};
            try {
                ncols = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for cols!");                
            }
            if ( ncols < MIN_ROW or ncols > MAX_ROW )
                message("Number of cols out of the acceptable range!");
                
            c = ncols;
        }
        else // # of puzzles
        {
            int npuzzles{1};
            
            try {
                npuzzles = std::stoi( argv[i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for number of puzzles!");                
            }
            if ( npuzzles < MIN_NPUZZLE or npuzzles > MAX_NPUZZLE )
                message("The requested number of puzzles is out of the acceptable range!");
                
            np = npuzzles;
        }
        
    }
    
    std::cout << ">>> cols = " << c << ", rows = "  << r << ", npuzzles = " << np << std::endl;

    PuzzleG::puzzle_generator(c,r,np);

    return EXIT_SUCCESS;
    
}