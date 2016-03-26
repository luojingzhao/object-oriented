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
#include<queue>
#include"Scan.h"
#include"Print.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//
int main(int argc, char** argv) 
{
    Dispose *p=new Dispose();  /*申请内存 */
    Print *t=new Print();     
    string _input, strGetInputRet;    /*实例化string*/ 
     
    /*处理输入的字符串*/ 
    cin>>_input;
    p->setinput(_input);
    strGetInputRet = p->getinput();
    p->ToStringQueue(strGetInputRet);
    
    t->output();   /*输出处理完的字符串*/ 
    
    /*释放内存 ，并使其指向空指针*/ 
    delete p;   
    p=NULL;
    delete t;
    t=NULL;
    
    return 0;
}
