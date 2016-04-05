#ifndef SUDOKU_CLASS_H
#define SUDOKU_CLASS_H

typedef std::vector<int> Row;
typedef std::vector<Row> Puzzle;
class Sudoku
{
    Sudoku();
    ~Sudoku();
    Sudoku(Sudoku &cpy) = delete;
public:
    Puzzle _puzzle;
};
#endif
