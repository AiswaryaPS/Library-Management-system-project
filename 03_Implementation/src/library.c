#include<contact.h>

int login(char user[10],char pass[10])
{
	int k;
    char uname[10];
    char pword[10],code[10];


   // printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  LOGIN FORM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  ");
    	printf("\t\t\t\t\tLOGIN");
	printf(" \n\n                  ENTER USERNAME:-");
	scanf("%9s", uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	/*while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';*/
	scanf("%9s", pword);

	//i=0;

    	//if((uname=="user")&&(pword=="pass"))
	//if((uname,"user")==0 && strcmp(pword,"pass")==0)
	if((strcasecmp(uname,"user")==0 && strcasecmp(pword,"pass")==0)||(strcasecmp(user,"user")==0 && strcasecmp(pass,"pass")==0))
	{
	k=1;

	}
	else
	{
		k=0;


	}

    return k;

}

