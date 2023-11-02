#include <stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#define MAX 1000
int main()
{
	{
		int s,pi,ci;
		char plain[MAX],cipher[MAX];
		printf("***encryption , decr\n\n");
			printf("\n enter:\n");
			gets(plain);
		while(1)
		{
			printf("\n Key(number of shifts per char)for encry:");
				scanf("%d",&s);
			if(s<1||s>25)
				printf("bad input");
			else
				break;
		}
		printf("after removing");
		for(ci=0,pi=0;plain[pi]!='\0';pi++)
			if(isalpha(plain[pi]))
				return 0;
			{
				putchar(toupper(plain[pi]));
				cipher[ci++]=((toupper(plain[pi])-'a')+s%26)%26+'a';
			}
			cipher[ci]='\0';
			printf("after encry");
			while(1)
			{
				printf("key");
				scanf("%D",&s);
				if(s<1||s>25)
					printf("bad");
				else
					break;
			}
			for(pi=0,ci=0;cipher[ci]!='\0';ci++)
				plain[pi++]=((cipher[ci]-'a')+(26-s))%26+'a';
			plain[pi]='\0';
			printf("aft decrp");
			//return 0;
	}
	getch();
}
