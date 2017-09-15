/*
 *  sudoku.h
 *  Sudoku
 *  Created by Prof. Ramavarapu Sreenivas 
 *  Inspired by: http://web.eecs.utk.edu/courses/spring2012/cs140/Notes/Sudoku/index.html
*/

#ifndef sudoku
#define sudoku

#include <vector>
#include <fstream>
using std::vector;
using namespace std;
class Sudoku

{   //int Row;
    //int Col;
	// Private
	int puzzle[9][9];
    
    int k;
    

	
	// Private member function that checks if the named row is valid
	bool row_valid(int row,int num)
    {   int i;
        for (i=0;i<9;i++)
        {
            if (puzzle[row][i]==num)
            {
                return true;
            }
        }
        return false;

		// write code that checks if "row" is valid
    }
	
	// Private member function that checks if the named column is valid
	bool col_valid(int col,int num)
    {   int i;
        for (i=0;i<9;i++)
        {
            if (puzzle[i][col]==num)
            {
                return true;
            }
        }
        return false;		// check validity of "col"
    }
	
	// Private member function that checks if the named 3x3 block is valid
	bool block_valid(int row, int col,int num)
    {   int i,j,k,l,m,n;
        
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (row%3==i&&col%3==j)
                {
                    for(k=i+1;k<i+3;k++)
                    {
                        for (l=j+1;l<j+3;l++)
                        {
                            m=(row+k)%3+row/3*3;
                            n=(col+l)%3+col/3*3;
                            if (num==puzzle[m][n])
                            {
                                return true;
                            }
                        }
                    }
                    
                }
            }
        }
        

                        /*if(row%3==0&&col%3==0)
            {
                for (i=1;i<3;i++)
                {
                    for(j=1;j<3;j++)
                    {
                        if (0==puzzle[row][col]-puzzle[row+i][col+j])
                        {
                            return false;
                        }
                    }
                }
            }
                        */

        return false;
		// check 3 x 3 block validity 
	}
	
public:
   
	// Public member function that reads the incomplete puzzle
	// we are not doing any checks on the input puzzle -- that is,
	// we are assuming they are indeed valid
	void read_puzzle(int argc, char * const argv[])
	{
        
        int value_just_read_from_file;
        vector <int> P; //vector of numbers
        
        ifstream input_file("input4"); // The input file name is "Data.txt"
        // It contains the numbers P_1 P_2 ... P_M
        
        if (input_file.is_open()) // If "Data.txt" exists in the local directory
        {
            while(input_file >> value_just_read_from_file) // As long as your are not at the "end-of-file"
            {
                P.push_back(value_just_read_from_file);
            }
        }
        int k=0;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                puzzle[i][j]=P[k];
                k++;
            }
        }
        
       		// write code that reads the input puzzle using the
		// guidelines of figure 23 of the bootcamp material
	}
	
	// Public member function that prints the puzzle when called
	void print_puzzle()
	{
		std::cout << std::endl << "Board Position" << std::endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				// check if we have a legitimate integer between 1 and 9
				if ((puzzle[i][j] >= 1) && (puzzle[i][j] <= 9))
				{
					// printing initial value of the puzzle with some formatting
					std::cout << puzzle[i][j] << " ";
				}
				else {
					// printing initial value of the puzzle with some formatting
					std::cout << "X ";
				}
			}
			std::cout << std::endl;
		}
	}
    
    
    bool Check_puzzle(int &row,int &col)
    {
        for (row = 0; row < 9; row++)
        {
            for (col = 0; col < 9; col++)
            {
                if (puzzle[row][col]==0)
                {
                   return false;
                }
            }
        }
        return true;
       
    }
	// Public member function that (recursively) implements the brute-force 
	// search for possible solutions to the incomplete Sudoku puzzle
	bool Solve(int row, int col)
    {
        {
            if (Check_puzzle(row,col))
            {
                return true;
            }
            for (int k = 1; k <= 9; k++)
            {

                if (!row_valid(row,k)&&!col_valid(col,k)&&!block_valid(row,col,k)==true)
                {
                    puzzle[row][col] = k;
                    

                    if (Solve(row, col))
                    {
                        return true;
                    }
                    puzzle[row][col] = 0;
                }
            }
            return false;
        }
    }
};
        
        
        
        /*for (int i=0; i<9;i++)
            
        {
            if (0==puzzle[i][col])
            {
                for (int k=1;k<10;k++)
                {
                    puzzle[i][col]=k;
                    if (row_valid(i)&&col_valid(col)&&block_valid(i,col)==true)
                    {
                        Solve(i,col+1);
                    }
                    else
                    {
                        puzzle[i][col]=0;
                    }
                    
                }
            }
        }
        
		// this part of the code identifies the row and col number of the
		// first incomplete (i.e. 0) entry in the puzzle.  If the puzzle has
		// no zeros, the variable row will be 9 => the puzzle is done, as 
		// each entry is row-, col- and block-valid...
		
		// use the pseudo code of figure 3 of the description
    }*/


#endif
