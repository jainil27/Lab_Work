#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int global;
int priority(char t)
{
	switch(t)
	{
		case '*':return 1;
			break;
		case '/':return 1;
			break;
		case '%':return 1;
			break;
		case '+':return 2;
			break;
		case '-':return 2;
			break;
		case '<':return 3;
			break;
		case '>':return 3;
			break;
		case '(':return 8;
			break;
	}
}

void convert(char inf[100],char pof[100])
{
	int i=0,j=0,k=0;
	char stack[100];
	//while(inf[i]!='\0')cout<<inf[i++];
	i=0;
	while(global--)
	{
		//cout<<"=#=";
		if(((int(inf[i])>=97)&&(int(inf[i])<=122))||((int(inf[i])>=65)&&(int(inf[i])<=90)))
		{
			char temp=inf[i];
			pof[j]=temp;	
			//cout<<pof[j]<<" ";
			j++;	
			//cout<<"ALPha assiging:"<<temp;
		}
		else if(int(inf[i])==40)
		{
			
			char t='(';
			stack[k++]=t;
			//cout<<" open_brac assigin:"<<t;
		}
		else if(int(inf[i])==41)
		{
			//cout<<" close_brac ";
			while(stack[k-1]!='(')
			{
				char t=stack[k-1];
				pof[j++]=t;
			//	cout<<pof[j-1]<<" ";
				k--;
			}
			k--;
		}
		else
		{
			
			char temp=inf[i];
			//cout<<" opera assign:"<<temp;
			if(k==0)
			{
				stack[k++]=temp;
			}
			else if(priority(temp)>=priority(stack[k-1])&&k>0)
			{
			    while((priority(temp)>=priority(stack[k-1]))&&k>0)
				{char t=stack[k-1];
				k--;
				pof[j++]=t;
			//	cout<<"!!!!!!!!!!";
			//	cout<<pof[j-1]<<" ";
				}
				stack[k++]=temp;
			}			
			else 
			{
				stack[k++]=temp;
			}
		}
		i++;
	}
	while(k>0)	
	{
	char t=stack[--k];
	pof[j++]=t;
	//cout<<pof[j-1]<<" ";
	}
	pof[j]='\0';
	
}

main()
{
	system("clear");
	char inf[100], pof[100];
	int i;
	cout<<"\t\tINFIX to POSTFIX Conversion";
	cout<<"\n\n\n\nEnter the INFIX expression : ";
	for(i=0;;i++)
	{
		inf[i]=getchar();
		if(int(inf[i])==10)
			{inf[i]='\0';break;}
	}
	global=i;	
	//inf[i]='\0';
	i=0;
	//while(inf[i]!='\0')cout<<inf[i++];
	convert(inf,pof);
	i=0;
	cout<<"\n\nPOSTFIX expression :";
	while(int(pof[i])!=0)
	{
		cout<<(pof[i++]);
	}
	cout<<"\n\n";
}

