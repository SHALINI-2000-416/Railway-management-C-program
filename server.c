#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"interface.h"

//1.VIEWDETAILS FUNCTION
//----------------------

void viewdetails(void)
{
	system("cls");
	printf("ALL THE TRAINS ARE DEPARTING FROM : BANGALORE\n");
	printf("----------------------------------------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tDeparture Time\tArrival Time\n");
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n12608\tLALBAGH EXPRESS\t\tBANGALORE TO CHENNAI\tRs.999\t\t06:30\t\t12:15");
	printf("\n12028\tSHATABDI EXPRESS\tBANGALORE To CHENNAI\tRs.1097\t\t06:00\t\t11:00");
	printf("\n22691\tRAJDHANI EXPRESS\tBANGALORE TO DELHI\tRs.1999\t\t20:20\t\t05:50");
	printf("\n12627\tKARNATAKA EXPRESS\tBANGALORE TO DELHI\tRs.2599\t\t19:20\t\t09:53");
	printf("\n12253\tANGA EXPRESS\t\tBANGALORE TO KOLKATA\tRs.1899\t\t13:30\t\t22:25");
	printf("\n12509\tGUWAHATI EXPRESS\tBANGALORE TO KOLKATA\tRs.3999\t\t23:30\t\t10:55");
	printf("\n12295\tSANGHAMITRA EXPRESS\tBANGALORE TO VIJAYAWADA\tRs.1997\t\t09:00\t\t22:25");
	printf("\n22352\tPATLIPUTRA EXPRESS\tBANGALORE TO VIJAYAWADA\tRs.1599\t\t09:55\t\t22:55");
	printf("\n16508\tJODHPUR EXPRESS\t\tBANGALORE TO MUMBAI\tRs.2799\t\t21:55\t\t21:40");
	printf("\n16506\tGANDHIDHAM EXPRESS\tBANGALORE TO MUMBAI\tRs.1899\t\t21:00\t\t22:55\n");

	printf("----------------------------------------------------------------------------------------------------------");
    
}


//2.RESERVATION FUNCTION:
//------------------------


void reservation()
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num==12608 || passdetails.train_num==12028 || passdetails.train_num==22691 || passdetails.train_num==12627 || passdetails.train_num==12253 || passdetails.train_num==12509 || passdetails.train_num==12295 || passdetails.train_num==22352 || passdetails.train_num==16508 || passdetails.train_num==16506)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		if(paymentmode()==1)
		{
			printf("\nPAYMENT SUCCESSFUL\n");
			fprintf(fp,"%s %d %d\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num);
			printf("\n==================");
			printf("\nReservation Done\n");
			printf("==================");
			printf("\nPress any key to go back to Main menu");
		}
		else
		{
			        printf("SORRY PAYMENT FAILED\n");
				printf("PLEASE REBOOK AGAIN\n");
		}
	
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress ENTER key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}


//3.CHARGES FUNCTION:
//--------------------


float charge(int train_num,int num_of_seats)
{
	if (train_num==12608)
	{
		return(999.0*num_of_seats);
	}
	if (train_num==12028)
	{
		return(1097.0*num_of_seats);
	}
	if (train_num==22691)
	{
		return(1999.0*num_of_seats);
	}
	if (train_num==12627)
	{
		return(2599.0*num_of_seats);
	}
	if (train_num==12253)
	{
		return(1899.0*num_of_seats);
	}
	if (train_num==12509)
	{
		return(3999.0*num_of_seats);
	}
	if(train_num==12295)
	{
		return(1997.0*num_of_seats);
	}
	if (train_num==22352)
	{
		return(1599.0*num_of_seats);
	}
	if (train_num==16508)
	{
		return(2799.0*num_of_seats);
	}
	if (train_num==16506)
	{
		return(1899.0*num_of_seats);
	}
}


//4.PRINT TICKET FUNCTION:
//--------------------------


void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("|-------------------------------------------------\n");
	printf("|Name:\t\t\t%s\n",name);
	printf("|Number Of Seats:\t%d\n",num_of_seats);
	printf("|Train Number:\t\t%d\n",train_num);
	specifictrain(train_num);
	printf("\n|Charges:\t\t%.2f",charges);
	printf("\n|--------------------------------------------------");

}


//5.SPECIFIC TRAIN FUNCTION:
//---------------------------


