#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"Scan.h"

using namespace std;

queue<string>data;  //������е����Ͳ�ʵ���� 
string str;        //ʵ����string���� 
int count;        //���������������λ�� 

//�õ�˽�г�Ա
void Dispose::setinput(string &_input)
{
    input=_input;
}

string Dispose::getinput()
{
    return input;
}

//��Ҫ�Ĵ����� 
void Dispose::ToStringQueue(string &input)
{
    int n=input.length();
    
    int i;
    for (i=0;i<n;i++)
    {
        if (count>10)
        {
        cout<<"Error"<<endl;  /*����������ַ������ȳ���10����������� */ 
        break;
        }
        else if (input[i]=='+'||input[i]=='-'||input[i]=='*'
                             ||input[i]=='/'||input[i]=='='||input[i]=='('||input[i]==')')
        {
            count=0;  /*��λ������ */ 
            data.push(str);  /*��֮ǰ��������*/ 
            str.clear();     /*���*/ 
            
            str=input[i];   /*�������ٴδ���*/ 
            data.push(str);
            str.clear();
        }
        else if (count<=10)
        {
            count++;  //����      
            str+=input[i];  
        }
    }

    if (count<=10)
    {
    	data.push(str);  /*������ĩβ��δ�������������*/ 
    	str.clear();
    }
}


