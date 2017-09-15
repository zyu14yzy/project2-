// Soduku Solver using Brute-Force Search implemted using 
// recursion.
// Written for IE523: Financial Computation by Prof. Sreenivas
// and GE523: Discrete Event Systems
//
#include <iostream>
#include "prog2_hint.h"

int main (int argc, char * const argv[]) 
{
	Sudoku x;
	x.read_puzzle(argc, argv);
	x.print_puzzle();
	x.Solve(0,0);
    //x.alternate_Solve(0, 0);
	x.print_puzzle();
	
    return 0;
}
