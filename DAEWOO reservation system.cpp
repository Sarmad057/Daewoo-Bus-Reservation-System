#include <conio.h>
#include <stdio.h>
#include <stdlib.h>      //header files
#include <strings.h>
#include<windows.h>
int inc=0,u,s,sum[32]={0},pass=0;     // Global variables initialization

void reserve_ticket();             //function prototype to reserve ticket
void modify_reservation();        //function prototype to modify reservation 
void cancel_reservation();       //function prototype to cancel reservation
void search_name();              //function prototype to search record by name
void search_date();				//function prototype to search record by date

    struct date_of_travel            //structure of the date of travel
    {
           int day,month,year;
    };
    struct time_of_travel            //structure for the time of travel
    {
           int hour,min;
           
    };
    struct  info                   //structure for different data types
    {
            char  n_pas[30],dep_city[30],des_city[30];     //stores name ,destination and departure city of passenger
            int n_tickets,idd;                                    // stores number of tickets
            struct date_of_travel d1;                       
            struct time_of_travel t1;
    }p1[32];                //array created of size 32 as p1[32]
    


int main()
{
    int choice;
    FILE *fp= fopen("bus rec.txt","r");                                //opening a file in read mode,creating a pointer of that file
    while (fread(&p1[inc],sizeof(p1[inc]),1,fp)!=NULL)                
    {inc++;
    s++;
    u++;
          }
    printf("\n\t\t   **********************************************");
    printf("\n\t\t   *  Welcome to the DAEWOO reservation system  *");
    printf("\n\t\t   *\t\t\t\t\t        *");
    printf("\n\t\t   **********************************************");
    printf("\n\n\t\t\t\t  |*..MAIN MENU..*|\n\n");
    do																
    {
    printf("\n-->Enter 0 if you are admin");                           				//mode 0 for Admin access
    printf("\n-->Enter 1 to reserve your ticket ");    								//mode 1 for reservation
    printf("\n-->Enter 2 to modify your reservation ");                					//mode 2 for modification of reservation
    printf("\n-->Enter 3 to cancel reservation ");                     						//mode 3 for cancelling the reservation
    printf("\n-->Enter 4 to search information of passenger by NAME ");   							//mode 4 for searching by name
    printf("\n-->Enter 5 to search information of passenger by DATE-OF-TRAVEL(dd-mm-yy) ");		//mode 5 for searching by date
    printf("\n-->Enter 6 to EXIT :");					// mode 6 to exit
    scanf("%d",&choice);            //mode value stored in variable named choice
    switch(choice)              //applying switch statement for modes
    {
                  case 0:					//admin access mode
                       {
                            FILE *fp= fopen("bus rec.txt","r");        //file opened in read mode
                            fseek(fp,0,SEEK_SET);                      //its for placing the cursor at end
                            printf("Enter password for login  :");        // password required for admin access
                            scanf("%d",&pass);
                            if(pass==54321)                            //password checking
                            {
                      	
                            printf("\nloading ");
                            Sleep(1000);
							printf(".");
							Sleep(1000);
							printf(".");                            //shows loading or processing
							Sleep(1000);
							printf(".");
                            Sleep(1500);
                            printf(".");   
						    while (fread(&p1[inc],sizeof(p1[inc]),1,fp)!=NULL)          //checking file for read mode
						    {                                             //displaying user s information
						    printf("\nName of passenger :");            
                            puts(p1[inc].n_pas); 
							printf("id of the passenger");
							printf("%d",p1[inc].idd);                         //Display name 
                            printf("\ndeparture city :");         
                            puts(p1[inc].dep_city);                      //Display departure city 
                            printf("\ndestination city :");
                            puts(p1[inc].des_city);                     //Display destination city 
                            printf("\n\n\ndate of travel : (day-month-year)");
                            printf("%d  %d  %d",p1[inc].d1.day,p1[inc].d1.month,p1[inc].d1.year);           //Display date of travel 
                            printf("\ntime of travel : (hour(00 to 24)-min(00 to 60))");
                            printf("%d  %d",p1[inc].t1.hour,p1[inc].t1.min);                                //Display time of travel
                            printf("\nnumber of tickets :");
                            printf("%d",p1[inc].n_tickets);         ///Display number of tickets
						    	inc++;          //increment
						    }
						  
                            
                           
                     }
                             else
						    {      
						    printf("\npassword is incorrect ");
					        }
                          
                                              
                           
          }
					   
                       break;
                  case 1:                //mode for new reservation
                       {
                       reserve_ticket();          //function call for reserving ticket
                       }
                       break;
                  case 2:					//mode for modify reservation
                       {
                       modify_reservation();         //function call for modify reservation
                       }
                       break;
                  case 3:                    //mode for cancel a reservation
                       {
                       cancel_reservation();       //function call for cancel a reservation
                       }
                       break;
                  case 4:                   //mode for searching record by name
                       {
                       	search_name();             //function call for searching by name
                       }
                       break;
                  case 5:                  //mode for searching by date
                       {
                    search_date();                //function for searching by date
                       }
                       break;
                  case 6:                 //mode for exit
                       {
                       printf("\n\nSAVING DATA");
                       
                                    //saving entered data before exit
                       FILE *fp;         //pointer of file
                       fp = fopen("bus rec.txt","w"); 
                       for (int i=0;i<inc;i++)
					   {
					   	fwrite (&p1[i],sizeof(p1[i]),1,fp);                 //entering data into file
					   }
					   Sleep(800);
                       printf(".");
                       Sleep(800);
                       printf(".");
                       Sleep(800);
                       printf(".");
                       Sleep(800);
                       printf(".");
                       Sleep(800);
                       printf(".");
                       Sleep(800);
                       printf(".");
					    fclose(fp);
                        printf("\n\tDATA succesfuly saved");
                                         //closing a fie
					    printf("press any key to exit");
                        break;
                       }
                       
                  default:
                       {
                        printf("\n\t\t\t......wrong choice......");             //wrong choice if no match found
                       }
                       break;
                  }
    }while(choice!=6);
    getche();
}
void reserve_ticket()                          //function to reserve ticket
{
     printf("\n\n***********You are in a mode to reserve your ticket**********");
                            printf("\nEnter name of passenger :");
                            scanf("%s",&p1[inc].n_pas);
							printf("enter id of the passenger :");
							scanf("%d",&p1[inc].idd);                                       //getting name as input
                            printf("\nEnter the name of departure city :");
                            scanf("%s",&p1[inc].dep_city);                                   //getting departure city as input
                            printf("\nEnter the name of destination city :");
                            scanf("%s",&p1[inc].des_city);			                         //getting destination city as input
                            printf("\n\n\nEnter date of travel : (day-month-year)");         //getting date as input
                            printf("\nEnter day:");
                            scanf("%d",&p1[inc].d1.day);
                            if(p1[inc].d1.day>31 )
                            {
                            	printf("\n Day should be  from 1 to 31  :");
                            	scanf("%d",&p1[inc].d1.day);
                            }
                            printf("\nEnter month :");
                            scanf("%d",&p1[inc].d1.month);
    
                            printf("\n Enter year:");
                            scanf("%d",&p1[inc].d1.year);        
                            printf("\nEnter time of travel : (hour(00 to 24)-press enter-min(00 to 60))");
                            scanf("%d  %d",&p1[inc].t1.hour,&p1[inc].t1.min);                       //getting date as input
                            if(p1[inc].t1.hour>24)                 //condition for checking time greater than  24
                            {
                                                  printf("\nhour should be(00 to 24) : ");
                                                  scanf("%d",&p1[inc].t1.hour);               //reenter time
                                                  
                            }
                            if(p1[inc].t1.min>60)                     //condition if time is greater than 60
                            {
                                                 printf("\nMinute should be (00 to 60)");
                                                 scanf("%d",&p1[inc].t1.min);					//re enter time
                                                 }
                            printf("\nEnter the number of tickets :");
                            scanf("%d",&p1[inc].n_tickets);                         //getting number of tickets as input
                            printf("\n\n\t\t\tEND OF GETTING DEATAIL..........");
                            
                            if(p1[inc].n_tickets<=32 && u<32)                 //condition for checking seats less than 32
                            {
                               for(int d=0;d<p1[inc].n_tickets;d++)
                               { 
                                 sum[u]=s+1;                            //reserving tickets
                                 s++;                                  //increment seats
                                 printf("\n your ticket number is :%d",sum[u]);          //displaying tickets number
                                 u++;  
                                                
                               }
                            
                            }
                            else
                            {
                                printf("\n\nsorry all seats are reserved ");           //if seats are full
                            }
                            inc++;                       //increment customers number
                
}

