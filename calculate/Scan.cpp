#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"Scan.h"

using namespace std;

queue<string> data;  //������е����Ͳ�ʵ���� 
string str="";        //ʵ����string���� 
int count=0;        //���������������λ�� 

//�õ�˽�г�Ա
void Dispose::setinput(string &_input)
{
    input = _input;
}

string Dispose::getinput()
{
    return input;
}

//��Ҫ�Ĵ����� 
queue<string> Dispose::ToStringQueue(string &input)
{
    int n = input.length();
    //cout<<n<<endl;
    
    int i;
    for (i=0;i<n;i++)
    {
        if (count>10)
        {
        cout<<"Error"<<endl;  /*����������ַ������ȳ���10����������� */ 
        break;
        }
        if (input[i]=='+'||input[i]=='-'||input[i]=='*'
                             ||input[i]=='/'||input[i]=='='||input[i]=='('||input[i]==')')
        {
            count=0;  /*��λ������ */ 
            if(str!="")
            {
            	data.push(str);  /*��֮ǰ��������*/ 
                str.clear();     /*���*/ 
            }
            
            str = input[i];   /*�������ٴδ���*/ 
            data.push(str);
            str.clear();
        }
        else if (count<=10&&input[i] <= '9'  && input[i] >= '0'||input[i]=='.')
        {
            count++;  //����      
            str += input[i];  
        }
    }

    if (count<=10&&str!="")  
    {
    	data.push(str);  /*������ĩβ��δ�������������*/ 
    	str.clear();
    }
    return data;
}


