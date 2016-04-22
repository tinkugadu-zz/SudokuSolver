#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;
typedef std::vector<int> Row;
typedef std::map<int, Row> PROBS;
typedef unsigned int uint;

void InsertOrder(Row &tmpRow, int val);
Row::iterator Find(Row &tmpRow, int val);
void printPossibles(PROBS &possibles);
void printVector(Row &tmpRow);

#endif //UTILS_H
