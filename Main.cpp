#include "utils.h"
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::string errMsg = "sudoku file should be entered at : ";
        errMsg += __func__;
        perror(errMsg.c_str());
        exit(-1);
    }
    std::string filename(argv[1]);
    std::fstream filePtr;
    filePtr.open(filename.c_str(), std::fstream::in);
    if(!filePtr.is_open())
    {
        perror("Error opening file or file does not exist");
        exit(-1);
    }
    cout<<"filename chosen: "<<filename<<endl;
    std::string tmpStr;
    while(getline(filePtr, tmpStr))
    {
        cout<<tmpStr<<endl;
    }
    filePtr.close();    
    return 0;
}
