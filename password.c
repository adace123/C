#include <stdio.h>
/* Feigenbaum, Aaron */
/* This program checks if a password is alphanumeric only, has at least 8 characters and has at least 2 digits.*/
int main()
{
char ch;
int numcount=0;
int charcount=0;
int x;
/* The while loop goes through each character entered. There are variables to count for the number of total characters and digits.*/
/* The variable x checks if the characters are alphanumeric. If the character is not alphanumeric it returns "invalid password", sets x to 0 and exits the program.*/
/*If all characters are alphanumeric then x is set to 1.*/
while((ch=getchar())!='\n')
{charcount++;
if(ch>='0' && ch<='9')
numcount++;
if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' || ch>='0' && ch<='9')
x=1;
else 
{x=0;
printf("invalid password");
return 0;}
}
/*If x is 1 (all characters are alphanumeric) and there are at least 8 characters and 2 digits, the password is valid. Otherwise it is invalid.*/
if(x==1 && charcount>=8 && numcount>=2)
printf("valid password");
else printf("invalid password");
system("pause");
return 0;
}