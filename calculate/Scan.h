#ifndef	__SCAN_H__
#define	__SCAN_H__
#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;

class Dispose
{
    public:
        void setinput(string &_input); /*函数的封装 */ 
        string getinput();
        void ToStringQueue(string &input); /*主要的处理函数 */ 
    private:    
        string input;
};

#endif	//__SCAN_H__

