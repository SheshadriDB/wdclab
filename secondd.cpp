#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N strlen(g)
char t[128],cs[128],g[]="10110";
int a,e,c;
void xor(){
for (c=1;c<N;c++)cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc()
{
	for(e=0;e<N;e++)cs[e]=t[e];
	do{
		if(cs[0]=='1')xor();
		for (c=0;c<N-1;c++)cs[c]=cs[c+1];
		cs[c]=t[e++];
	}
	while(e<=a+N-1);
}
void main (){
	printf("\n enterpoly:");scanf("%s",t);
	printf("\n generating polynomial is:%s",g);
	a=strlen(t);
	for(e=a;e<a+N-1;e++)t[e]='0';
	printf("\n modified t[u] is:%s",t);
	crc();
	printf("\n checksum is:%s",cs);

	//rx
	for(e=a;e<a+N-1;e++)t[e]=cs[e-a];
	printf("\n final codeword is:%s",t);
	int check,gg;
	printf("\n test error detection 0(yes) 1(no)?");
	scanf("%d",&check);
	if(check==0){
		printf("\n enter position for insert error:");
		scanf("%d",&gg);
		t[gg]=(t[gg]=='1'?'0':'1');
		printf("\n errorneous data:%s:",t);
			printf("\n error: ");
	}
	else {
		printf("\n no error");
	}
	getch();
}