void modify_reservation()                   //function for modifyng reservation
{
     printf("\n\n*******You are in a mode to modify your ticket your ticket********\n");
     char s_name[20];
	 int s_id;    
	 printf("enter name to modify your reservation :");
	 scanf("%s",s_name);                 //array for name for searching data
	 fflush(stdin);
     printf("Enter the id to modify your reservation ");
     scanf("%d",&s_id);                  //taking name as input for searching data
     for(int i=0;i<inc;i++)
     {
     //	printf("%s", s_name);
     //	printf("\n%s",p1[i].n_pas);
     //	getche();
                       if(strcmp(s_name,p1[i].n_pas)==0)              //comparing the entered name and the stored data
                       
                       {
                       	for(int t=0;t<inc;t++)
                       	{
                       	if(s_id==p1[t].idd)
                           {
                           
                                           printf("\nEnter name of passenger :");
                                           scanf("%s",&p1[t].n_pas);  
							               printf("enter id of the passenger");
							               scanf("%d",&p1[t].idd);                                                  //re entering the whole data of the customer
                                           printf("\nEnter the name of departure city :");
                                           scanf("%s",&p1[t].dep_city);
                                           printf("\nEnter the name of destination city :");
                                           scanf("%s",&p1[t].des_city);
                                           printf("\n\n\nEnter date of travel : (day-month-year)");//getting date as input
                                           printf("\nEnter day:");
                                           scanf("%d",&p1[t].d1.day);
                                           if(p1[t].d1.day>31);
                                           {
                            	           printf("\n Day should be  from 1 to 31  :");
                            	           scanf("%d",&p1[t].d1.day);
                                           }
                                           printf("\nEnter month :");
                                           scanf("%d",&p1[t].d1.month);
                                           printf("\n Enter year:");
                                           scanf("%d",&p1[t].d1.year);    
                                           printf("\nEnter time of travel : (hour(00 to 24)-min(00 to 60))");
                                           scanf("%d  %d",&p1[t].t1.hour,&p1[t].t1.min);
                                           if(p1[t].t1.hour>24)
                                           {
                                                  printf("\nhour shuold be(00 to 24) : ");
                                                  scanf("%d",&p1[t].t1.hour);
                                                                         
                                           }
                                           if(p1[t].t1.min>60)
                                           {
                                                 printf("\nMinute should be (00 to 60)");
                                                 scanf("%d",&p1[t].t1.min);
                                           }
                                           printf("\nEnter the number of tickets :");
                                           scanf("%d",&p1[t].n_tickets);
                                           printf("\n\t\t\tEND OF GETTING DEATAIL..........");
                            
                            if(p1[i].n_tickets<=32 && u<32)
                            {
                               for(int d=0;d<p1[i].n_tickets;d++)
                               { 
                                 sum[u]=s+1;
                                 s++;
                                 printf("\n....%d",sum[u]);
                                 u++;  
                                                       
                               }
                               
                            
                            }
                        }
       /*                     else
                            {
                            	printf("id  noit matched");
                            //	break;
                            }*/
                        }
                    }
                            /*else
                            {
                            	printf("names are not matched");
                           0 //	break;
                            }
                            */
                  
                            
                              
                           
                           
                       
    
     
     
     
 }
 inc++;

}

