#ifndef SUDOKU_CLASS_H
#define SUDOKU_CLASS_H
#include "utils.h"

class Sudoku
{
    Sudoku(Sudoku &cpy) = delete;
    PROBS _possibValues;
    int _size;
    int _sqSize;
    int **_puzzle;
    uint  _cellsFixed;
    bool IsValidRow(int row, bool checkComplete=false);
    bool IsValidColumn(int col, bool checkComplete=false);
    bool IsValidZone(int zone, bool checkComplete=false);
    Row getPossibles(int i, int j);
    void printTmpArr(int *arr, int size, int i, int j);
    void UpdatePossibles(int i, int j);
    Row::iterator find(Row &tmpRow, int val);
    void FixValue(int row, int col, int val);
public:
    Sudoku(int siz);
    ~Sudoku();
    //setters and getters
    bool setRow(uint row, int *arr);
    bool getRow(uint row, int *arr) const;
    bool setVal(uint row, uint col, int val);
    bool getVal(uint row, uint col, int &val) const;
    void printPuzzle();
    void printRow(uint row);
    bool Valid(bool checkComplete=false);
    void FillInitialPossibilities();
    void PrintPossibilities();
    void Solve();
    inline uint GetCellsFixed() { return _cellsFixed; }
};
#endif
