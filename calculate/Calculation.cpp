/************************************************************
FileName: Calculate.cpp
Author:Sonnypp   Version :1.0       Date:16/04/09 
Description:ʵ�ֶ�����Ķ��н��в����������ֵĻ��֣�      
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
#include<cstdio>
#include<string>
#include<queue>
#include<sstream>
#include"Calculation.h"
#include"Operation.h"
using namespace std;

Operation *temp=new Operation();

double Calculation::CaculateExpression(queue<string> data)
{
	stack<string> StaOper; //ֻ����+ - # / ()����
	stack<double> StaNum;  //ֻ����������������
	string str;
	double tmp;
	data.push("#");
	StaOper.push("#");
	StaNum.push(0);
	str = data.front();
	data.pop();
	//printf("caculateExpression one step\n");
	//���##��ԣ����ʽ��ֵ���
	while (str != "#" || StaOper.top() != "#")
	{
		if (!temp->Isoperator(str))
		{
			//��������ջ
			stringstream ss;
			ss<<str;
			ss>> tmp;
			StaNum.push(tmp);
			str = data.front();
			data.pop();
		}
		else
		{
			//�Ƚ�ջ������������ȡ�õĲ����������ȹ�ϵ
			switch (temp->PrecedeSign(StaOper.top(), str))
			{
				case '<'://ջ������Ȩ��
					StaOper.push(str);
					str = data.front();
					data.pop();
					break;
				case '='://������ԣ�ջ�����ŵ���
					StaOper.pop();
					str = data.front();
					data.pop();
					break;
				case '>'://ջ������Ȩ�ߣ��ȵ��������㣬�����������ջ
				{
					string op = StaOper.top();
					StaOper.pop();
					double num2 = StaNum.top();   //�ڶ�����������ǰ
					StaNum.pop();
					double num1 = StaNum.top();
					StaNum.pop();
					double ret = temp->Operate(num1, op, num2);
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


