#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char mat[5][5];
	int i,j,flag,c=1,x=0,r1,r2,c1,c2,k,y=0,ch;
	char chr[25]={'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char key[25],Nkey[25],plaintext[100],final[26];
	char ciphertext[250],Plain[200],FPlain[250];
	cout<<"\n1.PlainText to CipherText";
	cout<<"\n2.CipherText to PlainText";
	cout<<"\nEnter your Choice [1/2]";
	cin>>ch;
	cout<<"\nEnter Key:";
	cin>>key;
	Nkey[0]=key[0];
	if(ch==1)
	{ fflush(stdin);
	cout<<"\nEnter Plain text:";
	gets(Plain);
	for(i=0,j=0;i<strlen(Plain);i++)
	{	
		if(Plain[i]==' ')
		{
			continue;
		}
		plaintext[j]=Plain[i];
		j++;
	}
	plaintext[j]='\0';
	// converting j's into i
	for(i=0;i<strlen(key);i++)
	{
		if(key[i]=='j')
		{
			key[i]=='i';
		}
		if(key[i]=='J')
		{
			key[i]=='I';
		}
	}
	//for loop for removing multiple characters in key
	for(i=1;key[i]!='\0';i++)
	{	flag=0;
		for(j=0;j<i;j++)
		{
			if(Nkey[j]==key[i])
			{
			flag=1;	
			}
		}
		if(flag==0)
		{
			Nkey[c]=key[i];
			c++;
		}
	}
	cout<<Nkey<<endl;
	// for loop to convert each character in uppercase 
	for(i=0;i<strlen(Nkey);i++)
	{
		Nkey[i]=toupper(Nkey[i]);
	}
	cout<<Nkey<<endl;
 	//to make final string for matrix
	for(i=0,c=0;i<25;i++)
	{	flag=0;
		for(j=0;j<strlen(Nkey);j++)
		{
			if(Nkey[j]==chr[i])
			{
			flag=1;	
			}
		}
		if(flag==0)
		{
			final[c]=chr[i];
			c++;
		}
	}
	cout<<final<<endl;
	// to insert into matrix 
	for(i=0,c=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(c<(strlen(Nkey)))
			{
			mat[i][j]=Nkey[c];
			c++;
			}
			else
			{
				mat[i][j]=final[y];
				y++;	
			}
		}
	}
	//displaying matrix 
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	//converting j's of plaintext into i
	for(i=0;i<strlen(plaintext);i++)
	{
		if(plaintext[i]=='j')
		{
			plaintext[i]='i';
		}
		if(plaintext[i]=='J')
		{
			plaintext[i]='I';
		}
	}
	//converting plaintext into uppercase
	for(i=0;i<strlen(plaintext);i++)
	{
		plaintext[i]=toupper(plaintext[i]);
	}
	cout<<strlen(plaintext)<<plaintext<<endl;
	//converting into 2 block sequance
	for(i=0,j=1,c=0;i<(strlen(plaintext));i=i+2,j=j+2)
	{
		if(plaintext[i]==plaintext[j])
		{
			FPlain[c]=plaintext[i];
			c++;
			FPlain[c]='X';
			c++;
			i=i-1;
			j=j-1;
		}
		else if(j==strlen(plaintext))
		{
			FPlain[c]=plaintext[i];
			c++;
		}
		else
		{
			FPlain[c]=plaintext[i];
			c++;
			FPlain[c]=plaintext[j];
			c++;
		}
		
	}
	if((strlen(FPlain))%2==1 )
	{
		FPlain[c]='X';
		FPlain[++c]='\0';
	}
	else{FPlain[c]='\0';
	}
	cout<<strlen(FPlain)<<FPlain<<endl;
	//Encryption process
	for(i=0,c=1;FPlain[i]!='\0';i=i+2,c=c+2)
	{
		for(j=0;j<5;j++)
		{	
			for(k=0;k<5;k++)
			{
				if(FPlain[i]==mat[j][k])
				{
					r1=j;
					c1=k;
				}
				else if(FPlain[c]==mat[j][k])
				{
					r2=j;
					c2=k;
				}
			}
		}
		if(r1==r2)
		{
			if((c1+1)==5)
			{
				c1=-1;
			}
			if((c2+1)==5)
			{
				c2=-1;
			}
			ciphertext[i]=mat[r1][c1+1];
			ciphertext[c]=mat[r2][c2+1];
		}
		else if(c1==c2)
		{
			if((r1+1)==5)
			{
				r1=-1;
			}
			if((r2+1)==5)
			{
				r2=-1;
			}
			ciphertext[i]=mat[r1+1][c1];
			ciphertext[c]=mat[r2+1][c2];
		}
		else
		{
			ciphertext[i]=mat[r1][c2];
			ciphertext[c]=mat[r2][c1];
		}
	}
	cout<<"CipherText:"<<ciphertext;
	}
