#include "stdafx.h"
#include"Scan.h"

using namespace std;

  //定义队列的类型并实例化 
string str="";        //实例化string类型 

Scan::Scan()
{
}


Scan::~Scan()
{
}

//得到私有成员
void Scan::setinput(string &_input)
{
    input = _input;
}

string Scan::getinput()
{
    return input;
}

//主要的处理函数 
queue<string> Scan::ToStringQueue(string &input)
{   

    int count=0;        //用来数输入的数的位数 
	while(!data.empty())
	{
		data.pop();
	}
    int n = input.length();
    string tmp=""; 
    
    /*===============================================================

	对输入的字符串在入队之前先做处理，判断在'('的下一个是不是'-'，如果
	是的话就在他们之间加入一个'0'，处理完后就对处理后的字符串进行入队处
	理。

	==============================================================*/
	for(int i=0; i<n-1; i++)
	{
		if(input[i]=='('&&input[i+1]=='-')
		{
			tmp+=input[i];
			tmp+='0';
		}
		else if(input[i]=='-'&&input[i+1]=='-')
		{
			tmp+='+';
			i++;
		}
		else if(input[i]=='-'&&input[i+1]=='+')
		{
			tmp+=input[i];
			i++;
		}
		else if(input[i]=='+'&&input[i+1]=='-')
		{
			tmp+=input[i];
			tmp+='0';
		}
		else if(input[i]=='+'&&input[i+1]=='+')
		{
			tmp+=input[i];
			i++;
		}
		else if(input[i]==')'&&input[i+1]=='(')
		{
			tmp+=input[i];
			tmp+='*';
		}
		else if(input[i]>='0'&&input[i]<='9'&&input[i+1]=='(')
		{
			tmp+=input[i];
			tmp+='*';
		}
		else if(input[i]==')'&&isdigit(input[i+1]))
		{
			tmp+=input[i];
			tmp+='*';
		}
		else
		{
			tmp+=input[i];
		}
	}

    int i;
    n = tmp.length();
    for (i=0;i<n;i++)
    {
        if (count>10)
        {
        	cout<<"Error"<<endl;  /*假如输入的字符串长度超过10，则输出错误 */ 
        	break;
        }
        if (tmp[i]=='+'||tmp[i]=='-'||tmp[i]=='*'
                             ||tmp[i]=='/'||tmp[i]=='='||tmp[i]=='('||tmp[i]==')')
        {
            count=0;  /*将位数归零 */ 
            if(str!="")
            {
            	data.push(str);  /*将之前的数存入*/ 
                str.clear();     /*清空*/ 
            }
            
            str = tmp[i];   /*将符号再次存入*/ 
            data.push(str);
            str.clear();
        }
        else if (count<=10&&input[i] <= '9'  && tmp[i] >= '0'||tmp[i]=='.')
        {
            count++;  //计数      
            str += tmp[i];  
        }
    }

    if (count<=10&&str!="")  
    {
    	data.push(str);  /*处理若末尾是未超过的数的输出*/ 
    	str.clear();
    }
    return data;
}

