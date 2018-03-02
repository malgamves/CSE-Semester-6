#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
using namespace std;
int main()
{
	srand(static_cast <unsigned int> (time(0)));
	int key[26],k,i,j,flag=0,c;
	char Plaintext[200],Ciphertext[200],ch;
	cout<<"\n1.Plaintext to Ciphertext";
	cout<<"\n2.Ciphertext to Plaintext";
	cout<<"\nEnter your choice[1/2]";
	cin>>c;
	if(c==1){
	
	for(i=0;i<26;i++)
	{
		again:
		k=rand()%26+0;
		for(j=0;j<i;j++)
		{
			if(key[j]==k)
			{
				goto again;
			}
		}
		key[i]=k;
	}
		
	for(i=0;i<26;i++)
	{
		cout<<char(65+i)<<":"<<char(key[i]+65)<<endl;
	}
	cout<<"Enter PlainText:";
	gets(Plaintext);
	for(i=0;i<strlen(Plaintext);i++)
	{
		Plaintext[i]=toupper(Plaintext[i]);
	}
	for(i=0;i<strlen(Plaintext);i++)
	{	if(Plaintext[i]==' ')
		{
			Ciphertext[i]=' ';
			continue;
		}
		Ciphertext[i]=char(key[Plaintext[i]-65]+65);
	}
	cout<<"\n"<<Ciphertext;
	}
	else if(c==2){
	cout<<"\nEnter keys";
	for(i=0;i<26;i++)
	{
		cout<<"\n"<<char(i+65)<<":";
		cin>>ch;
		key[i]=toupper(ch)-65;
	}
	fflush(stdin);
	cout<<"\nEnter Ciphertext:";
	gets(Ciphertext);
	for(i=0;i<strlen(Ciphertext);i++)
	{
		Ciphertext[i]=toupper(Ciphertext[i]);
	}
	
	for(i=0;i<strlen(Ciphertext);i++)
	{
		if(Ciphertext[i]==' ')
		{
			Plaintext[i]=' ';
			continue;
		}
		for(j=0;i<26;j++)
		{
			if(key[j]==(int(Ciphertext[i])-65))
			{
				Plaintext[i]=char(j+65);
				break;
			}
		}
	}
	cout<<"\nPlaintext:"<<Plaintext;
   }
	return 0;
}

