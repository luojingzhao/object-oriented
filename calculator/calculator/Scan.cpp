#include "stdafx.h"
#include"Scan.h"

using namespace std;

  //������е����Ͳ�ʵ���� 
string str="";        //ʵ����string���� 

Scan::Scan()
{
}


Scan::~Scan()
{
}

//�õ�˽�г�Ա
void Scan::setinput(string &_input)
{
    input = _input;
}

string Scan::getinput()
{
    return input;
}

//��Ҫ�Ĵ����� 
queue<string> Scan::ToStringQueue(string &input)
{   

    int count=0;        //���������������λ�� 
	while(!data.empty())
	{
		data.pop();
	}
    int n = input.length();
    string tmp=""; 
    
    /*===============================================================

	��������ַ��������֮ǰ���������ж���'('����һ���ǲ���'-'�����
	�ǵĻ���������֮�����һ��'0'���������ͶԴ������ַ���������Ӵ�
	��

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
        	cout<<"Error"<<endl;  /*����������ַ������ȳ���10����������� */ 
        	break;
        }
        if (tmp[i]=='+'||tmp[i]=='-'||tmp[i]=='*'
                             ||tmp[i]=='/'||tmp[i]=='='||tmp[i]=='('||tmp[i]==')')
        {
            count=0;  /*��λ������ */ 
            if(str!="")
            {
            	data.push(str);  /*��֮ǰ��������*/ 
                str.clear();     /*���*/ 
            }
            
            str = tmp[i];   /*�������ٴδ���*/ 
            data.push(str);
            str.clear();
        }
        else if (count<=10&&input[i] <= '9'  && tmp[i] >= '0'||tmp[i]=='.')
        {
            count++;  //����      
            str += tmp[i];  
        }
    }

    if (count<=10&&str!="")  
    {
    	data.push(str);  /*������ĩβ��δ�������������*/ 
    	str.clear();
    }
    return data;
}

