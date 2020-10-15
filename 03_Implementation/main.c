#include<library.h>
struct book

{


    char name[50],add[80],email[50],ph[20];
    char answer[3];

} list;

char query[50],name[50];

FILE *fp, *ft;

int i,n,ch,l,found,k,n,a;
char z;
char user[10];
char pass[10];

void main()
{

	n=login(user,pass);
	if(n==1)
    {

        printf("  \n\n\n       WELCOME TO LIBRARY MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
        printf("\n\n\n\t\t\t\tPress any key to continue...");
        //getch();
        mainmenu();
    }
    else
        {
           printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
	   // main();


        if (a>2)
        {
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		//getch();


		}
		else
        {

		main();
        }
        }
}
void mainmenu(void)
	{
		int choice;

		system("cls");
		printf("\n------------------------------------------------------------------------------------------------");

		printf("MAIN MENU");
		printf("\n------------------------------------------------------------------------------------------------");
        printf("\n\t \xB2\xB2\xB2\xB2\xB2\xB2 Contact Management System \xB2\xB2\xB2\xB2\xB2\xB2");

        printf("\n\n\n\t\t\tMAIN MENU\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t<1> Add new Contact\n\t\t<2> List all Contacts\n\t\t<3> Search for contact\n\t\t<4> Edit a Contact\n\t\t<5> Delete a Contact\n\t\t<0> Exit\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t");

		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
				add_book();
				break;
				case 2:
			    	list_book();
				break;
				case 3:
				search_book();
				break;
                		case 4:
				edit_book();
				break;
				case 5:
				delete_book();
				case 6:
				exit(0);
				break;

				default:
					printf("Exiting");
					exit(0);


			}
}



/* *********************Add new book************  */

    void add_book()
    {

            char answer;

            system("cls");

            fp=fopen("book.txt","a");

            fflush(stdin);

            printf("\nFullName :");

            scanf("%49[^\n]s",list.name);

            fflush(stdin);

            printf("Phone:");

            //gets(list.ph);
	    scanf("%19s",list.ph);



            //scanf("%ld",&list.ph);

            fflush(stdin);

            printf("address:");

            scanf("%79[^\n]s",list.add);

            fflush(stdin);

            printf("email address:");

           // gets(list.email);
	    scanf("%49s",list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

            fclose(fp);

            printf("\n\t\t Do you want to add another book?[Y/N]:");

            scanf("%2s",&answer);

            /*while(toupper(answer)!='Y'&& toupper(answer)!='N')
            {
                printf("Invalid!\n\tDo you want to add another book?[Y/N]:");
                scanf("%s",&answer);
            }*/
            if((answer=='Y')||(answer=='y'))

            {
                add_book();
            }

            else
            {
                printf("\n\t\tPress any key to go to mainmenu.....");
                mainmenu();
            }
    }



        /* *********************list of books*************************  */

    void list_book()
    {
        char answer;
        system("cls");

        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\tLIST OF CONTACTS\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("book.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n",list.name,

                           list.ph,list.add,list.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
		scanf("%c",&z);

               // getch();
            }

            fclose(fp);

        }
	scanf("%c",&z);
        mainmenu();


    }

        /* *******************search book**********************  */

    void search_book()
    {


            char answer;

            system("cls");
            found=0;

            printf("\n\n\t..::BOOK SEARCH\n\t===========================\n\t..::Name of book to search: ");

            fflush(stdin);

            scanf("%49[^\n]s",query);

            l=strlen(query);

            fp=fopen("book.txt","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                //if(name==query)
		 //if(strcasecmp(name,query)==0)
		 if(strcasecmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        //getch();

                    }

                }

            }


            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n\t\t Do you want to  search another book ?[Y/N]:");

            scanf("%2s",&answer);

            /*while(toupper(answer)!='Y'&& toupper(answer)!='N')
            {
                printf("Invalid!\n\tDo you want to search another book?[Y/N]:");
                scanf("%s",&answer);
            }*/
            if((answer=='Y')||(answer=='y'))
            {
                search_book();
            }
            else
            {
                printf("\n\t\tPress any key to go to mainmenu.....");

                mainmenu();
            }

    }

        /* *********************edit book************************/

 void edit_book()

 {      char answer;
        system("cls");

        fp=fopen("book.txt","r");

        ft=fopen("temp.txt","w");

        fflush(stdin);

        printf("..::Edit book\n===============================\n\n\t..::Enter the name of book to edit:");

        scanf("%49[^\n]s",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

             if(strcasecmp(name,list.name)!=0)


                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name(Use identical):");

        scanf("%49[^\n]s",list.name);

        fflush(stdin);

        printf("..::Phone:");

        //scanf("%ld",&list.ph);
        //gets(list.ph);
  	scanf("%19s",list.ph);


        fflush(stdin);

        printf("..::address:");

        scanf("%79[^\n]s",list.add);

        fflush(stdin);

        printf("..::email address:");

        //gets(list.email);
  	scanf("%49s",list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book.txt");

        rename("temp.txt","book.txt");



        printf("\n\t\t Do you want to edit another book?[Y/N]:");

	    scanf("%2s",&answer);

        /*while(toupper(answer)!='Y'&& toupper(answer)!='N')
        {
            printf("Invalid!\n\tDo you want to edit another contact ?[Y/N]:");
            scanf("%s",&answer);
        }*/
       if((answer=='Y')||(answer=='y'))
        {
            edit_book();
        }
        else
        {
            printf("\n\t\tPress any key to go to mainmenu.....");
            mainmenu();
        }
 }





void delete_book()
{
        char answer;
        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A BOOK\n\t==========================\n\t..::Enter the name of book to delete:");

        scanf("%49[^\n]s",name);

        fp=fopen("book.txt","r");

        ft=fopen("temp.txt","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (strcasecmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("book.txt");

        rename("temp.txt","book.txt");


        printf("book successfully deleted!!!");

        printf("\n\t\t Do you want to delete another book?[Y/N]:");

	    scanf("%2s",&answer);

        /*while(toupper(answer)!='Y'&& toupper(answer)!='N')
        {
            printf("Invalid!\n\tDo you want to delete another contact ?[Y/N]:");
            scanf("%s",&answer);
        }*/
        if((answer=='Y')||(answer=='y'))
        {
            delete_book();
        }
        else
        {
            printf("\n\t\tPress any key to go to mainmenu.....");
            mainmenu();
        }


    }


