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
#include<queue>
#include"Scan.h"
#include"Print.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//
int main(int argc, char** argv) 
{
    Dispose *p=new Dispose();  /*�����ڴ� */
    Print *t=new Print();     
    string _input, strGetInputRet;    /*ʵ����string*/ 
     
    /*����������ַ���*/ 
    cin>>_input;
    p->setinput(_input);
    strGetInputRet = p->getinput();
    p->ToStringQueue(strGetInputRet);
    
    t->output();   /*�����������ַ���*/ 
    
    /*�ͷ��ڴ� ����ʹ��ָ���ָ��*/ 
    delete p;   
    p=NULL;
    delete t;
    t=NULL;
    
    return 0;
}
