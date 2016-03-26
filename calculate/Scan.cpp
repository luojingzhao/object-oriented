#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"Scan.h"

using namespace std;

queue<string>data;  //定义队列的类型并实例化 
string str;        //实例化string类型 
int count;        //用来数输入的数的位数 

//得到私有成员
void Dispose::setinput(string &_input)
{
    input=_input;
}

string Dispose::getinput()
{
    return input;
}

//主要的处理函数 
void Dispose::ToStringQueue(string &input)
{
    int n=input.length();
    
    int i;
    for (i=0;i<n;i++)
    {
        if (count>10)
        {
        cout<<"Error"<<endl;  /*假如输入的字符串长度超过10，则输出错误 */ 
        break;
        }
        else if (input[i]=='+'||input[i]=='-'||input[i]=='*'
                             ||input[i]=='/'||input[i]=='='||input[i]=='('||input[i]==')')
        {
            count=0;  /*将位数归零 */ 
            data.push(str);  /*将之前的数存入*/ 
            str.clear();     /*清空*/ 
            
            str=input[i];   /*将符号再次存入*/ 
            data.push(str);
            str.clear();
        }
        else if (count<=10)
        {
            count++;  //计数      
            str+=input[i];  
        }
    }

    if (count<=10)
    {
    	data.push(str);  /*处理若末尾是未超过的数的输出*/ 
    	str.clear();
    }
}


