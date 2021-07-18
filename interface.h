typedef struct
{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;

void login();                                                           //to check username amd password.
void reservation();							                                        //main reservation function.
void viewdetails(void);							                                    //view details of all the trains
void cancel(char * str,const char * toRemove);				                  //cancelling booked tickets.	
void printticket(char name[],int,int,float);                            //print ticket 
void specifictrain(int);						                                    //print data related to specific train
float charge(int,int);		                                              //calculating the total fare
int paymentmode();					                                            //the payment modes.
