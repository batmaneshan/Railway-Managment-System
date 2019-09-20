//MINI Project for T3 examination

/***************************************************************************
****************************************************************************
*********************************HEADER FILES*******************************
****************************************************************************
***************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>


/***************************************************************************
****************************************************************************
*************************FUNCTIONS THAT ARE TO BE USED**********************
****************************************************************************
***************************************************************************/

void add();
void view();
void edit();
void del();
void loading();


/***************************************************************************
****************************************************************************
**********************************STRUCTURE*********************************
****************************************************************************
***************************************************************************/

struct record
{
	char time[6];
	char name[20];
	char place[10];
	char desc[500];
};

/***************************************************************************
****************************************************************************
********************************LOADING SCREEN*****************************
****************************************************************************
***************************************************************************/
void loading()
{

	int x=26,y=10,u=26;
	int v=15,w=25,z=11;
	int r=58,s=11,h=27;
	int k=12,t=27,l=14;
	int a,i,c,e,b,d,f;

	for(a=1;a<=32;a++)
	{
		gotoxy(x++,y);
		printf("_");
	}

	for(c=1;c<=32;c++)
	{
		gotoxy(u++,v);
		printf("_");
	}
	for(e=1;e<=5;e++)
	{
		gotoxy(w,z++);
		{
			for(f=1;f<2;f++)
			{
				printf("|");
			}
		}
	}

	for(b=1;b<=5;b++)
	{
		gotoxy(r,s++);
		{
			for(d=1;d<2;d++)
			{
				printf("|");
			}
		}
	}

	{
		gotoxy(h,k);
		printf("LOADING!! PLEASE WAIT.......");
	}

	for(i=1;i<=29;i++)
	{
		gotoxy(t++,l);
		delay(100);
		printf("%c",(char)223);
	}
	getch();
	clrscr();

}

/***************************************************************************
****************************************************************************
***************************FUNCTION TO ADD RECORDS**************************
****************************************************************************
***************************************************************************/

void add()
{
	struct record e;
	FILE *fp;
	char a='Y';
	char time[10];
	char filen[15];
	int ch;
	clrscr();
	cleardevice();
	printf("\n\n\t***********************************\n");
	printf("\t***********************************\n");
	printf("\t*************ADDING MENU***********\n");
	printf("\t***********************************\n");
	printf("\t***********************************");
	printf("\n\n\n\n\n\n");
	printf("\n\nENTER THE DATE OF THE RECORD(YYYY-MM-DD):");
	fflush(stdin);
	gets(filen);
	fp=fopen(filen,"ab+");
	if(fp==NULL)
	{
		fp=fopen(filen,"ab+");
		if(fp==NULL)
		{
			printf("\n\nCANNOT OPEN THE FILE.....");
			printf("\n\nPRESS ANY KEY TO EXIT....");
			getch();
			return;
		}
	}

	while(a=='Y'||a=='y')
	{
		ch=0;
		fflush(stdin);
		printf("\n\nEnter the time(HH:MM):");
		scanf("%s",time);
		rewind(fp);

		while(fread(&e,sizeof(e),1,fp)==1)
		{
			if(strcmpi(e.time,time)==0)
			{
				printf("\n\nSIMMILAR RECORD AT THE SAME TIME EXISTS...!");
				ch=1;
			}
		}
		if(ch==0)
		{
			strcpy(e.time,time);
			printf("\n\n\tEnter the Name:");
			fflush(stdin);
			gets(e.name);
			fflush(stdin);
			printf("\n\n\tEnter the Place:");
			gets(e.place);
			fflush(stdin);
			printf("\nn\tDescription:");
			fflush(stdin);
			gets(e.desc);
			fwrite( &e,sizeof(e),1,fp);
			printf("\n\n\tTHIS RECORD HAS BEEN ADDED...!!");
		}

		printf("\n\n\tDO YOU WAN TO ADD ANOTHER RECORD...(Y/N)?");
		fflush(stdin);
		a=getchar();
	}

	fclose(fp);
	printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();
	clrscr();
}

/***************************************************************************
****************************************************************************
**************************FUNCTION TO EDIT RECORDS**************************
****************************************************************************
***************************************************************************/


