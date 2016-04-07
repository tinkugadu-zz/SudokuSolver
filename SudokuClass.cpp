#include "SudokuClass.h"
#include <math.h>

Sudoku::Sudoku(int siz) : _size(siz)
{
    _sqSize = (int)sqrt((double)siz);
    _puzzle = (int* *)malloc(_size*sizeof(int *));
    for(int i=0; i<_size; ++i)
    {
	    _puzzle[i] = (int *)calloc((size_t)_size, sizeof(int));
    }
}

Sudoku::~Sudoku()
{
    for(int i=0; i<_size; ++i)
    {
    	free(_puzzle[i]);
    }
    free(_puzzle);
}

bool Sudoku::setRow(uint row, int *arr)
{
    if(!arr)
    {
	    return false;
    }    
    memcpy(_puzzle[row], arr, _size*sizeof(int));
    return true;
}

bool Sudoku::getRow(uint row, int *arr) const
{
    if(!arr) return false;
    memcpy(arr, _puzzle[row], _size*sizeof(int));
    return true;
}

bool Sudoku::setVal(uint row, uint col, int val)
{
    if((row > 9) || (col > 9)) return false;
    _puzzle[row][col] = val;
    return true;
}

bool Sudoku::getVal(uint row, uint col, int &val) const
{
    if((row > 9) || (col > 9)) return false;
    val = _puzzle[row][col];
    return true;
}

void Sudoku::printPuzzle()
{
    for(uint i=0; i<_size; ++i)
    {
	printRow(i);
    }
}

void Sudoku::printRow(uint row)
{
    for(uint i=0; i<_size; ++i)
    {
	cout<<_puzzle[row][i]<<"\t";
    }
    cout<<endl;
}

bool Sudoku::Valid(bool checkComplete)
{
    //check row, column and zone sanity
    for(int i=0; i<_size; ++i)
    {
        if(!IsValidRow(i, checkComplete) || 
            !IsValidColumn(i, checkComplete) ||
             !IsValidZone(i, checkComplete))
        {
            cout<<"invalid detected at index: "<<(i+1)<<endl;
            return false;
        }
    }
    return true;
}

bool Sudoku::IsValidRow(int row, bool checkComplete)
{
    int tmpArr[] = {0,0,0,0,0,0,0,0,0};
    for(int i=0; i<_size; ++i)
    {
        auto ind = _puzzle[row][i];
        if(ind == 0)
        {
            continue;
        }
        else if(checkComplete)
        {
            return false;
        }
        else
        {
            --ind;
        }
        if(tmpArr[ind] != 0)    
        {
            cout<<"invalid row value: ("<<(row+1)<<" , "<<(i+1)<<")"<<endl;
            return false;
        }
        else
        {
            ++tmpArr[ind];
        }
    }
    return true;
}

bool Sudoku::IsValidColumn(int col, bool checkComplete)
{
    int tmpArr[] = {0,0,0,0,0,0,0,0,0};
    for(int i=0; i<_size; ++i)
    {
        auto ind = _puzzle[i][col];
        if(ind == 0)
        {
            continue;
        }
        else if(checkComplete)
        {
            return false;
        }
        else
        {
            --ind;
        }        
        if(tmpArr[ind] != 0)
        {
            cout<<"invalid row value: ("<<(i+1)<<" , "<<(col+1)<<")"<<endl;
            return false;
        }
        else
        {
            ++tmpArr[ind];
        }
    }
    return true;
}

bool Sudoku::IsValidZone(int zone, bool checkComplete)
{
    return true;
}

