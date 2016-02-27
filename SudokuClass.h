#ifndef SUDOKU_CLASS_H
#define SUDOKU_CLASS_H

#define SUDOKU_SIZE 9
class Sudoku
{
    void getArr(int *tmpArr);
    void setArr(int *tmpArr);
    void setArr(int i, int j, int val);
    bool isCompleted();
    void printPuzzle();
private:
    int _arr[SUDOKU_SIZE][SUDOKU_SIZE];
};
#endif
