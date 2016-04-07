#ifndef SUDOKU_CLASS_H
#define SUDOKU_CLASS_H

#include <map>

typedef std::vector<int> Row;
typedef std::vector<Row> Puzzle;
typedef std::map<int, Row> PROBS;

class Sudoku
{
    Sudoku(Sudoku &cpy) = delete;
    PROBS _possibValues;
    int **_puzzle;
public:
    Sudoku(int siz, int ssiz);
    ~Sudoku();
    //setters and getters
    bool setRow(int row, int *arr);
    bool getRow(int row, int *arr) const;
    bool setVal(int row, int col, int &val);
    bool getVal(int row, int col, int &val) const;
};
#endif
