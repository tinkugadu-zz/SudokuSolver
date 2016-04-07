#include "utils.h"
#include <fstream>
#include "SudokuClass.h"
#include <sstream>

int getInt(char c);
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout<<"Usage: sudoku size<9> filename"<<endl;
        exit(-1);
    }
    int size = atoi(argv[1]);
    std::string filename(argv[2]);
    std::fstream filePtr;
    filePtr.open(filename.c_str(), std::fstream::in);
    if(!filePtr.is_open())
    {
        perror("Error opening file or file does not exist");
        exit(-1);
    }
    cout<<"filename chosen: "<<filename<<endl;
    //create puzzle object
    Sudoku mySudoku(size);
    std::string tmpStr;
    auto line = 0;

    while(getline(filePtr, tmpStr) && line<size)
    {
        if(tmpStr.length() != size)
        {
            std::stringstream ss;
            ss << "invalid row detected for file: ";
            ss << filename;
            ss <<" @ line: ";
            ss << line;
            perror(ss.str().c_str());
            exit(-1);
        }
//        cout<<"processing line: "<<line<<endl;
        for(int i=0; i<size; ++i)
        {
            auto tmpVal = getInt(tmpStr[i]);
//            cout<<tmpVal<<"\t";
            mySudoku.setVal(line, i, tmpVal);
        }
//        cout<<endl;
        ++line;
    }
    cout<<"done reading file"<<endl;
    mySudoku.printPuzzle();
    filePtr.close();
    return 0;
}

int getInt(char c)
{
    int retVal = 0;
    if(c <= 0x39 && c >= 0x30)
    {
        retVal = c - 0x30;
    }
    return retVal;
}
