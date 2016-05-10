#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<queue>
#include"Print.h" 
#include "Scan.h"
#include"Calculation.h"

using namespace std; 


void Print::output(double &results)
{
    cout<<results;
}

void Print::FileOutput(string test_file , string result_file)
{
	ifstream iosin;     //�����������룩���ļ��� 
	ofstream iosout;    //д��������������ļ��� 
		    
	//���ļ� 
    iosin.open(test_file.c_str(),ios::in);  
	iosout.open(result_file.c_str(),ios::out);
			 
	/*���Ǳ������ string::c_str() ��Ա������
	��Ϊ fstream ����ֻ���ܳ����ַ�����Ϊ�ļ�����
    ���㽫�ļ�����Ϊ��������ʱ�����캯����ͼ��ָ�����ļ���
	���ţ����������ص� ��������������ļ���״̬��*/	
			
	while(!iosin.eof())
	{
		string get_input = "";
		Dispose *p = new Dispose();
		Calculation *cal = new Calculation();
				
		getline(iosin,get_input,'\n'); //�Ի��з���Ϊ�ֽ�㡣
				
		double results;
		results = cal->CaculateExpression(p->ToStringQueue(get_input));
				 
		iosout << results << endl;   //�����������ֵ��¼���ļ���ȥ
		
	    delete p;   
		p=NULL;
		delete cal;
		cal=NULL;
		
	}
	
	//�ر��ļ� 
	iosin.close();
	iosout.close();
}
