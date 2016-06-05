#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;

class Scan
{
    public:
		Scan();
		~Scan();
        void setinput(string &_input); /*函数的封装 */ 
        string getinput();
        queue<string> ToStringQueue(string &input); /*主要的处理函数 */ 
    private:    
        string input;
		queue<string> data;
};



