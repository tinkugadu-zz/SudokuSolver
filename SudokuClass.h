#ifndef SUDOKU_CLASS_H
#define SUDOKU_CLASS_H
#include "utils.h"
#include <map>

typedef std::vector<int> Row;
typedef std::vector<Row> Puzzle;
typedef std::map<int, Row> PROBS;
typedef unsigned int uint;
class Sudoku
{
    Sudoku(Sudoku &cpy) = delete;
    PROBS _possibValues;
    int _size;
    int _sqSize;
    int **_puzzle;
    bool IsValidRow(int row, bool checkComplete=false);
    bool IsValidColumn(int col, bool checkComplete=false);
    bool IsValidZone(int zone, bool checkComplete=false);
    Row getPossibles(int i, int j);
    void printTmpArr(int *arr, int size, int i, int j);
    void UpdatePossibles(int i, int j);
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
};
#endif