void cancel_reservation()                            //function for cancel a reservation
     {
     

        printf("\n\n***********You are in a mode to cancel your reservation**********\n");
     	char s_name1[20];
     	int id1;
     	fflush(stdin);
		printf("enter the name :");
		scanf("%s",s_name1);
		fflush(stdin);
		printf("Enter the id of the passenger ");
     	fflush(stdin);                                  
		scanf("%d",&id1);
		struct info p2={"","","",0,0,{0,0,0},{0,0}};            //null variable is initialized with info data type
		for(int t=0;t<inc;t++)
	    {
		
		    if(strcmp(s_name1,p1[t].n_pas)==0)
		    {    
		       for(int y=0;y<inc;y++)                 
                {
		           if(id1==p1[y].idd)
   	               {
		 		      p1[y]=p2; 
	               }                               //record is initialized zero or null
		 	
		/*else
		 	{
		 		printf("id are not matched");
		 		break;
		 	}*/
		
		        }
	          }
	/*	else
		{
		 printf("names are not matched");
		 break;
	    }*/
		 	
	}
	
		 }
void search_name()                            //function for searching data by name
     {
     printf("\n\n*******You are in a mode to search your ticket by NAME*******\n");
     	char search[20];                          //array declared for searching name
		 printf("Enter name of passenger:");
		 fflush(stdin);
		 gets(search);                           //taking name as input
		 for (int i=0;i<inc;i++)
		 {
		 	if (strcmp(search,p1[i].n_pas)==0)           //comparing both names
		 	{
		 	printf("\nName of passenger :");
                            puts(p1[i].n_pas);
                            printf("\ndeparture city :");
                            puts(p1[i].dep_city);
                            printf("\ndestination city :");
                            puts(p1[i].des_city);
                            printf("\n\n\ndate of travel : (day-month-year)");                         //diplaying the whole data or stored record of the customer
                            printf("%d  %d  %d",p1[i].d1.day,p1[i].d1.month,p1[i].d1.year);
                            printf("\ntime of travel : (hour(00 to 24)-min(00 to 60))");
                            printf("%d  %d",p1[i].t1.hour,p1[i].t1.min);
                            printf("\nnumber of tickets :");
                            printf("%d",p1[i].n_tickets);
		 	}
		 }
     }
     