void edit()
{
	FILE *fpte ;
	struct record customer ;
	char time[6],choice,filename[14];
	int num,count=0;
	clrscr();
	cleardevice();
	printf("\n\n\t***********************************\n");
	printf("\t***********************************\n");
	printf("\t************EDITING MENU***********\n");
	printf("\t***********************************\n");
	printf("\t***********************************");
	do
	    {
		    printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");
		    fflush(stdin);
		    gets(filename);
		    printf("\n\tENTER TIME:[hh:mm]:");
		    gets(time);
		    fpte = fopen ( filename, "rb+" ) ;
		    if ( fpte == NULL )
			    {
				printf( "\nRECORD DOES NOT EXISTS:" ) ;
				printf("\nPRESS ANY KEY TO GO BACK");
				getch();
				clrscr();
				return;
			    }
		    while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
		    {
			if(strcmp(customer.time,time)==0)
			{
			    printf("\nYOUR OLD RECORD WAS AS:");
			    printf("\nTIME: %s",customer.time);
			    printf("\nMEETING WITH: %s",customer.name);
			    printf("\nMEETING AT: %s",customer.place);
			    printf("\nNOTE: %s",customer.desc);

			    printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
				printf("\n1.TIME.");
				printf("\n2.MEETING PERSON.");
				printf("\n3.MEETING PLACE.");
				printf("\n4.NOTE.");
				printf("\n5.WHOLE RECORD.");
				printf("\n6.GO BACK TO MAIN MENU.");
				do
				{
					printf("\n\tENTER YOUR CHOICE:");
					fflush(stdin);
					scanf("%d",&num);
					fflush(stdin);
					switch(num)
					{
					    case 1: printf("\nENTER THE NEW DATA:");
						    printf("\nNEW TIME:[hh:mm]:");
						    gets(customer.time);
						    break;

					    case 2: printf("\nENTER THE NEW DATA:");
						    printf("\nNEW MEETING PERSON:");
						    gets(customer.name);
						    break;

					    case 3: printf("\nENTER THE NEW DATA:");
						    printf("\nNEW MEETING PLACE:");
						    gets(customer.place);
						    break;


					    case 4: printf("ENTER THE NEW DATA:");
						    printf("\nNOTE:");
						    gets(customer.desc);
						    break;

					    case 5:  printf("\nENTER THE NEW DATA:");
						     printf("\nNEW TIME:[hh:mm]:");
						     gets(customer.time);
						     printf("\nNEW MEETING PERSON:");
						     gets(customer.name);
						     printf("\nNEW MEETING PLACE:");
						     gets(customer.place);
						     printf("\nNOTE:");
						     gets(customer.desc);
						     break;

					    case 6: printf("\nPRESS ANY KEY TO GO BACK...\n");
						    getch();
						    break;

					    default: printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
						     break;
					}

				}while(num<1||num>8);
			    fseek(fpte,-sizeof(customer),SEEK_CUR);
			    fwrite(&customer,sizeof(customer),1,fpte);
			    fseek(fpte,-sizeof(customer),SEEK_CUR);
			    fread(&customer,sizeof(customer),1,fpte);
			    choice=5;
			    break;
			}
		    }
		    if(choice==5)
		    {
		    system("cls");
		    printf("\n\t\tEDITING COMPLETED...\n");
		    printf("--------------------\n");
		    printf("THE NEW RECORD IS:\n");
		    printf("--------------------\n");
		    printf("\nTIME: %s",customer.time);
		    printf("\nMEETING WITH: %s",customer.name);
		    printf("\nMEETING AT: %s",customer.place);
		    printf("\nNOTE: %s",customer.desc);
		    fclose(fpte);
		    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
		    scanf("%c",&choice);
		    count++;
		    }
		    else
		    {
			printf("\nTHE RECORD DOES NOT EXIST::\n");
			printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
			scanf("%c",&choice);
		    }

	    }while(choice=='Y'||choice=='y');
	    fclose ( fpte ) ;

	    if(count==1)
	    printf("\n%d FILE IS EDITED...\n",count);
	    else if(count>1)
	    printf("\n%d FILES ARE EDITED..\n",count);
	    else
	    printf("\nNO FILES EDITED...\n");
	    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
	    getch();
	    clrscr();
}



/***************************************************************************
****************************************************************************
*************************FUNCTION TO VIEW RECORDS***************************
****************************************************************************
***************************************************************************/

void view()
{
	FILE *fpte;
	struct record temp;
	char time[6],choice,file[14];
	int ch;
	clrscr();
	cleardevice();
	printf("\n\n\t***********************************\n");
	printf("\t***********************************\n");
	printf("\t************VIEWING MENU***********\n");
	printf("\t***********************************\n");
	printf("\t***********************************");

	do
	{
		printf("\n\n\tEnter the date of the record to be viewed (yyyy-mm-dd):");
		fflush(stdin);
		gets(file);

		fpte=fopen(file,"rb");
		if(fpte==NULL)
		{
			printf("\n\n\tTHIS RECORD DOESN'T EXIST...!");
			printf("\n\n\tEnter any key to exit...!");
			getch();
			return;
		}
		cleardevice();

		printf("\n\n\tPlease choose one of the following:");
		printf("\n\n\t1.WHOLE RECORD OF THE DAY.");
		printf("\n\n\t2.RECORD OF A FIXED TIME.");
		printf("\n\n\tENTE YOUR CHOICE:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\n\n\tTHE WHOLE RECORD FOR %s IS:",file);
				while(fread(&temp,sizeof(temp),1,fpte)==1)
				{

					printf("\n\n\tTime:%s",temp.time);
					printf("\n\tName:%s",temp.name);
					printf("\n\tPlace:%s",temp.place);
					printf("\n\tDescription:%s",temp.desc);

				}
				break;

			case 2: printf("\nEnter the time (hh:mm) :");
				fflush(stdin);
				gets(time);
				while(fread(&temp,sizeof(temp),1,fpte)==1)
				{
					if(strcmp(temp.time,time)==0)
					{
						printf("\n\nYour Record is:");
						printf("\n\tTime:%s",temp.time);
						printf("\n\tName:%s",temp.name);
						printf("\n\tPlace:%s",temp.place);
						printf("\n\tDescription:%s",temp.desc);
					}
				}
				break;


			default: printf("\nWrong Choice...!");
				 break;
		}

	printf("\n\n\tWOULD YOU LIKE TO CONTINUE...(Y/N)?:");
	fflush(stdin);
	scanf("%c",&choice);
	}while(choice=='Y'||choice=='y');

	fclose(fpte);
	clrscr();
	return;

}

