#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"calculate.h"
using namespace std;

queue<string>data; //������е����Ͳ�ʵ���� 
string str;  //ʵ����string���� 
int count;   //���������������λ�� 

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
			count=0;  //��λ������ 
			data.push(str);  //��֮ǰ�������� 
			str.clear();
			str=input[i];   //�������ٴδ��� 
			data.push(str);
			str.clear();
		}
		else if(count<=10)
		{
			count++;  //����		
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
