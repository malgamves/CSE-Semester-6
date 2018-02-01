//Practical 1
// Done by Daniel Phiri
// Aim: Implementation Caeser Cipher Encryption and Decryption

#include<iostream>

using namespace std;

char cipher(char x[])
{
	char C[25];
	int a,i;
	for(i=0;x[i]!='\0';i++)
	{
		C[i] = x[i]+3;
		if(x[i]>=65 && x[i]<=90)
		{
			if(C[i]>90)
			{
				C[i]= C[i] - 90 + 64;

			}
		}
		if(x[i] >= 97 && x[i]<= 122)
		{
			if(C[i]> 122)
			{
				C[i] = C[i] - 122+96;

			}
		}
	}
	cout<<"\nCiphered text is - "<<C;
	return 0;
}


char dcipher(char x[])
{
	char C[25];
	int a,i;
	for(i=0;x[i]!='\0';i++)
	{
		C[i] = x[i]-3;
		if(x[i]>=65 && x[i]<=90)
		{
			if(C[i]>65)
			{
				C[i]= C[i] + 90 - 64;

			}
		}
		if(x[i] >= 97 && x[i]<= 122)
		{
			if(C[i]> 97)
			{
				C[i] = C[i] + 122 - 96;

			}
		}
	}
	cout<<"\nDeciphered text is - "<<C;
	return 0;
}

int main()
{
	char P[25];
	int choice;
	cout<<"What would you like to do?\n1. Encrypt\n2. Decrypt\n";
	cin>>choice;
	cout<<"\nEnter text\n";
	//gets(P);
	cin>>P;
	if(choice == 1)
	{
		cipher(P);

	}
	else if(choice == 2)
	{
		dcipher(P);

	}

	return 0;
}