void specifictrain(int train_num)
{
	if (train_num==12608)
	{
		printf("|Train:\t\t\tLALBAGH EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO CHENNAI");
		printf("\n|Departure Time:\t06:30");
		printf("\n|Arrival Time:\t\t12:15");
	}
	else if (train_num==12028)
	{
		printf("|Train:\t\t\tSHATABDI EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO CHENNAI");
		printf("\n|Departure Time:\t06:00");
		printf("\n|Arrival Time:\t\t11:00");
	}
	else if (train_num==22691)
	{
		printf("|Train:\t\t\tRAJDHANI EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO DELHI");
		printf("\n|Departure Time:\t20:20");
		printf("\n|Arrival Time:\t\t05:50");
	}
	else if (train_num==12627)
	{
		printf("|Train:\t\t\tKARNATAKA EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO DELHI");
		printf("\n|Departure Time:\t19:20");
		printf("\n|Arrival Time:\t\t09:53");
	}
	else if (train_num==12253)
	{
		printf("|Train:\t\t\tANGA EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO KOLKATA");
		printf("\n|Departure Time:\t13:30");
		printf("\n|Arrival Time:\t\t22:25");
	}
	else if (train_num==12509)
	{			
		printf("|Train:\t\t\tGUWAHATI EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO KOLKATA");
		printf("\n|Departure Time:\t23:30");
		printf("\n|Arrival Time:\t\t10:55");
	}
	else if (train_num==12295)
	{
		printf("|Train:\t\t\tSANGHAMITRA EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO VIJAYAWADA");
		printf("\n|Departure Time:\t09:00");
		printf("\n|Arrival Time:\t\t22:25");
	}
	else if (train_num==22352)
	{
		printf("|Train:\t\t\tPATLIPUTRA EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO VIJAYAWADA");
		printf("\n|Departure Time:\t09:55");
		printf("\n|Arrival Time:\t\t22:55");
	}
	else if (train_num==16508)
	{
		printf("|Train:\t\t\tJODHPUR EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO MUMBAI");
		printf("\n|Departure Time:\t21:55");
		printf("\n|Arrival Time:\t\t21:40");
	}
	else if (train_num==16506)
	{
		printf("|Train:\t\t\tGANDHIDHAM EXPRESS");
		printf("\n|Destination:\t\tBANGALORE TO MUMBAI");
		printf("\n|Departure Time:\t21:00");
		printf("\n|Arrival Time:\t\t22:55");
	}
}


//6.LOGIN FUNCTION:
//------------------


void login()
{
    int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  PLEASE ENTER A VALID USERNAME AND PASSWORD \n  ");
    printf("\n YOU WILL BE GIVEN 3 CHANCES TO ENTER THE VALID USERNAME AND PASSWORD\n");
    printf(" \n                       ENTER USERNAME:-");
    scanf("%s", &uname); 
    printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf(" \n\n\n YOUR LOGIN IS SUCCESSFUL!!!");
	printf("\n\n\n\t\t\t\tPRESS ENTER KEY TO GO TO MAIN MENU...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\n\nSORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSORRY U HAVE ENTERED A WRONG USERNAME AND PASSWORD FOR 3 TIMES!!!");
		printf("\nPLEASE ENTER VALID USERNAME AND PASSWORD NEXT TIME\n\n\n");
		exit(0);
		
		}
			
}


//7.CANCEL FUNCTION:
//------------------


void cancel(char * str,const char * toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        found = 1;
        for(j=0; j < toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }
        if(found == 1)
        {
            for(j=i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;
            i--;
        }
    }
}

//8.PAYMENT MODE FUNCTION:
//------------------------

int paymentmode()
{
	int choice;
	char phno[15];
	char name[79];
	int cvv;
	long int cno;
	int otp;
	long int phone;
	#define otp1 7997;
	#define phone 9876543219;
	system("cls");
	printf("\nPLEASE ENTER THE PAYMENT MODE\n");
	printf("1.DEBIT/CREDIT CARD\n");
	printf("2.PAYTM\n");
	printf("3.GOOGLE PAY\n");
	printf("\nEnter the mode of payment u want:-\n");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:printf("|----------------------------|\n");
		       printf("|      DEBIT/CREDIT CARD     |\n");
		       printf("|----------------------------|\n");
			printf("CARD NO:\t");
		        scanf("%ld",&cno);
		        printf("NAME ON CARD:\t");
		        fflush(stdin);
			scanf("%s",name);
			printf("ENTER THE CVV:\t");
			scanf("%d",&cvv);
			printf("PLEASE ENTER THE OTP RECEIVED:\t");
			scanf("%d",&otp);
			if(otp==7997)
			{
			       return 1;
			}
			else
			{

				return 0;
			}
			
			break;
		case 2:printf("|--------------------------|\n");
		       printf("|         PAYTM  APP       |\n");
		       printf("|--------------------------|");
			printf("\nMOBILE NUMBER:\t");
			fflush(stdin);
			scanf("%s",&phno);
			if(strcmp(phno,"9876543219")==0)
				return 1;
				
			else
			{
				return 0;
			}
			
			break;
		case 3:printf("|--------------------------|\n");
		       printf("|      GOOGLE PAY APP      |\n");
		       printf("|--------------------------|");
			printf("\nCONTACT INFO:\t");
			fflush(stdin);
			scanf("%s",&phno);
			if(strcmp(phno,"9876543219")==0)
				return 1;
			else
			{
				return 0;
			}
			break;



		default:printf("\nPLEASE ENTER THE RIGHT CHOICE\n");
	}
}