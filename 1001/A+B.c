#include<stdio.h>
int main()
{
    int math[12];
    int a,b,sum,i=0;
    scanf("%d %d",&a,&b);
    sum=a+b;
    if(sum==0)
    {
        printf("0");    
    }
    else
	{
		if(sum<0)
		{
			printf("-");
			sum=-sum;
		}
		for(;sum>0;i++)
		{
			math[i]=sum%10;
			sum=sum/10;
		}
	} 
	for(i=i-1;i>=0;i--)
	{
		printf("%d",math[i]);
		if(i==6||i==3)
		{
			printf(",");
		}
	}
	return 0;
}
