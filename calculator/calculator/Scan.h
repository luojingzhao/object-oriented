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
        void setinput(string &_input); /*�����ķ�װ */ 
        string getinput();
        queue<string> ToStringQueue(string &input); /*��Ҫ�Ĵ����� */ 
    private:    
        string input;
		queue<string> data;
};



