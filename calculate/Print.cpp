#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
#include"Print.h" 
#include "Scan.h"
using namespace std; 

extern queue<string>data; /*ȫ�ֱ���������*/ 
extern int count;

void Print::output()
{
    if (count<=10)
    {
        while (data.empty()==0)
       {
       	   if (data.size()==1)  /*�����������Ļ���*/ 
       	   {
       	   	  cout<<data.front();
       	   	  data.pop();
       	   }
       	   else
       	   {
       	   	  cout<<data.front()<<endl;
              data.pop();
       	   } 
       }
    }
}
