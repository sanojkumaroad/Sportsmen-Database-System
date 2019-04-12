#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
														//FILE POINTERS
FILE *fptr;
FILE *ptr;

													//User Defined Functions
void addc(int);												//ADDITION
void del(FILE *, FILE *);									//DELETION
void ser(FILE *, int);										//SEARCHING
void mod(FILE *, int);										//MODIFICATION
void display(FILE *, int);									//LIST ALL

struct player 											//DETAILS STRUCTURE
{
	char name[30];
	char dyear[5];
	char matches[5], truns[9];
	char avg[5], srate[5];
	char f50s[5], c100s[5], bestsc[5];
}n;

int choice;												//GAME CHOICE
int ch1; 												//FEATURES CHOICE

int main()
{
	start:
	printf("\t\t    ===WELCOME TO SPORTSMEN DATABASE SYSTEM===\n");
	printf("\n\t----------------SELECT ANY GAME FROM THE FOLLOWING----------------\n");
	printf("\t\t1.Cricket\t 2.Football\t 3.Baseball\t 0.EXIT\n\n\t\t\tChoose any Options no. : ");
	scanf("%d", &choice);

	if(choice==0)
		exit(0);

	switch(choice)																	//SWITCH FOR GAME CHOICE
	{
		case 1:																				//CRICKET
		{
			cricket:
			system("cls");
			printf("\t\t\tWELCOME TO CRICKET SECTION\n\t       __________________________________________");
			printf("\n\t\t\tCRICKET DATABASE SECTION\n\t\t  ====================================");
			int ch1;
			printf("\n\n\t\t\t1.Add a Player Record\n\n\t\t\t2.Delete a Player Record\n\n\t\t\t3.Search a Player Record\n\n\t\t\t4.Modify Player Record");
			printf("\n\n\t\t\t5.View all Players Record\n\nEnter your Choice no. or Enter 0 to Exit from Cricket Section: ");
			scanf("%d", &ch1);

			if(ch1==0)
			{
				system("cls");
				goto start;
			}

			switch (ch1)
			{
				case 1:																	//Add a Player(CRICKET)
				{
					do
					{
						addc(choice);

					}while(getche()=='y');

					goto cricket;
	   			}

				case 2:		//Delete a Player (CRICKET)
	  			{
					do
	   				{
	   					fflush(stdin);
						fptr=fopen("rec_CRIC.dat","rb");
						ptr=fopen("temp.dat","wb");
	   					del(fptr,ptr);
	   					remove("rec_CRIC.dat");
	   					rename("temp.dat","rec_CRIC.dat");
	   					printf("\n\n\t\tDelete Another Record from CRICKET SECTION (y/n?)");
	  				}
	  				while(getche()=='y');

					goto cricket;
				}

				case 3:		//SEARCH a Player (CRICKET)
				{
					do
					{
						fptr=fopen("rec_CRIC.dat","rb");
						ser(fptr, choice);
					}while(getche()=='y');
					goto cricket;
				}
				case 4: 	//MODIFY PLAYER
				{

					do
	   				{
	   					fptr=fopen("rec_CRIC.dat","rb+");
	    				mod(fptr,choice);
	    				fclose(fptr);
	 				}
					while(getche()=='y');
					system("cls");
	 				goto cricket;
				}

				case 5:
				{
					system("cls");
					printf("\n\t\t\t  Records of CRICKET SECTION\n");
	 				printf("\t       ==================================================\n");
	 				fptr=fopen("rec_CRIC.dat","rb");
	  				if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
	   				{
	   					printf("\t\t\t\tNO RECORDS SAVED");
	   					getch();
	   					system("cls");
	   					goto cricket;
					}
	  				else
	   				{
	   					rewind(fptr);
	   					display(fptr, choice);
	   					fclose(fptr);
	   				}
	   				printf("\n\n\t\t\tALL RECORDS DISPLAYED SUCESSFULLY\n\t\t\t\tPRESS ANY KEY TO EXIT");
					getch();
					goto cricket;
				}
				default:
				{
					printf("\n\tSorry, \"%d\" is not in the choice list, Please Try Again!\n", ch1);
					printf("\t\t\tPress any Key to Continue ");
					getch();
					system("cls");
					goto cricket;
				}
			}
		}

		case 2:			//FOOTBALL
		{
			football:
			system("cls");
			printf("\t\t\tWELCOME TO FOOTBALL SECTION\n\t\t  _____________________________________");
			printf("\n\t\t\tFOOTBALL DATABASE SECTION\n\t\t     ===============================");
			printf("\n\n\t\t\t1.Add a Player Record\n\n\t\t\t2.Delete a Player Record\n\n\t\t\t3.Search a Player Record\n\n\t\t\t4.Modify Player Record");
			printf("\n\n\t\t\t5.View all Players Record\n\nEnter your Choice no. or Enter 0 to Exit from Football Section: ");
			scanf("%d", &ch1);

			if(ch1==0)
			{
				system("cls");
				goto start;
			}

			switch (ch1)
			{
				case 1:			//Add a Player(FOOTBALL)
				{
					do
					{
						addc(choice); //FUNCTION CALL

					}while(getche()=='y');

					system("cls");
					goto football;
	   			}

				case 2:			//Delete a Player (FOOTBALL)
	  			{
					do
	   				{
	   					fptr=fopen("rec_FOOT.dat","rb");
	   					ptr=fopen("temp.dat","wb");

	  					del(fptr,ptr); //FUNCTION CALL

						remove("rec_FOOT.dat");
	   					rename("temp.dat","rec_FOOT.dat");
	   					printf("\n\n\t\tDelete Another Record from FOOTBALL SECTION (y/n?)");
	   				}
					while(getche()=='y');

					  system("cls");
					goto football;
				}

				case 3:			//SEARCH a Player (FOOTBALL)
				{
					do
					{
						fptr=fopen("rec_FOOT.dat", "rb");
						ser(fptr,choice);

					}while(getche()=='y');

					system("cls");
					goto football;
				}

				case 4:			//MODIFY a Player (FOOTBALL)
				{
					do
	   				{
	   					fptr=fopen("rec_FOOT.dat","rb+");
	  					mod(fptr,choice);
	  					fclose(fptr);
	    				printf("\n\t\t\tPRESS y TO MODIFY ANOTHER");
	 				}
					while(getche()=='y');

					system("cls");
	 				goto football;
				}
				case 5:			//LIST ALL Player (FOOTBALL)
				{
					system("cls");
					printf("\n\t\t\t  Records of FOOTBALL SECTION");
	 				printf("\n\t     ===============================================\n");
	 				fptr=fopen("rec_FOOT.dat","rb");
	  				if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
	   				{
	   					printf("\t\t\t\tNO RECORDS SAVED");
						getch();
	   					system("cls");
	   					goto football;
					}
	  				else
	   				{
	   				rewind(fptr);
	   				display(fptr,choice);
					getch();
	   				fclose(fptr);
	   				}
	   				printf("\n\n\t\t\tALL RECORDS DISPLAYED SUCESSFULLY\n\t\t\t\tPRESS ANY KEY TO EXIT");
	   				getch();
					goto football;
				}
				default:
				{
					printf("\n\tSorry, \"%d\" is not in the choice list, Please Try Again!\n", ch1);
					printf("\t\t\tPress any Key to Continue ");
					getch();
					system("cls");
					goto football;
				}
			}
		}

		case 3:				//BASEBALL
			{
				system("cls");
				printf("\t\t\tWELCOME TO BASEBALL SECTION\n\t\t_______________________________________");
				baseball:
				printf("\n\t\t\tBASEBALL DATABASE SECTION\n\t\t  ==================================");
				printf("\n\n\t\t\t1.Add a Player Record\n\n\t\t\t2.Delete a Player Record\n\n\t\t\t3.Search a Player Record\n\n\t\t\t4.Modify Player Record");
				printf("\n\n\t\t\t5.View all Players Record\n\n\tEnter your Choice no. or Enter 0 to Exit from Baseball Section: ");
				scanf("%d", &ch1);

				if(ch1==0)
				{
					system("cls");
					goto start;
				}

				switch(ch1)
				{
					case 1:		//ADD A PLAYER (BASEBALL)
					{
						do
						{
							addc(choice); //FUNCTION CALL
						}
						while(getche()=='y');

						system("cls");
						goto baseball;
					}

					case 2:		//DELETE A PLAYER (BASEBALL)
					{
						do
						{
							fptr=fopen("rec_BASE.dat","rb");
	   						ptr=fopen("temp.dat","wb");
							del(fptr,ptr); 									//FUNCTION CALL
							remove("rec_BASE.dat");
							rename("temp.dat","rec_BASE.dat");
							printf("\n\n\t\tDelete Another Record from BASEBALL SECTION (y/n?)");
						}
						while(getche()=='y');

						system("cls");
						goto baseball;
					}

					case 3:		//SEARCH A PLAYER (BASEBALL)
					{
						do
						{
							fptr=fopen("rec_BASE.dat", "rb");
							ser(fptr,choice);
						}while(getche()=='y');

						system("cls");
						goto baseball;
					}
					case 4:		//MODIFY A PLAYER (BASEBALL)
					{
						do
	   					{
	   						fptr=fopen("rec_BASE.dat","rb+");
	  						mod(fptr,choice);
	  						fclose(fptr);
	    					printf("\n\tModify More Records in the BASEBALL SECTION (y/n)?");
	 					}
						while(getche()=='y');

						system("cls");
	 					goto baseball;
					}

					case 5:
					{
						system("cls");
						printf("\n\t\t\t  Records of BASEBALL SECTION\n");
	 					printf("\t    ==================================================\n");
	 					fptr=fopen("rec_BASE.dat","rb");
	  					if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
	   					{
	   						printf("\t\t\t\tNO RECORDS SAVED");
	   						getch();
	   						system("cls");
	   						goto baseball;
						}
	  					else
	   					{
	   						rewind(fptr);
	   						display(fptr,choice);
							getch();
	   						fclose(fptr);
	   					}
	   					printf("\n\n\t\t\tALL RECORDS DISPLAYED SUCESSFULLY\n\t\t\t\tPRESS ANY KEY TO EXIT");
	   					getch();
						system("cls");
						goto baseball;
					}
					default:
					{
						printf("\n\tSorry, \"%d\" is not in the choice list, Please Try Again!\n", ch1);
						printf("\t\tPress any Key to Continue ");
						getch();
						system("cls");
						goto baseball;
					}
				}
			}

		default:
			{
				printf("\n\tSorry, \"%d\" is not in the choice list, Please Try Again!\n", choice);
				printf("\t\t\tPress any Key to Continue ");
				getch();
				system("cls");
				goto start;
			}
	}
}