else if (ch==2)
{
	cout<<"\nEnter the CipherText:";
	cin>>ciphertext;
	//converting j's into i
		for(i=0;i<strlen(key);i++)
	{
		if(key[i]=='j')
		{
			key[i]=='i';
		}
		if(key[i]=='J')
		{
			key[i]=='I';
		}
	}
	//for loop for removing multiple characters in key
	for(i=1;key[i]!='\0';i++)
	{	flag=0;
		for(j=0;j<i;j++)
		{
			if(Nkey[j]==key[i])
			{
			flag=1;	
			}
		}
		if(flag==0)
		{
			Nkey[c]=key[i];
			c++;
		}
	}
	cout<<Nkey<<endl;
	// for loop to convert each character in uppercase 
	for(i=0;i<strlen(Nkey);i++)
	{
		Nkey[i]=toupper(Nkey[i]);
	}
	cout<<Nkey<<endl;
 	//to make final string for matrix
	for(i=0,c=0;i<25;i++)
	{	flag=0;
		for(j=0;j<strlen(Nkey);j++)
		{
			if(Nkey[j]==chr[i])
			{
			flag=1;	
			}
		}
		if(flag==0)
		{
			final[c]=chr[i];
			c++;
		}
	}
	cout<<final<<endl;
	// to insert into matrix 
	for(i=0,c=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(c<strlen(Nkey))
			{
			mat[i][j]=Nkey[c];
			c++;
			}
			else
			{
				mat[i][j]=final[y];
				y++;	
			}
		}
	}
	//displaying matrix
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	//converting ciphertext into uppercase	
	for(i=0;i<strlen(ciphertext);i++)
	{
		ciphertext[i]=toupper(ciphertext[i]);	
	}
	//Decryption process
	for(i=0,c=1;i<(strlen(ciphertext)-1);i=i+2,c=c+2)
		{	
			for(j=0;j<5;j++)
			{		
				for(k=0;k<5;k++)
				{
					if(ciphertext[i]==mat[j][k])
					{	
						r1=j;
						c1=k;
					}
					else if(ciphertext[c]==mat[j][k])
					{
						r2=j;
						c2=k;
					}
				}
			}	
		if(r1==r2)
		{
			if((c1-1)==-1)
			{
				c1=5;
			}
			if((c2-1)==-1)
			{
				c2=5;
			}
			plaintext[i]=mat[r1][c1-1];
			plaintext[c]=mat[r2][c2-1];
		}
		else if(c1==c2)
		{
			if((r1-1)==-1)
			{
				r1=5;
			}
			if((r2-1)==-1)
			{
				r2=5;
			}
			plaintext[i]=mat[r1-1][c1];
			plaintext[c]=mat[r2-1][c2];
		}
		else
		{
			plaintext[i]=mat[r1][c2];
			plaintext[c]=mat[r2][c1];
		}
	}
	cout<<"\nPlaintext:"<<plaintext;
	for(i=0,j=1,c=0;i<(strlen(plaintext)-1);i=i+2,j=j+2)
	{
		if(plaintext[j]=='X')
		{
			if(plaintext[i]==plaintext[j+1])
			{
				Plain[c]=plaintext[i];
				c++;
			}
			else{ goto L;
			}
		}
		else
		{	L:
			Plain[c++]=plaintext[i];
			Plain[c++]=plaintext[j];
		}
	}
	cout<<"\nPlaintext:"<<Plain;
	}	
	return 0;
}
