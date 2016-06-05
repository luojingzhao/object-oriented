#pragma once
#include"Calculation.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>

using namespace std;
class Operate
{
public:
	Operate();
	~Operate();
	bool Isoperator(string ch);
	int Convert(string opr);
	char PrecedeSign(string opr1, string opr2);
	double Operation(double opnd1, string op, double opnd2);
private:
	string OprRelation[7];
};