void addc(int choice)
{
	if(choice==1)	//CRICKET
	{
		fptr=fopen("rec_CRIC.dat","ab");
		if(fptr==NULL)
			printf("\nERROR! File Can't Open!\n");
		else
		{
			printf("\n\t\t\tEnter Player Name: \t");
			fflush(stdin);
			gets(n.name);
			printf("\n\t\t\tEnter Debut Year:  \t");
			gets(n.dyear);
			printf("\n\t\t\tNo. of Matches Played:  ");
			gets(n.matches);
			printf("\n\t\t\tTotal Runs:\t\t");
			gets(n.truns);
			printf("\n\t\t\tAverage: \t\t");
			gets(n.avg);
			printf("\n\t\t\tStrike Rate:\t\t");
			gets(n.srate);
			printf("\n\t\t\tNo. of 50's:\t\t");
			gets(n.f50s);
			printf("\n\t\t\tNo. of Centuries:\t");
			gets(n.c100s);;
			printf("\n\t\t\tBest Score: \t\t");
			gets(n.bestsc);
			fwrite(&n, sizeof(n),1,fptr);
			fclose(fptr);
			printf("\n\n\tAdd Another Record in CRICKET SECTION (y/n?)");
		}
	}
	else if(choice==2)	//FOOTBALL
	{
		fptr=fopen("rec_FOOT.dat","ab");
		if(fptr==NULL)
			printf("\nERROR! File Can't Open!\n");
		else
		{
			printf("\n\t\t\tEnter Player Name: \t");
			fflush(stdin);
			gets(n.name);
			printf("\n\t\t\tEnter Player Age: \t");
			gets(n.avg);
			printf("\n\t\t\tMatch Played: \t\t");
			gets(n.matches);
			printf("\n\t\t\tGoals: \t\t\t");
			gets(n.truns);
			printf("\n\t\t\tRight Foot Goals: \t");
			gets(n.c100s);
			printf("\n\t\t\tLeft Foot Goals: \t");
			gets(n.f50s);
			printf("\n\t\t\tHead Goals:\t\t");
			gets(n.srate);
			printf("\n\t\t\tBest: \t\t\t");
			gets(n.bestsc);
			fwrite(&n,sizeof(n),1,fptr);
			fclose(fptr);
			printf("\n\t\tAdd Another Record in FOOTBALL SECTION (y/n?)");
		}
	}
	else if(choice==3)	//BASEBALL
	{
		fptr=fopen("rec_BASE.dat","ab");
		if(fptr==NULL)
			printf("\n\t\t\t\t\tFile Unable to Open!");
		else
		{
			printf("\n\t\t\tPLAYER ID#: \t\t");
			fflush(stdin);
			gets(n.avg);
			printf("\n\t\t\tPLAYER NAME: \t\t");
			gets(n.name);
			printf("\n\t\t\tHEIGHT (in inches): \t");
			gets(n.c100s);
			printf("\n\t\t\tWEIGHT (in kg):    \t");
			gets(n.f50s);
			printf("\n\t\t\tHITS:  \t\t\t");
			gets(n.truns);
			printf("\n\t\t\tWALKS:  \t\t");
			gets(n.matches);
			printf("\n\t\t\tSTRIKEOUTS:     \t");
			gets(n.srate);
			printf("\n\t\t\tAVERAGE:       \t\t");
			gets(n.bestsc);
			fwrite(&n,sizeof(n),1,fptr);
			fclose(fptr);
			printf("\n\n\t\tAdd Another Record in FOOTBALL SECTION (y/n?)");
		}
	}

}

