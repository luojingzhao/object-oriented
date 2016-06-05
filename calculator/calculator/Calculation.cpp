/************************************************************
FileName: Calculate.cpp
Author:Sonnypp   Version :1.0       Date:16/04/09 
Description:实现对输入的队列进行操作符和数字的划分，      
Version:Dev-C++ 5.10
Function List:
    1. 处理输入的字符串;
    2. 输出处理后的字符串; 
History:
      <author>    <time>     <version >   <desc>
      luojingzhao    16/02/27                 
***********************************************************/
#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<string>
#include<queue>
#include<sstream>
#include"Calculation.h"
#include"Operate.h"
using namespace std;

Operate *temp=new Operate();

double Calculation::CaculateExpression(queue<string> data)
{
	Operate *temp=new Operate();
	stack<string> StaOper; //只处理+ - # / ()运算
	stack<double> StaNum;  //只处理输入数字运算
	while(!StaOper.empty())
	{
		StaOper.pop();
	}
	while(!StaNum.empty())
	{
		StaNum.pop();
	}
	string str="";
	double tmp;
	data.push("#");
	StaOper.push("#");
	StaNum.push(0);
	str = data.front();
	data.pop();
	//printf("caculateExpression one step\n");
	//如果##配对，表达式求值完成
	while (str != "#" || StaOper.top() != "#")
	{
		if (!temp->Isoperator(str))
		{
			//操作数入栈
			stringstream ss;
			ss<<str;
			ss>> tmp;
			StaNum.push(tmp);
			str = data.front();
			data.pop();
		}
		else
		{
			//比较栈顶操作符和新取得的操作符的优先关系
			switch (temp->PrecedeSign(StaOper.top(), str))
			{
				case '<'://栈顶优先权低
					StaOper.push(str);
					str = data.front();
					data.pop();
					break;
				case '='://括号配对，栈顶括号弹出
					StaOper.pop();
					str = data.front();
					data.pop();
					break;
				case '>'://栈顶优先权高，先弹出，计算，结果操作数入栈
				{
					string op = StaOper.top();
					StaOper.pop();
					double num2 = StaNum.top();   //第二个操作数在前
					StaNum.pop();
					double num1 = StaNum.top();
					StaNum.pop();
					double ret = temp->Operation(num1, op, num2);
					StaNum.push(ret);
					break;
				}		
			}
		 }
	}//end of while
	delete temp;
	temp=NULL;
	return StaNum.top();
}