/***************************************************************************
****************************************************************************
************************FUNCTION TO DELETE A RECORD*************************
****************************************************************************
***************************************************************************/

void del( )
{
		FILE *fp,*fptr ;
		struct record file ;
		char filename[15],another = 'Y' ,time[10];
		int choice,check;

		clrscr();
		cleardevice();

		printf("\n\n\t***********************************\n");
		printf("\t***********************************\n");
		printf("\t***********DELETING MENU***********\n");
		printf("\t***********************************\n");
		printf("\t***********************************");

		while ( another == 'Y' )
		{
			printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");
			printf("\n\n\t#DELETE WHOLE RECORD\t\t\t[1]");
			printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");

			do
			{
				printf("\n\t\tENTER YOU CHOICE:");
				scanf("%d",&choice);

				switch(choice)
				{
					case 1: printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");
						fflush(stdin);
						gets(filename);
						fp = fopen (filename, "wb" ) ;
						if ( fp == NULL )
						{
							printf("\nTHE FILE DOES NOT EXISTS");
							printf("\nPRESS ANY KEY TO GO BACK.");
							getch();
							return ;
						}

						fclose(fp);
						remove(filename);
						printf("\nDELETED SUCCESFULLY...");
						break;

					case 2: printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");
						fflush(stdin);
						gets(filename);
						fp = fopen (filename, "rb" ) ;
						if ( fp == NULL )
						{
							printf("\nTHE FILE DOES NOT EXISTS");
							printf("\nPRESS ANY KEY TO GO BACK.");
							getch();
							return ;
						}

						fptr=fopen("temp","wb");
						if(fptr==NULL)
						{
							printf("\nSYSTEM ERROR");
							printf("\nPRESS ANY KEY TO GO BACK");
							getch();
							return ;
						}

						printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");
						fflush(stdin);
						gets(time);
						while(fread(&file,sizeof(file),1,fp)==1)
						{
							if(strcmp(file.time,time)!=0)
							fwrite(&file,sizeof(file),1,fptr);
						}

						fclose(fp);
						fclose(fptr);
						remove(filename);
						rename("temp",filename);
						printf("\nDELETED SUCCESFULLY...");
						break;

					default: printf("\n\tYOU ENTERED WRONG CHOICE");
						 break;
				}

			}while(choice<1||choice>2);


			printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
			fflush(stdin);
			scanf("%c",&another);
		}
		printf("\n\n\tPRESS ANY KEY TO EXIT...");
		getch();
		clrscr();
}

/***************************************************************************
****************************************************************************
****************************THE MAIN FUNCTION*******************************
****************************************************************************
***************************************************************************/

void main()
{

    int ch;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
    loading();
    cleardevice();
    rectangle(10,10,getmaxx()-5,getmaxy()-5);

    printf("\n\n\t***********************************\n");
    printf("\t***********************************\n");
    printf("\t***********PERSONAL DIARY**********\n");
    printf("\t***********************************\n");
    printf("\t***********************************");

    while(1)

	{
		printf("\n\n\t\tMAIN MENU:");
		printf("\n\n\tADD RECORD\t[1]");
		printf("\n\tVIEW RECORD\t[2]");
		printf("\n\tEDIT RECORD\t[3]");
		printf("\n\tDELETE RECORD\t[4]");
		printf("\n\tEXIT\t\t[5]");
		printf("\n\n\tENTER YOUR CHOICE:");
		scanf("%d",&ch);
		cleardevice();

	    switch(ch)
		    {
			    case 1:
			    add();
			    break;

			    case 2:

			    view();
			    break;

			    case 3:

			    edit();
			    break;

			    case 4:

			    del();
			    break;

			    case 5:
			    printf("\n\n\t\tTHANK YOU...");
			    getch();
			    exit(0);

			    default:
			    printf("\nYOU ENTERED WRONG CHOICE..");
			    printf("\nPRESS ANY KEY TO TRY AGAIN");
			    getch();
			    break;
		    }

		cleardevice();
	}

}
