#ifndef __PRINT_H__
#define __PRINT_H__
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std; 

class Print
{
    public:
        void output(double &results);  /*�ַ��������*/ 
        void FileOutput(string test_file , string result_file);
};
#endif //__PRINT_H__
