#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"calculate.h"
using namespace std;

queue<string>data; //定义队列的类型并实例化 
string str;  //实例化string类型 
int count;   //用来数输入的数的位数 

void Dispose::setinput(string &_input)
{
	input=_input;
}

string Dispose::getinput()
{
	return input;
}

void Dispose::ToStringQueue(string &input)
{
	int n=input.length();
	int i;
	for(i=0;i<n;i++)
	{
		if(count>10)
		{
			cout<<"Error"<<endl;
			break;
		}
		else if(input[i]=='+'||input[i]=='-'||input[i]=='*'
		                     ||input[i]=='/'||input[i]=='='||input[i]=='('||input[i]==')')
		{
			count=0;  //将位数归零 
			data.push(str);  //将之前的数存入 
			str.clear();
			str=input[i];   //将符号再次存入 
			data.push(str);
			str.clear();
		}
		else if(count<=10)
		{
			count++;  //计数		
			str+=input[i];
		}
	}
	

}

void Print::output()
{
	if(count<=10)
	{
		while(data.empty()==0)
	   {
		   cout<<data.front()<<endl;
		   data.pop();
	   }
	}
}
