#include <stdio.h>
/* Aaron Feigenbaum */
int main()
{
	char ch;
	printf("Enter an alphabetic phone number: ");
	/* For each uppercase letter (except for Z) the user enters, 
	the while statement assigns a number value to it as on a telephone.
	The program then prints the result. If the user did not enter
	an uppercase letter (or entered a Z) then the program echoes what the user
	entered.*/
	while ((ch=getchar())!='\n')
	{
		if(ch>='A' && ch<='C')
		{ch='2'; printf("%c",ch);}	
		else if(ch>='D' && ch<='F')
		{ch='3'; printf("%c",ch);}
		else if(ch>='G' && ch<='I')
		{ch='4'; printf("%c",ch);}
		else if(ch>='J' && ch<='L')
		{ch='5'; printf("%c",ch);}
		else if(ch>='M' && ch<='O')
		{ch='6'; printf("%c",ch);}
		else if(ch>='P' && ch<='S')
		{ch='7'; printf("%c",ch);}
		else if(ch>='T' && ch<='V')
		{ch='8'; printf("%c",ch);}
		else if(ch>='W' && ch<='Y')
		{ch='9'; printf("%c",ch);}
		else printf("%c",ch);
	}
	printf("\n");
	system ("pause");
	return 0;
}