void del(FILE *rec, FILE *temp) //DELETE A PLAYER
{
	char name[50];
	if((rec==NULL)||(fread(&n,sizeof(rec),1,rec)==0))
	{
		printf("\n\t\t\tNo Records Available in This Section ");
	}
	else
	{
		rewind(rec);
		printf("\n\n\t\tEnter the name of player to be deleted: ");
	    fflush(stdin);
	    gets(name);

	   	while(fread(&n,sizeof(n),1,rec)==1)
 		{
 			if((strcmpi(n.name,name))!=0)
  				fwrite(&n,sizeof(n),1,temp);
 			else
 			{
 				printf("\n\t\t\tRecord deleted successfully");
			}
  		}
	    fclose(rec);
	    fclose(temp);
	}
}

void ser(FILE *rec, int choice)
{
	char name[50];
	printf("\n\t\t\tEnter Player Name: ");
	fflush(stdin);
	gets(name);
	if(choice==1)
	{
		while(fread(&n,sizeof(n),1,rec)==1)
 		{
  			if((strcmpi(name,n.name))==0)
  			{
   				printf("\n\n\t\t\tName: \t\t\t%s\n\t\t\tDebut Year:    \t\t%s\n\t\t\tNo. of Matches Played:  %s\n\t\t\tTotal Runs:   \t\t%s\n\t\t\tAverage:   \t\t%s",n.name,n.dyear,n.matches,n.truns,n.avg);
   				printf("\n\t\t\tStrike Rate:   \t\t%s\n\t\t\tNo. of 50's:   \t\t%s\n\t\t\tNo. of Centuries:   \t%s\n\t\t\tBest Score:   \t\t%s",n.srate, n.f50s, n.c100s, n.bestsc);
				break;
 			}
 		}
 		if((strcmpi(name,n.name))!=0)
 		printf("\n\t\t\tSORRY RECORD NOT FOUND");
		printf("\n\t\t\tPRESS y TO SEARCH AGAIN");
		fclose(rec);
	}
	else if(choice==2)
	{
		while(fread(&n,sizeof(n),1,rec)==1)
 		{
  			if((strcmpi(name,n.name))==0){
   			printf("\n\t\t\t\tName:      \t  %s\n\t\t\t\tAge:      \t  %s\n\t\t\t\tMatches:      \t  %s\n\t\t\t\tTotal Goals:      %s\n\t\t\t\tRight Foot Goals: %s",n.name,n.avg,n.matches,n.truns, n.c100s);
   			printf("\n\t\t\t\tLeft Foot Goals:  %s\n\t\t\t\tHead Goals:       %s\n\t\t\t\tBest:     \t  %s", n.f50s, n.srate, n.bestsc);
			break;}
 		}
 		if((strcmpi(name,n.name))!=0)
 		printf("\n\t\t\tSORRY RECORD NOT FOUND");
		printf("\n\t\t\tPRESS y TO SEARCH AGAIN");
		fclose(rec);
	}
	else if(choice==3)
	{
		while(fread(&n,sizeof(n),1,rec)==1)
 		{
  			if((strcmpi(name,n.name))==0){
   			printf("\n\t\t\tPLAYER ID#: \t\t%s\n\t\t\tPLAYER NAME: \t\t%s\n\t\t\tHEIGHT: \t\t%s\n\t\t\tWEIGHT:    \t\t%s\n\t\t\tHITS:  \t\t\t%s",n.avg,n.name,n.c100s,n.f50s, n.truns);
   			printf("\n\t\t\tWALKS: \t\t\t%s\n\t\t\tSTRIKEOUTS: \t\t%s\n\t\t\tAVERAGE: \t\t%s", n.matches, n.srate, n.bestsc);
			break;}
 		}
 		if((strcmpi(name,n.name))!=0)
 		printf("\n\t\t\tSORRY RECORD NOT FOUND");
		printf("\n\t\t\tPRESS y TO SEARCH AGAIN");
		fclose(rec);
	}
}

