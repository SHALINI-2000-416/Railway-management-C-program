#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"interface.h"

void main()
{
	int n;
	FILE * fPtr;
    	FILE * fTemp;
    	char path[100];
    	char toRemove[100];
    	char buffer[1000];
	char feedback[79];
	system("cls");
	printf("\t\t|-----------------------------------------------------|\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|        -----------------------------------          |\n");
	printf("\t\t|          TRAIN TICKET RESERVATION SYSTEM            |\n");
	printf("\t\t|        -----------------------------------          |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|                                                     |\n");
	printf("\t\t|-----------------------------------------------------|\n\n\n");
		
	    
	printf(" \n Press ENTER key to continue:");
        getch();            //it reads a single character from keyboard. But it does not use any buffer, so the                               entered character is immediately returned without waiting for the enter key.	
        system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1.Reserve A Ticket");
	printf("\n2.View All Available Trains");
	printf("\n3.Cancel Reservation");
	printf("\n4.Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1: reservation();		              
			break;
		case 2: viewdetails();
			getch();
			break;
		case 3: system("cls");
			printf("THE RESERVATION LIST:\n");
			scanf("%s",path);
			fflush(stdin);
			printf("\n\nENTER THE DETAILS IN THE FORMAT:\n\nNAME\tNO OF SEATS\tTRAIN NUMBER\n\n");
    			scanf("%[^\n]", toRemove);
    			fPtr  = fopen(path, "r");
    			fTemp = fopen("delete.txt", "w"); 
    			while ((fgets(buffer,100, fPtr)) != NULL)
    			{
        		// Remove all occurrence of word from current line
        		cancel(buffer, toRemove);

       			 // Write to temp file
        		fputs(buffer, fTemp);
    			}
    			fclose(fPtr);
    			fclose(fTemp);
    			remove(path);
   			rename("delete.txt",path);
    			printf("\n\n\nYOUR BOOKING DETAILS GOT CANCELLED");
			getch();
			break;
		case 4: system("cls");
			printf("PLEASE GIVE YOUR FEEDBACK BEFORE YOU EXIT\n\n");
			fflush(stdin);
			scanf("%[^\n]",feedback);
			printf("\n\n\nTHANK YOU FOR YOUR FEEDBACK!!!");
			printf("DO VISIT US AGAIN");
			exit(0);
		default:printf("\nINVALID CHOICE");
	}
	goto start;
}
