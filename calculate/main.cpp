/************************************************************
FileName: main.cpp
Author:Sonnypp   Version :1.0       Date:16/02/25 
Description:实现对输入的四则表达式进行      
Version:Dev-C++ 5.10
Function List:
    1. 处理输入的字符串;
    2. 输出处理后的字符串; 
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
<<<<<<< 5af0c5aae71a5024a1d3dd82cf8f77f1f1e4c42a
{
    Dispose *p = new Dispose();  /*申请内存 */
    Print *t = new Print();
	Calculation *cal=new Calculation();     
    string _input, strGetInputRet;    /*实例化string*/ 
    
    cout<<"输入四则运算式：" ;
    if(argc<2)
    {
    	cout << "无参数" << endl; 
    }
    else
	{
	    if(strcmp(argv[1],"-a") == 0) //判断是否要输出表达式 
	    {
	    	cout<<argv[2]<<"=";
	    	_input=argv[2];
			p->setinput(_input);
	    }
	    else
	    {
	    	_input=argv[1];
	    	p->setinput(_input);
	    }
	    strGetInputRet = p->getinput();
	    
	    double calculate;
	    calculate = cal->CaculateExpression(p->ToStringQueue(strGetInputRet)); //传入队列进行计算 
		cout<<"答案："; 
		t->output(calculate);  //打印答案 
	    
	    /*释放内存 ，并使其指向空指针*/ 
	    delete p;   
	    p=NULL;
	    delete t;
	    t=NULL;
	    delete cal;
	    cal=NULL;
    }
=======
{     

	if(argc<2)
	{
		cout<<"无参数"<<endl;
	}
	else
	{
		if(strcmp(argv[1],"-f") == 0)
		{
		    string test_file=argv[2];    //输入文件名 
			string result_file=argv[3];  //输出文件名 
			Print *t = new Print();
			t->FileOutput(test_file , result_file);	
			
		}
		else
		{
			Dispose *p = new Dispose();  /*申请内存 */
	    	Print *t = new Print();
			Calculation *cal=new Calculation();
			string _input, strGetInputRet;
			
			if(strcmp(argv[1],"-a") == 0)   //判断是否要输出表达式 
			{
				cout<<"答案："; 
		    	cout<<argv[2];
		    	
		    	_input=argv[2];
				p->setinput(_input);
				strGetInputRet = p->getinput();
				
				double results;
				results = cal->CaculateExpression(p->ToStringQueue(strGetInputRet)); //传入队列进行计算 
		    	
				t->output(results);  //打印答案 
			}
			else
			{
				cout<<"答案："; 
		    	_input=argv[1]; 
		    	
		    	p->setinput(_input);
				strGetInputRet = p->getinput();
				
				double results;
				results = cal->CaculateExpression(p->ToStringQueue(strGetInputRet)); //传入队列进行计算 
		    	
				t->output(results);  //打印答案 
			}
			 /*释放内存 ，并使其指向空指针*/ 
			delete p;   
			p=NULL;
			delete t;
			t=NULL;
			delete cal;
			cal=NULL;
	    }
	}
		 
>>>>>>> second finish
    return 0;
}
