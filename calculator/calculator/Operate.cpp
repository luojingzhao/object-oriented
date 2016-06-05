#include "stdafx.h"
#include "Operate.h"


Operate::Operate()
{
	OprRelation[0] = ">><<<>>";  // '+'
	OprRelation[1] = ">><<<>>";  // '-'
	OprRelation[2] = ">>>><>>";  // '*'
	OprRelation[3] = ">>>><>>";  // '/'
	OprRelation[4] = "<<<<<= ";  // '('
	OprRelation[5] = ">>>> >>";  // ')'
	OprRelation[6] = "<<<<< =";  // '#'
}


Operate::~Operate()
{
}


bool Operate::Isoperator(string str)
{
	if (str == "+" || str == "-" ||
		str == "*" || str == "/" ||
		str == "(" || str == ")" || str == "#")
		return true;
	else
		return false;
}






int Operate::Convert(string opr)
{
	int index;

	if (opr == "+")
	{
		index = 0;
	}
	else if (opr == "-")
	{
		index = 1;
	}
	else if (opr == "*")
	{
		index = 2;
	}
	else if (opr == "/")
	{
		index = 3;
	}
	else if (opr == "(")
	{
		index = 4;
	}
	else if (opr == ")")
	{
		index = 5;
	}
	else if (opr == "#")
	{
		index = 6;
	}
	return index;
}


char Operate::PrecedeSign(string opr1, string opr2)
{
	int index1 = Convert(opr1);
	int index2 = Convert(opr2);
	return OprRelation[index1][index2];
}

double Operate::Operation(double opnd1, string op, double opnd2)
{
	double ret;
	if (op == "+")
	{
		ret = opnd1 + opnd2;
	}
	else if (op == "-")
	{
		ret = opnd1 - opnd2;
	}
	else if (op == "*")
	{
		ret = opnd1 * opnd2;
	}
	else if (op == "/")
	{
		ret = opnd1 / opnd2;
	}
	return ret;
}
