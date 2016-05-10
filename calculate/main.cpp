/************************************************************
FileName: main.cpp
Author:Sonnypp   Version :1.0       Date:16/02/25 
Description:ʵ�ֶ������������ʽ����      
Version:Dev-C++ 5.10
Function List:
    1. ����������ַ���;
    2. ����������ַ���; 
History:
      <author>    <time>     <version >   <desc>
      luojingzhao    16/02/27                 
***********************************************************/

#include<iostream>
#include<stdlib.h>
#include<string> 
#include<string.h> 
#include<queue>
#include<fstream> 
#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include"Operation.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char* argv[]) 
{
	if(argc<2)
	{
		cout<<"�޲���"<<endl;
	}
	else
	{
		if(strcmp(argv[1],"-f") == 0)
		{
		    string test_file=argv[2];    //�����ļ��� 
			string result_file=argv[3];  //����ļ��� 
			Print *t = new Print();
			t->FileOutput(test_file , result_file);	
			
		}
		else
		{
			Dispose *p = new Dispose();  /*�����ڴ� */
	    	Print *t = new Print();
			Calculation *cal=new Calculation();
			string _input, strGetInputRet;
			
			if(strcmp(argv[1],"-a") == 0)   //�ж��Ƿ�Ҫ������ʽ 
			{
				cout<<"�𰸣�"; 
		    	cout<<argv[2];
		    	
		    	_input=argv[2];
				p->setinput(_input);
				strGetInputRet = p->getinput();
				
				double results;
				results = cal->CaculateExpression(p->ToStringQueue(strGetInputRet)); //������н��м��� 
		    	
				t->output(results);  //��ӡ�� 
			}
			else
			{
				cout<<"�𰸣�"; 
		    	_input=argv[1]; 
		    	
		    	p->setinput(_input);
				strGetInputRet = p->getinput();
				
				double results;
				results = cal->CaculateExpression(p->ToStringQueue(strGetInputRet)); //������н��м��� 
		    	
				t->output(results);  //��ӡ�� 
			}
			 /*�ͷ��ڴ� ����ʹ��ָ���ָ��*/ 
			delete p;   
			p=NULL;
			delete t;
			t=NULL;
			delete cal;
			cal=NULL;
	    }
	}
		 
    return 0;
}
