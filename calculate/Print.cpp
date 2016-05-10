#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<queue>
#include"Print.h" 
#include "Scan.h"
#include"Calculation.h"

using namespace std; 


void Print::output(double &results)
{
    cout<<results;
}

void Print::FileOutput(string test_file , string result_file)
{
	ifstream iosin;     //读操作（输入）的文件类 
	ofstream iosout;    //写操作（输出）的文件类 
		    
	//打开文件 
    iosin.open(test_file.c_str(),ios::in);  
	iosout.open(result_file.c_str(),ios::out);
			 
	/*我们必须调用 string::c_str() 成员函数，
	因为 fstream 对象只接受常量字符串作为文件名。
    当你将文件名作为参数传递时，构造函数试图打开指定的文件。
	接着，我们用重载的 ！操作符来检查文件的状态。*/	
			
	while(!iosin.eof())
	{
		string get_input = "";
		Dispose *p = new Dispose();
		Calculation *cal = new Calculation();
				
		getline(iosin,get_input,'\n'); //以换行符作为分界点。
				
		double results;
		results = cal->CaculateExpression(p->ToStringQueue(get_input));
				 
		iosout << results << endl;   //将计算出来的值记录到文件中去
		
	    delete p;   
		p=NULL;
		delete cal;
		cal=NULL;
		
	}
	
	//关闭文件 
	iosin.close();
	iosout.close();
}
