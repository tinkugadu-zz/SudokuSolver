#include "SudokuClass.h"

void Sudoku::printPuzzle()
{
    for(auto ii = 0; ii<SUDOKU_SIZE; ++ii)
    {
	for(auto jj=0; jj<SUDOKU_SIZE; ++jj)
	{
	    cout<<_arr[ii][jj]<<"\t";
	}
	cout<<endl;
    }
}

bool Sudoku::isCompleted()
{
    return true;
}

void Sudoku::getArr(int **tmpArr)
{
    if(!tmpArr)
    {
	throw "Sudoku::tmpArr is NULL";
    }
    for(auto ii=0; ii<SUDOKU_SIZE; ++ii)
    {
	for(auto jj=0; jj<SUDOKU_SIZE; ++jj)
	{
	    tmpArr[ii][jj] = _arr[ii][jj];
	}
    }
}

void Sudoku::setArr(int **tmpArr)
{
    if(!tmpArr)
    {
	throw "Sudoku::tmpArr is NULL";
    }
    for(auto ii=0; ii<SUDOKU_SIZE; ++ii)
    {
	for(auto jj=0; jj<SUDOKU_SIZE; ++jj)
	{
	    _arr[ii][jj] = tmpArr[ii][jj];
	}
    }
}

void Sudoku::setArr(int i, int j, int val)
{
    _arr[i][j] = val;
}