void mod(FILE *fptr, int choice)
{
	int test=0;
	long int offset=sizeof(n);
	char name[50];

	if(choice==1)
	{
		if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
		{
			printf("\n\t\t\tNO RECORD AVAILABLE");
			test=1;
		}
		else
		{
	 		rewind(fptr);
	   		printf("\n\n\t\tEnter the Palyer Name to Modify: ");
	   		fflush(stdin);
	   		gets(name);
			while(fread(&n,sizeof(n),1,fptr)==1)
 			{
  				if((strcmpi(n.name,name))==0)
  				{
   					printf("\n\n\t\t\tEnter New Name: \t");
   					gets(n.name);
   					printf("\n\t\t\tEnter Debut Year: \t");
					gets(n.dyear);
					printf("\n\t\t\tMatches Played: \t");
					gets(n.matches);
					printf("\n\t\t\tTotal Runs: \t\t");
					gets(n.truns);
					printf("\n\t\t\tAverage: \t\t");
					gets(n.avg);
					printf("\n\t\t\tStrike Rate: \t\t");
					gets(n.srate);
					printf("\n\t\t\tNo. of 50's: \t\t");
					gets(n.f50s);
					printf("\n\t\t\tNo. of Centuries: \t");
					gets(n.c100s);
					printf("\n\t\t\tBest Score: \t\t");
					gets(n.bestsc);
					fseek(fptr,-offset,SEEK_CUR);
					fwrite(&n,sizeof(n),1,fptr);
					test=2;
					break;
  				}
 			}
 			if(test==0)
				printf("\n\t\t\tSORRY RECORD NOT FOUND");
 			printf("\n\t\t\tPRESS y TO MODIFY ANOTHER");
 		}
	}
	else if(choice==2)
	{
		if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
	   		{
	   			printf("\n\t\t\tNO RECORD AVAILABLE");
	   			test=1;
			}
	   	else
	   	{
		   	rewind(fptr);
	   		printf("\n\n\t\tEnter the Palyer Name to Modify: ");
	   		fflush(stdin);
	   		gets(name);
	    }
		while(fread(&n,sizeof(n),1,fptr)==1)
 		{
  			if((strcmpi(n.name,name))==0)
  			{
   			printf("\n\t\t\tEnter Player New Name: \t");
			fflush(stdin);
			gets(n.name);
			printf("\n\t\t\tEnter Player Age: \t");
			gets(n.avg);
			printf("\n\t\t\tNo. of Match Played: \t");
			gets(n.matches);
			printf("\n\t\t\tGoals: \t\t\t");
			gets(n.truns);
			printf("\n\t\t\tRight Foot Goals: \t");
			gets(n.c100s);
			printf("\n\t\t\tLeft Foot Goals: \t");
			gets(n.f50s);
			printf("\n\t\t\tHead Goals: \t\t");
			gets(n.srate);
			printf("\n\t\t\tBest: \t\t\t");
			gets(n.bestsc);
			fseek(fptr,-offset,SEEK_CUR);
			fwrite(&n,sizeof(n),1,fptr);
			test=2;
			break;
  			}
 		}
 		if(test==0)
 		printf("\n\t\t\tSORRY RECORD NOT FOUND");
	}
	else if(choice==3)
	{
		if((fptr==NULL)||(fread(&n,sizeof(n),1,fptr)==0))
	   		{
	   			printf("\n\t\t\tNO RECORD AVAILABLE");
	   			test=1;
			}
	   	else
	   	{
		   	rewind(fptr);
	   		printf("\n\n\t\tEnter the Palyer Name to Modify: ");
	   		fflush(stdin);
	   		gets(name);
	    
			while(fread(&n,sizeof(n),1,fptr)==1)
 			{
  				if((strcmpi(n.name,name))==0)
  				{
   				printf("\n\t\t\tENTER NEW NAME: \t");
				fflush(stdin);
				gets(n.name);
				printf("\n\t\t\tPLAYER ID#: \t\t");
				fflush(stdin);
				gets(n.avg);
				printf("\n\t\t\tHEIGHT (in inches): \t");
				gets(n.c100s);
				printf("\n\t\t\tWEIGHT (in kg): \t");
				gets(n.f50s);
				printf("\n\t\t\tHITS: \t\t\t");
				gets(n.truns);
				printf("\n\t\t\tWALKS: \t\t\t");
				gets(n.matches);
				printf("\n\t\t\tSTRIKEOUTS: \t\t");
				gets(n.srate);
				printf("\n\t\t\tAVERAGE: \t\t");
				gets(n.bestsc);
				fseek(fptr,-offset,SEEK_CUR);
				fwrite(&n,sizeof(n),1,fptr);
				test=2;
				break;
				}
			}
			if(test==0)
 				printf("\n\t\t\tSORRY RECORD NOT FOUND");
		}
	}
}