void search_date()                        //function for searching data by date
{
    printf("\n\n*******You are in a mode to search your ticket by DATE******\n");
	int dayy,monthh,yearr;
	printf("\nEnter day: ");
	scanf("%d",&dayy);
	printf("\nEnter month: ");
	scanf("%d",&monthh);
	printf("\nEnter year: ");             //taking day,month ,year as input to search
	scanf("%d",&yearr);
	for (int i=0;i<inc;i++)
	{
	if (p1[i].d1.day==dayy && p1[i].d1.month==monthh && p1[i].d1.year==yearr)                    //comparing  dates
	{
							printf("\nName of passenger :");
                            puts(p1[i].n_pas);
                            printf("\ndeparture city :");
                            puts(p1[i].dep_city);
                            printf("\ndestination city :");
                            puts(p1[i].des_city);                                            //if record found whole data will be displayed
                            printf("\n\n\ndate of travel : (day-month-year)");
                            printf("%d  %d  %d",p1[i].d1.day,p1[i].d1.month,p1[i].d1.year);
                            printf("\ntime of travel : (hour(00 to 24)-min(00 to 60))");
                            printf("%d  %d",p1[i].t1.hour,p1[i].t1.min);
                            printf("\nnumber of tickets :");
                            printf("%d",p1[i].n_tickets);
	}
	}
}
