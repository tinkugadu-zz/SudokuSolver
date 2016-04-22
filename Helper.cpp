#include "utils.h"

void InsertOrder(Row &tmpRow, int val)
{
    Row::iterator it = tmpRow.begin();
    bool inserted = false;
    while(it != tmpRow.end())
    {
        if(val >= *it)
        {
            ++it;
            continue;
        }
        else
        {
            tmpRow.insert(it, val);
            inserted = true;
            break;
        }
    }
    if(!inserted)
    {
        tmpRow.push_back(val);
    }
}

Row::iterator Find(Row &tmpRow, int val)
{
    int siz = tmpRow.size() - 1;
    int left_ind = 0;
    int right_ind = siz;
    int ind = 0;
    bool found = false;
    do
    {
        ind = left_ind + (right_ind - left_ind)/2;
        if(tmpRow[ind] == val) 
        {
            found = true;
            break;
        }
        if(val > tmpRow[ind])
        {
        //shift right to the region
            left_ind = ind;
        }
        if(val < tmpRow[ind])
        {
	 //shift left to region
            right_ind = ind;
        }
    }
    while(right_ind - left_ind > 1);
    if(tmpRow[left_ind] == val)
    {
        ind = left_ind;
        found = true;
    }
    if(tmpRow[right_ind] == val)
    {
        ind = right_ind;
        found = true;
    }
    
    if(found)
    {
        cout<<"index found at: "<<ind<<endl;
        return tmpRow.begin() + ind;
    }
    else return tmpRow.end();
}

void printPossibles(PROBS &possibles)
{
    for(auto it = possibles.begin(); it != possibles.end();
            ++it)
    {
        cout<<"DEBUG::vector for key: "<<it->first<<endl;
        printVector(it->second);
        cout<<endl; 
    }
}

void printVector(Row &tmpRow)
{
    cout<<"DEBUG\t";
    for(auto it = tmpRow.begin(); it != tmpRow.end(); ++it)
    {
        cout<<*it<<"\t";
    }
}
