#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;

class Dispose
{
	public:
		void setinput(string &_input); //�����ķ�װ 
		string getinput();
		void ToStringQueue(string &input); //��Ҫ�Ĵ����� 
	private:
		string input;
};

class Print
{
	public:
		void output();
};
 
