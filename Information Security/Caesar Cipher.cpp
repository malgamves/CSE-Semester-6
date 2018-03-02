#include<iostream>
using namespace std;
int main()
{
	char P[50],C[50],D[50];
	int ch,i,key;

		cout<<"\n1.Plain Text to Caesar Cipher Text";
		cout<<"\n2.Caesar Cipher Text to Plain Text";
		cout<<"\nEnter your Choice [1/2]:";
		cin>>ch;
		if(ch==1){
		
		cout<<"\nEnter any Plain text:";
	    //gets(P);
	    cin>>P;
	    cout<<"\nEnter key:";
	    cin>>key;
		for(i=0;P[i]!='\0';i++)
		{
		C[i]=P[i]+key;
		if(P[i]>=65 && P[i]<=90)
		{
			if(C[i]>90)
			{
				C[i]=C[i]-90+64;
				
			}		
		}
		if(P[i]>=97 && P[i]<=122)
		{
			if(C[i]>122)
			{
				C[i]=C[i]-122+96;
				
			}		
		}
	}
	cout<<"\nCipher Text:"<<C;
	}
	else if(ch==2)
	{
	cout<<"\nEnter Caesar Cipher Text:";
	cin>>C;
	cout<<"\nEnter key:";
	cin>>key;
	for(i=0;C[i]!='\0';i++)
	{
		D[i]=C[i]-key;
		if(C[i]>=65 && C[i]<=90)
		{
			if(D[i]<65)
			{
				D[i]=90-(64-D[i]);
				
			}		
		}
		if(C[i]>=97 && C[i]<=122)
		{
			if(D[i]<97)
			{
				D[i]=122-(96-D[i]);
				
			}		
		}
	}
	cout<<"\nDecrypted Text:"<<D;
  }
  else{
  	cout<<"\nWrong Choice";
  }
return 0;
}
