#ifndef	__OPERATION_H__
#define	__OPERATION_H__
#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"Calculation.h"
using namespace std;

class Operation
{
	public:
		Operation();
		bool Isoperator(string ch);
		int Convert(string opr);
		char PrecedeSign(string opr1, string opr2);
		double Operate(double opnd1, string op, double opnd2);
	private:
		string OprRelation[7];
};


#endif //__OPERATION_H__
