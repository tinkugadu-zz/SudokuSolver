#ifndef CELLCLASS_H
#define CELLCLASS_H

#include "utils.h"

class Cell
{
    uint _row;
    uint _col;
public:
    Cell(uint row, uint col): _row(row), _col(col) { } 
    ~Cell(){ }
};
#endif //CELLCLASS_H
