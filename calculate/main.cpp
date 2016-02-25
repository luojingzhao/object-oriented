#include <iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"calculate.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Dispose *p=new Dispose();  //申请内存 
	Print *t=new Print();     //申请内存 
	string _input, strGetInputRet;
	cin>>_input;
	p->setinput(_input);
	strGetInputRet = p->getinput();
	p->ToStringQueue(strGetInputRet);
	t->output();
	delete p;  //释放内存 ，并使其指向空指针 
	p=NULL;
	delete t;
	t=NULL;
	return 0;
}
