#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int respect = 40;

void help();

int main(void)
{
	struct creature{
		int type;
		int location;
	};

	struct room{
		int north;
		int south;
		int east;
		int west;
		int state;
		int creatures;
	};
	//GET NUMBER OF ROOMS
	int roomnum = 0;
	printf("\nEnter the number of ROOMS: ");
	scanf("%d",&roomnum);
	struct room *r = malloc(sizeof(struct room)*roomnum);

	//GET ROOM DETAILS AND MAKE ROOMS
	printf("Enter ROOMS - [State (0 = clean, 1 = half-dirty, 2 = dirty),\n");
	printf("              North, South, East, West (Neighboring room # 0 through %d, -1 = no neighbor]:\n",roomnum-1);
	
	char *str;
	char *ptr;
	long ret1;
	int ret2;
	char rooms[20];
	int x=0;
	for(;x<roomnum;x++)
	{
		//GET ROOM INFO
		scanf(" %[^\n]s",rooms);

		//SEPARATE FIRST STR #
		str = strtok (rooms," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET ROOM STATE
		ret2=(int)ret1;
		r[x].state=ret2;

		//SEPARATE SECOND STR #
		str = strtok (NULL," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET ROOM NORTH
		ret2=(int)ret1;
		r[x].north=ret2;

		//SEPARATE THIRD STR #
		str = strtok (NULL," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET ROOM SOUTH
		ret2=(int)ret1;
		r[x].south=ret2;

		//SEPARATE FOURTH STR #
		str = strtok (NULL," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET ROOM EAST
		ret2=(int)ret1;
		r[x].east=ret2;

		//SEPARATE FIFTH STR #
		str = strtok (NULL," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET ROOM WEST
		ret2=(int)ret1;
		r[x].west=ret2;

		//SET NUMBER OF CREATURES
		r[x].creatures=0;

		memset(rooms, 0, sizeof(rooms));
	}
	//GET NUMBER OF CREATURES
	int creaturenum = 0;
	printf("\nEnter the number of creatures: ");
	scanf("%d",&creaturenum);
	struct creature *c = malloc(sizeof(struct creature)*creaturenum);

	//GET CREATURE DETAILS AND MAKE CREATURES
	printf("Enter creatures - [Type (0 = PC, 1 = animal, 2 = NPC), Location (Room # 0 through %d)]:\n",roomnum-1);
	char creatures[20];
	int playerroom;

	for(x=0;x<creaturenum;x++)
	{
		//GET CREATURE INFO
		scanf(" %[^\n]s",creatures);

		//SEPARATE FIRST STR #
		str = strtok (creatures," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//SET CREATURE TYPE
		ret2=(int)ret1;
		c[x].type=ret2;

		//SEPARATE SECOND STR #
		str = strtok (NULL," ");
		//CONVERT STR TO LONG
		ret1=strtol(str,&ptr,10);
		//CREATURE LOCATION
		ret2=(int)ret1;
		c[x].location=ret2;
		
		//ADD CREATURES TO THE ROOM
		r[ret2].creatures++;

		if(c[x].type==0)
			playerroom=ret2;
		memset(creatures, 0, sizeof(creatures));
	}

	help();

	//START OF GAME

	char move[20];
	printf("First move: ");
	scanf("%s",move);

	while((strncmp(move,"Exit",5)!=0)&&(strncmp(move,"exit",5)!=0)&&(respect>0)&&(respect<80))
	{
		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//Creature Controls
		//*****************
		if((isdigit(move[0]))&&((move[1]==':')||((isdigit(move[1]))&&(move[2]==':'))))
		{
			int cname = 0;
			str = strtok (move,":");
                	//CONVERT STR TO LONG
                	ret1=strtol(str,&ptr,10);
                	//SET CNAME
                	ret2=(int)ret1;
                	cname=ret2;
			str = strtok (NULL,"\n");
			if((strncmp(str,"north",6)==0)||(strncmp(str,"North",6)==0))
			{
				if(r[playerroom].north==-1)
					printf("\nThere is no room to the north!");
				else if(r[r[playerroom].north].creatures>=10)
					printf("\nRoom Full!");
				else
				{
					printf("\n%d leaves towards the north.",cname);
					r[playerroom].creatures--;
					c[cname].location=r[playerroom].north;
					r[r[playerroom].north].creatures++;
					if((c[cname].type==1)&&(r[c[cname].location].state==2))
					{
						r[c[cname].location].state--;
						printf("\n%d cleaned room %d.",cname,c[cname].location);
					}
					if((c[cname].type==2)&&(r[c[cname].location].state==0))
                                        {
                                                r[c[cname].location].state++;
                                                printf("\n%d dirtied room %d.",cname,c[cname].location);
                                        }
				}
			}
	
			else if((strncmp(str,"south",6)==0)||(strncmp(str,"South",6)==0))
        	        {
        	                if(r[playerroom].south==-1)
        	                        printf("\nThere is no room to the south!");
        	                else if(r[r[playerroom].south].creatures>=10)
        	                        printf("\nRoom Full!");
        	                else 
        	                {
					printf("\n%d leaves towards the south.",cname);
        	                        r[playerroom].creatures--;
        	                        c[cname].location=r[playerroom].south;
        	                        r[r[playerroom].south].creatures++;
					if((c[cname].type==1)&&(r[c[cname].location].state==2))
                                        {
                                                r[c[cname].location].state--;
                                                printf("\n%d cleaned room %d.",cname,c[cname].location);
                                        }
                                        if((c[cname].type==2)&&(r[c[cname].location].state==0))
                                        {
                                                r[c[cname].location].state++;
                                                printf("\n%d dirtied room %d.",cname,c[cname].location);
                                        }
        	                }
        	        }
	
			else if((strncmp(str,"east",5)==0)||(strncmp(str,"East",5)==0))
	                {
	                        if(r[playerroom].east==-1)
	                                printf("\nThere is no room to the east!");
	                        else if(r[r[playerroom].east].creatures>=10)
	                                printf("\nRoom Full!");
	                        else 
	                        {
					printf("\n%d leaves towards the east.",cname);
	                                r[playerroom].creatures--;
	                                c[cname].location=r[playerroom].east;
	                                r[r[playerroom].east].creatures++;
					if((c[cname].type==1)&&(r[c[cname].location].state==2))
                                        {
                                                r[c[cname].location].state--;
                                                printf("\n%d cleaned room %d.",cname,c[cname].location);
                                        }
                                        if((c[cname].type==2)&&(r[c[cname].location].state==0))
                                        {
                                                r[c[cname].location].state++;
                                                printf("\n%d dirtied room %d.",cname,c[cname].location);
                                        }
	                        }
	                }
	
			else if((strncmp(str,"west",5)==0)||(strncmp(str,"West",5)==0))
	                {
	                        if(r[playerroom].west==-1)
	                                printf("\nThere is no room to the west!");
	                        else if(r[r[playerroom].west].creatures>=10)
	                                printf("\nRoom Full!");
	                        else 
	                        {
					printf("\n%d leaves towards the west.",cname);
	                                r[playerroom].creatures--;
	                                c[cname].location=r[playerroom].west;
	                                r[r[playerroom].west].creatures++;
	                        	if((c[cname].type==1)&&(r[c[cname].location].state==2))
                                        {
                                                r[c[cname].location].state--;
                                                printf("\n%d cleaned room %d.",cname,c[cname].location);
                                        }
                                        if((c[cname].type==2)&&(r[c[cname].location].state==0))
                                        {
                                                r[c[cname].location].state++;
                                                printf("\n%d dirtied room %d.",cname,c[cname].location);
                                        }
				}
	                }
			//1=ANIMAL
			//2=NPC
			else if((strncmp(str,"clean",6)==0)||(strncmp(str,"Clean",6)==0))
	                {
				if(r[playerroom].state==2)
				{
					printf("\n%d the human grumbles and cleans the room.",cname);
					respect-=2;
					r[playerroom].state--;
					for(x=0;x<creaturenum;x++)
					{
						if((c[x].type==2)&&(c[x].location==playerroom))
						{
							printf("\n%d, the human grumbles in discontent.",x);
							respect--;
						}
					}
				}
				else if(r[playerroom].state==1)
        	                {
        	                        r[playerroom].state--;
					if(c[cname].type==2)
					{
						printf("\n%d the human grumbles and cleans the room.",cname);
                                        	respect-=2;
					}
					if(c[cname].type==1)
                                        {
                                                printf("\n%d the animal licks your face and cleans the room.",cname);
                                                respect+=2;
                                        }
					for(x=0;x<creaturenum;x++)
        	                        {
        	                         	if((c[x].type==1)&&(c[x].location==playerroom))
						{
							printf("\n%d, the Animal licks your face.",x);
        	                                        respect++;
						}
						if((c[x].type==2)&&(c[x].location==playerroom))
        	                                {
        	                                        printf("\n%d, the human grumbles and leaves the room ",x);
        	                                        respect-=3;
							if((r[playerroom].north!=-1)&&(r[r[playerroom].north].creatures<=10))
							{
								printf("to the north.");
								r[playerroom].creatures--;
								c[x].location=r[playerroom].north;
								r[r[playerroom].north].creatures++;
								if(r[r[playerroom].north].state==0)
								{
									r[r[playerroom].north].state++;
									printf("\n%d dirties the room to the north.",x);
								}
							}
							else if((r[playerroom].south!=-1)&&(r[r[playerroom].south].creatures<=10))
        	                                        {
        	                                                printf("to the south.");
        	                                                r[playerroom].creatures--;
        	                                                c[x].location=r[playerroom].south;
        	                                                r[r[playerroom].south].creatures++;
        	                                                if(r[r[playerroom].south].state==0)
        	                                                {
        	                                                        r[r[playerroom].south].state++;
        	                                                        printf("\n%d dirties the room to the south.",x);
        	                                                }
        	                                        }
							else if((r[playerroom].east!=-1)&&(r[r[playerroom].east].creatures<=10))
        	                                        {
        	                                                printf("to the east.");
        	                                                r[playerroom].creatures--;
        	                                                c[x].location=r[playerroom].east;
        	                                                r[r[playerroom].east].creatures++;
        	                                                if(r[r[playerroom].east].state==0)
        	                                                {
        	                                                        r[r[playerroom].east].state++;
        	                                                        printf("\n%d dirties the room to the east.",x);
        	                                                }
        	                                        }
							else if((r[playerroom].west!=-1)&&(r[r[playerroom].west].creatures<=10))
        	                                        {
        	                                                printf("to the west.");
       		                                        	r[playerroom].creatures--;
	                                                        c[x].location=r[playerroom].west;
		                                                r[r[playerroom].west].creatures++;
	                                                        if(r[r[playerroom].west].state==0)
	                                                        {
	                                                                r[r[playerroom].west].state++;
	                                                                printf("\n%d dirties the room to the west.",x);
	                                                        }
	                                                }
							else
							{
								printf("through the roof!");
								c[x].type=-1;
								c[x].location=-1;
								r[playerroom].creatures--;
								respect-=7;
								int y;
								for(y=0;y<creaturenum;y++)
								{
									if(c[y].location==playerroom)
									{
										if(c[y].type==1)
											printf("\nAnimal %d growls at you.",y);
										if(c[y].type==2)
	                                                                                printf("\nHuman %d grumbles.",y);
									}
								}
							}
	                                        }
	                                }	
	                        }
				else
				{
					printf("\nThe room is already clean!");
				}
				printf("\nRespect is now %d after this turn.",respect);
			}
	
			else if((strncmp(str,"dirty",6)==0)||(strncmp(str,"Dirty",6)==0))
	                {
				if(r[playerroom].state==0)
				{
					r[playerroom].state++;
       	                                if(c[cname].type==1)
       	                                {
       	                                        printf("\n%d the animal growls and cleans the room.",cname);
       	                                        respect-=2;
       	                                }
					for(x=0;x<creaturenum;x++)
					{
						if((c[x].type==1)&&(c[x].location==playerroom))
						{
							printf("\n%d, the animal growls in discontent.",x);
							respect--;
						}
					}
				}
				else if(r[playerroom].state==1)
                	        {
                	                r[playerroom].state++;
					if(c[cname].type==2)
                                        {
                                                printf("\n%d the human smiles and cleans the room.",cname);
                                                respect+=2;
	    	                        }
       	 	                        if(c[cname].type==1)
       		                        {
                       	                        printf("\n%d the animal growls and cleans the room.",cname);
                       	                        respect-=2;
                       	                }
					for(x=0;x<creaturenum;x++)
               		                {
               		                 	if((c[x].type==2)&&(c[x].location==playerroom))
						{
							printf("\n%d, the Human smiles at you.",x);
               		                                respect++;
						}
						if((c[x].type==1)&&(c[x].location==playerroom))
               		                        {
               		                                printf("\n%d, the animal growls and leaves the room ",x);
               		                                respect-=2;
							if((r[playerroom].north!=-1)&&(r[r[playerroom].north].creatures<=10))
							{
								printf("to the north.");
								r[playerroom].creatures--;
								c[x].location=r[playerroom].north;
								r[r[playerroom].north].creatures++;
								if(r[r[playerroom].north].state==0)
								{
									r[r[playerroom].north].state++;
									printf("\n%d dirties the room to the north.",x);
								}
							}
							else if((r[playerroom].south!=-1)&&(r[r[playerroom].south].creatures<=10))
               		                                {
               		                                        printf("to the south.");
               		                                        r[playerroom].creatures--;
               		                                        c[x].location=r[playerroom].south;
               		                                        r[r[playerroom].south].creatures++;
               		                                        if(r[r[playerroom].south].state==0)
               		                                        {
               		                                                r[r[playerroom].south].state++;
               		                                                printf("\n%d dirties the room to the south.",x);
               		                                        }
               		                                }
							else if((r[playerroom].east!=-1)&&(r[r[playerroom].east].creatures<=10))
               		                                {
               		                                        printf("to the east.");
               		                                        r[playerroom].creatures--;
               		                                        c[x].location=r[playerroom].east;
               		                                        r[r[playerroom].east].creatures++;
               		                                        if(r[r[playerroom].east].state==0)
               		                                        {
               		                                                r[r[playerroom].east].state++;
               		                                                printf("\n%d dirties the room to the east.",x);
       	        	                                        }
       	        	                                }
							else if((r[playerroom].west!=-1)&&(r[r[playerroom].west].creatures<=10))
       	        	                                {
       	        	                                        printf("to the west.");
       		                                                r[playerroom].creatures--;
       		                                                c[x].location=r[playerroom].west;
	    	                                                r[r[playerroom].west].creatures++;
	    	                                                if(r[r[playerroom].west].state==0)
			                                        {
       	        	                                                r[r[playerroom].west].state++;
       	        	                                                printf("\n%d dirties the room to the west.",x);
       	        	                                        }
       	        	                                }
							else
							{
								printf("through the roof!");
								c[x].type=-1;
								c[x].location=-1;
								r[playerroom].creatures--;
								respect-=3;
								int y;
								for(y=0;y<creaturenum;y++)
								{
									if(c[y].location==playerroom)
									{
										if(c[y].type==1)
											printf("\nAnimal %d growls at you.",y);
										if(c[y].type==2)
	               	                                                                printf("\nHuman %d grumbles.",y);
									}
								}
							}
                	                        }
                	                }	
				}
				else
				{
					printf("\nThe room is already dirty!");
				}
				printf("\nRespect is now %d after this turn.",respect);
               		}
			else
				printf("\nInvalid command, try again.");
		}



		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//******************************************************************************************
		//Human Controls
		//**************
		else if((strncmp(move,"help",5)==0)||(strncmp(move,"Help",5)==0))
                {
			help();
		}

		else if((strncmp(move,"cheat",6)==0)||(strncmp(move,"Cheat",6)==0))
		{
			printf("PLAYERROOM =  %d\n",playerroom);
			printf("# of ROOMS =  %d",roomnum);
			for(x=0;x<roomnum;x++)
			{
        			printf("\nRoom %d STATE =  %d",x,r[x].state);
        			printf("\nRoom %d NORTH =  %d",x,r[x].north);
        			printf("\nRoom %d SOUTH =  %d",x,r[x].south);
        			printf("\nRoom %d EAST  =  %d",x,r[x].east);
        			printf("\nRoom %d WEST  =  %d",x,r[x].west);
        			printf("\nRoom %d POPULATION =  %d\n",x,r[x].creatures);
			}
			printf("\n# of CREATURES =  %d",creaturenum);
			for(x=0;x<creaturenum;x++)
			{				
        			printf("\nCreature %d TYPE = %d",x,c[x].type);
        			printf("\nCreature %d ROOM = %d",x,c[x].location);
			}
		}

		else if((strncmp(move,"look",5)==0)||(strncmp(move,"Look",5)==0))
                {
			printf("Room %d, ",playerroom);
			if(r[playerroom].state==0)
				printf("clean, neighbors ");
			if(r[playerroom].state==1)
                                printf("half-dirty, neighbors ");
			if(r[playerroom].state==2)
                                printf("dirty, neighbors ");
			if(r[playerroom].north!=-1)
				printf("%d to the north, ",r[playerroom].north);
			if(r[playerroom].south!=-1)
                                printf("%d to the south, ",r[playerroom].south);     
			if(r[playerroom].east!=-1)
                                printf("%d to the east, ",r[playerroom].east);     
			if(r[playerroom].west!=-1)
                                printf("%d to the west, ",r[playerroom].west);
			printf("contains:\n");
			for(x=0;x<creaturenum;x++)
			{
				if(c[x].location==playerroom)
				{
					if(c[x].type==1)
						printf("Animal %d\n",x);
					else if(c[x].type==2)
                        printf("Human %d\n",x);
					else
						printf("PC\n");
				}
			}
		}
		
		else if((strncmp(move,"north",6)==0)||(strncmp(move,"North",6)==0))
		{
			if(r[playerroom].north==-1)
				printf("\nThere is no room to the north!");
			else if(r[r[playerroom].north].creatures>=10)
				printf("\nRoom Full!");
			else
			{
				printf("\nYou leave towards the north.");
				r[playerroom].creatures--;
				playerroom=r[playerroom].north;
				r[playerroom].creatures++;
				for(x=0;x<creaturenum;x++)
								{				
        							if(c[x].type==0)
        							{
        								c[x].location=playerroom;
        								break;
        							}
								}
			}
		}

		else if((strncmp(move,"south",6)==0)||(strncmp(move,"South",6)==0))
                {
                        if(r[playerroom].south==-1)
                                printf("\nThere is no room to the south!");
                        else if(r[r[playerroom].south].creatures>=10)
                                printf("\nRoom Full!");
                        else 
                        {
								printf("\nYou leave towards the south.");
                                r[playerroom].creatures--;
                                playerroom=r[playerroom].south;
                                r[playerroom].creatures++;
                                for(x=0;x<creaturenum;x++)
								{				
        							if(c[x].type==0)
        							{
        								c[x].location=playerroom;
        								break;
        							}
								}
                        }
                }

		else if((strncmp(move,"east",5)==0)||(strncmp(move,"East",5)==0))
                {
                        if(r[playerroom].east==-1)
                                printf("\nThere is no room to the east!");
                        else if(r[r[playerroom].east].creatures>=10)
                                printf("\nRoom Full!");
                        else 
                        {
								printf("\nYou leave towards the east.");
                                r[playerroom].creatures--;
                                playerroom=r[playerroom].east;
                                r[playerroom].creatures++;
                                for(x=0;x<creaturenum;x++)
								{				
        							if(c[x].type==0)
        							{
        								c[x].location=playerroom;
        								break;
        							}
								}
                        }
                }

		else if((strncmp(move,"west",5)==0)||(strncmp(move,"West",5)==0))
                {
                        if(r[playerroom].west==-1)
                                printf("\nThere is no room to the west!");
                        else if(r[r[playerroom].west].creatures>=10)
                                printf("\nRoom Full!");
                        else 
                        {
								printf("\nYou leave towards the west.");
                                r[playerroom].creatures--;
                                playerroom=r[playerroom].west;
                                r[playerroom].creatures++;
                                for(x=0;x<creaturenum;x++)
								{				
        							if(c[x].type==0)
        							{
        								c[x].location=playerroom;
        								break;
        							}
								}
                        }
                }
		//1=ANIMAL
		//2=NPC
		else if((strncmp(move,"clean",6)==0)||(strncmp(move,"Clean",6)==0))
                {
			if(r[playerroom].state==2)
			{
				r[playerroom].state--;
				printf("\nYou clean the room, it is now half-dirty.");
				for(x=0;x<creaturenum;x++)
				{
					if((c[x].type==2)&&(c[x].location==playerroom))
					{
						printf("\n%d, the human grumbles in discontent.",x);
						respect--;
					}
				}
			}
			else if(r[playerroom].state==1)
                        {
                                r[playerroom].state--;
				printf("\nYou clean the room, it is now completely clean.");
				for(x=0;x<creaturenum;x++)
                                {
                                 	if((c[x].type==1)&&(c[x].location==playerroom))
					{
						printf("\n%d, the Animal licks your face.",x);
                                                respect++;
					}
					if((c[x].type==2)&&(c[x].location==playerroom))
                                        {
                                                printf("\n%d, the human grumbles and leaves the room ",x);
                                                respect-=3;
						if((r[playerroom].north!=-1)&&(r[r[playerroom].north].creatures<=10))
						{
							printf("to the north.");
							r[playerroom].creatures--;
							c[x].location=r[playerroom].north;
							r[r[playerroom].north].creatures++;
							if(r[r[playerroom].north].state==0)
							{
								r[r[playerroom].north].state++;
								printf("\n%d dirties the room to the north.",x);
							}
						}
						else if((r[playerroom].south!=-1)&&(r[r[playerroom].south].creatures<=10))
                                                {
                                                        printf("to the south.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].south;
                                                        r[r[playerroom].south].creatures++;
                                                        if(r[r[playerroom].south].state==0)
                                                        {
                                                                r[r[playerroom].south].state++;
                                                                printf("\n%d dirties the room to the south.",x);
                                                        }
                                                }
						else if((r[playerroom].east!=-1)&&(r[r[playerroom].east].creatures<=10))
                                                {
                                                        printf("to the east.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].east;
                                                        r[r[playerroom].east].creatures++;
                                                        if(r[r[playerroom].east].state==0)
                                                        {
                                                                r[r[playerroom].east].state++;
                                                                printf("\n%d dirties the room to the east.",x);
                                                        }
                                                }
						else if((r[playerroom].west!=-1)&&(r[r[playerroom].west].creatures<=10))
                                                {
                                                        printf("to the west.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].west;
                                                        r[r[playerroom].west].creatures++;
                                                        if(r[r[playerroom].west].state==0)
                                                        {
                                                                r[r[playerroom].west].state++;
                                                                printf("\n%d dirties the room to the west.",x);
                                                        }
                                                }
						else
						{
							printf("through the roof!");
							c[x].type=-1;
							c[x].location=-1;
							r[playerroom].creatures--;
							respect-=7;
							int y;
							for(y=0;y<creaturenum;y++)
							{
								if(c[y].location==playerroom)
								{
									if(c[y].type==1)
										printf("\nAnimal %d growls at you.",y);
									if(c[y].type==2)
                                                                                printf("\nHuman %d grumbles.",y);
								}
							}
						}
                                        }
                                }	
                        }
			else
			{
				printf("\nThe room is already clean!");
			}
			printf("\nRespect is now %d after this turn.",respect);
		}

		else if((strncmp(move,"dirty",6)==0)||(strncmp(move,"Dirty",6)==0))
                {
			if(r[playerroom].state==0)
			{
				r[playerroom].state++;
				printf("\nYou dirty the room, it is now half-dirty");
				for(x=0;x<creaturenum;x++)
				{
					if((c[x].type==1)&&(c[x].location==playerroom))
					{
						printf("\n%d, the animal growls in discontent.",x);
						respect--;
					}
				}
			}
			else if(r[playerroom].state==1)
                        {
                                r[playerroom].state++;
				printf("\nYou dirty the room, it is now completely dirty.");
				for(x=0;x<creaturenum;x++)
                                {
                                 	if((c[x].type==2)&&(c[x].location==playerroom))
					{
						printf("\n%d, the Human smiles at you.",x);
                                                respect++;
					}
					if((c[x].type==1)&&(c[x].location==playerroom))
                                        {
                                                printf("\n%d, the animal growls and leaves the room ",x);
                                                respect-=2;
						if((r[playerroom].north!=-1)&&(r[r[playerroom].north].creatures<=10))
						{
							printf("to the north.");
							r[playerroom].creatures--;
							c[x].location=r[playerroom].north;
							r[r[playerroom].north].creatures++;
							if(r[r[playerroom].north].state==0)
							{
								r[r[playerroom].north].state++;
								printf("\n%d dirties the room to the north.",x);
							}
						}
						else if((r[playerroom].south!=-1)&&(r[r[playerroom].south].creatures<=10))
                                                {
                                                        printf("to the south.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].south;
                                                        r[r[playerroom].south].creatures++;
                                                        if(r[r[playerroom].south].state==0)
                                                        {
                                                                r[r[playerroom].south].state++;
                                                                printf("\n%d dirties the room to the south.",x);
                                                        }
                                                }
						else if((r[playerroom].east!=-1)&&(r[r[playerroom].east].creatures<=10))
                                                {
                                                        printf("to the east.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].east;
                                                        r[r[playerroom].east].creatures++;
                                                        if(r[r[playerroom].east].state==0)
                                                        {
                                                                r[r[playerroom].east].state++;
                                                                printf("\n%d dirties the room to the east.",x);
                                                        }
                                                }
						else if((r[playerroom].west!=-1)&&(r[r[playerroom].west].creatures<=10))
                                                {
                                                        printf("to the west.");
                                                        r[playerroom].creatures--;
                                                        c[x].location=r[playerroom].west;
                                                        r[r[playerroom].west].creatures++;
                                                        if(r[r[playerroom].west].state==0)
                                                        {
                                                                r[r[playerroom].west].state++;
                                                                printf("\n%d dirties the room to the west.",x);
                                                        }
                                                }
						else
						{
							printf("through the roof!");
							c[x].type=-1;
							c[x].location=-1;
							r[playerroom].creatures--;
							respect-=3;
							int y;
							for(y=0;y<creaturenum;y++)
							{
								if(c[y].location==playerroom)
								{
									if(c[y].type==1)
										printf("\nAnimal %d growls at you.",y);
									if(c[y].type==2)
                                                                                printf("\nHuman %d grumbles.",y);
								}
							}
						}
                    }
                }	
            }
			else
			{
				printf("\nThe room is already dirty!");
			}
			printf("\nRespect is now %d after this turn.",respect);
        }

		else
			printf("\nInvalid command, try again.");
		if((respect>79)||(respect<1))
			break;
		printf("\n\nNext move: ");
		memset(move, 0, sizeof(move));
		scanf("%s",move);
	}
	if(respect<=0)
		printf("\nShame on you! You lose!\n\n");
	else if(respect>=80)
		printf("\nCongratulations, you are praised!\n\n");
	else
		printf("\nYou ended with %d respect. Goodbye!\n\n",respect);
	return 0;
}





void help()
{
        printf("\n\n*********************************************************************************************************\n");
	printf("** Commands can only contain one or two words. Two words are split by \":\" (without the quotes).        **\n");
        printf("** White spaces of any kind are forbidden.                                                             **\n");
        printf("** One-word commands apply to the PC, two-word commands apply to other creatures.                      **\n");
        printf("** To move, type north, south, east, or west.                                                          **\n");
        printf("** If there is no room in this direction or because the room there is full, a corresponding error      **\n");
        printf("** message will be given and the PC will not move.                                                     **\n");
        printf("** To move a creature, type [Creature name]:[direction].                                               **\n");
        printf("** To make the PC clean or dirty the current room, type \"clean\" or \"dirty\".                            **\n");
        printf("** To make the PC look around the current room, type \"look\".                                           **\n");
        printf("** To make a creature clean or dirty the current room, type \"[Creature name]:clean\"                    **\n");
	printf("** or \"[Creature name]:dirty\".                                                                         **\n");
        printf("** To see this menu, type \"Help\" (not case-sensitive)                                                  **\n");
        printf("** To exit the game, type \"Exit\" (not case-sensitive)                                                  **\n");
	printf("**												       **\n");
	printf("** PS. I also added a \"cheat\" command to show all rooms and creatures and their characteristics.       **\n");
        printf("*********************************************************************************************************\n\n");
	return;
}