void display(FILE *fptr, int choice)
{
	if(choice==2)
	{
		fflush(stdin);
		while(fread(&n,sizeof(n),1,fptr)==1)
 		{
  		printf("\n\t\t\tName: \t\t  %s\n\t\t\tAge: \t\t  %s\n\t\t\tMatches Played:   %s\n\t\t\tTotal Goals:\t  %s\n\t\t\tRight Hand Goals: %s",n.name,n.avg,n.matches,n.truns,n.c100s);
  		printf("\n\t\t\tLeft Hand Goals:  %s\n\t\t\tHead Goals:       %s\n\t\t\tBest Score:       %s\n   \t\tPress any key to move to Next Record...", n.f50s, n.srate, n.bestsc);
		getch();
 		}
	}
	else if(choice==1)
	{
		fflush(stdin);
		while(fread(&n,sizeof(n),1,fptr)==1)
 		{
  		printf("\n\t\t\tName: \t\t\t%s\n\t\t\tDebut Year: \t\t%s\n\t\t\tMatches: \t\t%s\n\t\t\tTotal Runs: \t\t%s\n\t\t\tAverage: \t\t%s",n.name,n.dyear,n.matches,n.truns,n.avg,n.srate);
  		printf("\n\t\t\tStrike Rate: \t\t%s\n\t\t\tNo. of 50's: \t\t%s\n\t\t\tNo. of Centuries: \t%s\n\t\t\tBest Score: \t\t%s\n   \t\t\tPress any key to move to Next Record...", n.srate, n.f50s, n.c100s, n.bestsc);
		getch();
 		}
	}
	else if(choice==3)
	{
		fflush(stdin);
		while(fread(&n,sizeof(n),1,fptr)==1)
 		{
  		printf("\n\t\t\tPLAYER ID#: \t\t%s\n\t\t\tPLAYER NAME: \t\t%s\n\t\t\tHEIGHT(in inches): \t%s\n\t\t\tWEIGHT (in kg): \t%s\n\t\t\tHITS: \t\t\t%s",n.avg,n.name,n.c100s,n.f50s,n.truns);
  		printf("\n\t\t\tWALKS: \t\t\t%s\n\t\t\tSTRIKEOUTS: \t\t%s\n\t\t\tAVERAGE: \t\t%s\n   \t\tPress any key to move to Next Record...", n.matches, n.srate, n.bestsc);
		getch();
 		}
	}
}
