#include<library.h>
int Password(char password[10])
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
p=1;
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
p=0;
}
return p;
