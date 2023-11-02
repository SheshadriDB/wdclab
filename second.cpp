#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	{

		char ch,arr[50]={"01111110"},rev[50];
		int i,j,k,len=8,cnt=0;
		printf("enter the data\n");
		while((ch=getche())!='\r')
		{
			if(ch=='1')
				cnt++;
			else
				cnt=0;
			arr[len++]=ch;
			if(cnt==5)
			{
				arr[len++]='0';
					cnt=0;
			}
		}
		strcat(arr,"01111110");
		printf("\n bit stuffed stream is :\n");
		for(i=0; i<len+8; i++)
			printf("%c",arr[i]); 

	
		//distuffing
		cnt=0;
		printf("\n bit distuffed stream is :\n");
		for(j=8,k=0;j<len;j++) 
		{
			if(arr[j]=='1')
				cnt++;
			else
				cnt=0;
			rev[k++]=arr[j];
			if(cnt==5&& arr[j+1]=='0')
			{
				j++;
				cnt=0;
			}
		}
		for(j=0;j<k;j++)
			printf("%c",rev[j]);
	}
	
	getch();


}
