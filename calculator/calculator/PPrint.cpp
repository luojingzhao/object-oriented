#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<queue>
#include"PPrint.h" 
#include "Scan.h"
#include "Calculation.h"

using namespace std; 


void PPrint::output(double &results)
{
    cout<<results;
}

void PPrint::FileOutput(string test_file , string result_file)
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
		Scan *p = new Scan();
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
