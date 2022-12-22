#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Team 3 Project Profolio
//Cole Flory, Daniel Jung, and Alaina Strickler

//Yahtzee!
//Function prototypes
void dicerolli(int[]);
void diceSelect(int[]);
void dispVal(int[]);
void diceRoll(int[],int[]);
void clearSelect(int[]);
char tierDivider(int[]);
void sectionChoice(int[],char,int[], int[]);
void asc_sort(int[], int);
//Horse Racing
//Function prototypes
int randNumber(void);
void delay(int);

int main(void){
	
	//Declare Total Variables
	int gameChoice, dice[5],diceNum[5]={0},category=0,j=0; //, diceVal[5]={0};
    int Total[2]={0}, UTotal=0, LTotal=0, FinalTotal, horseChoice;
    int horseOne,horseTwo,horseThree,catCheck[13]={0};
    char tierChoice, playAgain, chooseCat;
    
    do{
		printf("\nWelcome to Group 3's aracade");
		
		//Ask the user for which game they would want to play
		do{
		printf("\nWhich game would you like to play? Type 1 for Yahtzee and Type 2 for Horse Racing.\n");
		scanf("%d",&gameChoice);
		}while (gameChoice<1 || gameChoice >2); //loop again if the user puts in an invalid number
	
	switch (gameChoice){
	
		case 1:
		/*Yahtzee: How to play is the user will have 5 dices rolled and after the first two rolls they will pick which dice they would
		 * like to save for the next roll. After the third roll, the user will check to see where they want to put their scores in and they 
		 * only have a choice of either the upper tier or the lower tier. The upper tier will add up the values of the number they selected,
		 * for example if the user chooses sixes, the values that will be added are only of the dice that contained a six on it. The lower 
		 * tier will be other variations of dice rolls, 3 of a kind is when three dice have the same numbers but all the dice will be added
		 * up, 4 of a kind is when four dice have the same number but all the dices will be added up, a full house is when three of the dice
		 * are of the same number while two of the other dice are the same but different number than the other three, a small straight is when
		 * 4 of the dice are in sequential order, a large straight is when 5 of the dice are in sequential order, a yahtzee is when all the 
		 * dice are the same number, and chance is when all the dice values are added up and their is no rules to what has to be on the dice. 
		 * After 13 rounds, the upper tier and lower tier will be added up and if the upper tier is 63 points or greater, the player will get
		 * an additional 35 points. The two tiers then will be added up and if they are 150 points or greater than the player wins*/
			printf("\nYahtzee!!\n\n");
			for(int i=0;i<13;i++) {
				if(category==0) {
					//initially rolls five dice
					dicerolli(dice);
					//displays the values of five dice
					dispVal(dice);
			
					while(category==0 && j<2) {
						//Decide if they want to choose a category
						do {
							printf("\nChoose a Category? (y/n)\n");
							scanf(" %c", &chooseCat);
						}while(chooseCat!='y'&&chooseCat!='n');
						if(chooseCat=='y') {
							//let the user choose which tier they want their dice in
							tierChoice=tierDivider(dice);
							//let the user choose which section they want their dice in 
							sectionChoice(dice,tierChoice,Total,catCheck);
							//break out of while loop by setting category=1
							category=1;
						}
						else {
							//selects one to five dice to not roll
							diceSelect(diceNum);
							diceRoll(diceNum,dice);
							dispVal(dice);
							if(j==1) {
								//let the user choose which tier they want their dice in
								tierChoice=tierDivider(dice);
								//let the user choose which section they want their dice in 
								sectionChoice(dice,tierChoice,Total,catCheck);
								//break out of while loop by setting category=1
								category=1;
							}		
							j++;	
						}
					}
					printf("\n\nThe Upper Score is:\t%d\nThe Lower Score is:\t%d\n",Total[0],Total[1]);
					j=0;
				}
				category=0;
				printf("\nEnd of Round %d\n\n------------------------------------------\n\n",i+1);
			}
			//declaring UTotal and LTotal as the different elements in array Total
			UTotal=Total[0];
			LTotal=Total[1];
			
			//adding additional 35 points if Utotal equals 63 or greater
			if(UTotal>62){
				printf("You received a bonus 35 points!");
				UTotal=UTotal+35;
			}
			
			//Combining the totals
			FinalTotal=UTotal+LTotal;
			
			//Win or Lose
			if (FinalTotal>150){
			  printf("Congratulations you WIN!!!");}
			else {
			  printf("Sorry, but you did not win. Better luck next time!");}
			break;
		case 2:
		/*Horse Racing: How the game works is the user will select a horse they think will win and then they will
		 * watch as the horses race to the finish line (get to the value of 100 or greater)
		 * and if their horse wins, then they win. The horses positions will be generated as a random number and will keep
		 * being added to its previous position.*/
			printf("\nHorse Racing!!");
			
			//Let the user choose their horse they want to win
			do{
			printf("\nPlease select which horse you want to choose.\nThe choices are either 1, 2, or 3 ");
			scanf("%d", &horseChoice);
			}while(horseChoice<1 || horseChoice>3); //loop if a valid horse is not chosen
			
				//Display to the user which horse they chose
				switch (horseChoice){
					case 1:
					printf("\nYou chose horse 1");
					break;
					case 2:
					printf("\nYou chose horse 2");
					break;
					case 3:
					printf("\nYou chose horse 3");
					break;
				}
				
				//initializing each horse
				horseOne=0;
				horseTwo=0;
				horseThree=0;
				
				printf("\nHorse one, horse two, and horse three are at the starting position.");
				
				printf("\nThe first one to reach 100 meters wins.");
				
				printf("\nAnd they're off!");
				
				//generate a random number for each horse and continously add up the values until one of the horses is at 100 or greater
				do{
					horseOne= horseOne+randNumber();
					horseTwo = horseTwo + randNumber();
					horseThree = horseThree + randNumber();

					printf("\nHorse 1: %d", horseOne);
					printf("\nHorse 2: %d", horseTwo);
					printf("\nHorse 3: %d", horseThree);
					printf("\n---------------");
					
					//have a time delay between each random number that is generated
					delay(3);
					
				}while (horseOne <=100&&horseTwo <=100&&horseThree <=100);
				
				//Display which horse won in the race
				if (horseOne > horseTwo && horseOne > horseThree) {
					printf("\nHorse 1 is the winner.");
					//Display if the users choice of horse won that they won
						if (horseChoice == horseOne){
							printf("\nYou win!!!");
							}
						else{
							printf("\nSorry, better luck next time");
							}
				}
				else if (horseTwo > horseOne && horseTwo > horseThree) {
					printf("\nHorse 2 is the winner.");
					//Display if the users choice of horse won that they won
					if (horseChoice == horseTwo){
							printf("\nYou win!!!");
							}
						else{
							printf("\nSorry, better luck next time");
							}
				}
				else {
					printf("\nHorse 3 is the winner.");
					//Display if the users choice of horse won that they won
					if (horseChoice == horseThree){
							printf("\nYou win!!!");
							}
						else{
							printf("\nSorry, better luck next time");
							}
				}
			
				break;
		}
		//Ask the user if they will like to play the game again
		printf("\nWould you like to play again? Type y to go again. ");
		scanf(" %c",&playAgain);
		}while(playAgain=='y');
	return 0;
}


//initial diceroll
void dicerolli(int diceVal[]) {
	srand(time(NULL));
	for(int i=0;i<5;i++) {
	
		diceVal[i]=rand()%6+1;
		//printf("Dice %d is %d.\n",i+1,diceVal[i]);
	}
	
}
//print values of dice
void dispVal(int diceVal[]){
	for(int i=0;i<5;i++) {
		
		printf("Dice %d is %d.\n",i+1,diceVal[i]);
	
	}
}

//roll dice without selected dice
void diceRoll(int diceNum[],int diceVal[]){
	int dicePlaceHold[5]={0};
	//place the value of the initial dice roll into new dice
	for(int i=0;i<5;i++) {
		if(diceNum[i]!=0) {
			dicePlaceHold[i] = diceVal[diceNum[i]-1];
		}
	}
	
	dicerolli(diceVal);
	//hold the value of the dice
	for(int i=0;i<5;i++) {
		if(diceNum[i]!=0) {
			diceVal[diceNum[i]-1] = dicePlaceHold[i];
		}
	}	

}

//Clear dice selection
void clearSelect(int diceNum[]){
	
	for(int i=0;i<5;i++) {
		diceNum[i]=0;
	}
	
}

//select dice
void diceSelect(int diceNum[]){
	
	 
	char again='y';
	for(int j=0;j<5;j++) {
		printf("Which dice would you like to select?\nDice #");
		scanf("%d", &diceNum[j]);
		if(j==4) {
			break;
		}
		do {
			printf("Would you like to select another die?\n");
			scanf(" %c", &again);
		}while(again!='n' && again!='y');
		if(again=='n') {
			break;
		}
	}
}

//Choice of tiers
char tierDivider(int diceNum[]){
	
	char tierchoice;
	
	//Get the user's input on what dice they choose to select
	do {
		printf("\nWould you like to put your dice roll in the upper tier or the lower tier (ones is upper, yahtzee is lower)?");
		printf("\nInput u for upper or l for lower.\t");
		scanf(" %c",&tierchoice);
	}while(tierchoice!='u'&&tierchoice!='l');
	//Switch case for the user's input on which tier they chose
	switch (tierchoice){
		case 'l':
			printf("You chose lower tier!");
			break;
		case 'u':
			printf("You chose upper tier!");
			break;
	}
	return tierchoice;
}

//Let the user choose which section they want to put their dice roll in
void sectionChoice(int diceVal[],char tierchoice,int Total[],int catCheck[]) {
	int i=0, UTotal=0, LTotal=0; 
	int Ones=0, Twos=0, Threes=0, Fours=0, Fives=0, Sixes=0, SmallStraight=0;
    int LargeStraight=0, FullHouse=0, Yahtzee=0, ThreeOfKind=0, FourOfKind=0, Chance=0, UTierChoice;
    char LTierChoice;
    int counter[6]={0},curSeqLen,lastDie,LTierNum;
    //Counts number of instances of dice
	for(int k=0;k<5;k++) {
		//count number of 1s
		if(diceVal[k]==1) {
			counter[0]++;
		}
		//count number of 2s
		else if(diceVal[k]==2) {
			counter[1]++;
		}
		//number of 3s
		else if(diceVal[k]==3) {
			counter[2]++;
		}
		else if(diceVal[k]==4) {
			counter[3]++;
		}
		else if(diceVal[k]==5) {
			counter[4]++;
		}
		else {
			counter[5]++;
		}
	}
	
	if(tierchoice=='u'){
		//Get the user's input for what section of the upper tier they want to place their dice rolls
		do {
			printf("\nWhich section would you like to put your dice roll?");
			printf("\n1 for ones, 2 for twos, 3 for threes, 4 for fours, 5 for fives, or 6 for sixes ");
			scanf("%d",&UTierChoice);
		}while((UTierChoice<1||UTierChoice>6)||catCheck[UTierChoice-1]==1);
		//Switch case for the different sections in the upper tier
		switch (UTierChoice){
			case 1:
				for(i=0;i<5;i++){
					if(diceVal[i]==1){
						Ones=Ones+diceVal[i];
					}
				}
				UTotal=UTotal+Ones;
				printf("\nOnes has been filled");
				printf("\nThe Total for Ones is: %d",Ones);
				//Set Category as Chosen
				catCheck[0]=1;
				break;
			case 2:
				for(i=0;i<5;i++){
					if(diceVal[i]==2){
						Twos=Twos+diceVal[i];
					}
				}
				UTotal=UTotal+Twos;
				printf("\nTwos has been filled");
				printf("\nThe Total for Twos is: %d",Twos);
			
				//Category is now chosen
				catCheck[1]=1;
				break;
			case 3:
				for(i=0;i<5;i++){
					if(diceVal[i]==3){
						Threes=Threes+diceVal[i];
					}
				}
				UTotal=UTotal+Threes;
				printf("\nThrees has been filled");
				printf("\nThe Total for Threes is: %d",Threes);
			
				//Category is now chosen
				catCheck[2]=1;
				break;
							
			case 4:
				for(i=0;i<5;i++){
					if(diceVal[i]==4){
						Fours=Fours+diceVal[i];
					}
				}
				UTotal=UTotal+Fours;
				printf("\nFours has been filled");
				printf("\nThe Total for Fours is: %d",Fours);
			
				//Category set to chosen
				catCheck[3]=1;
				break;
			case 5:
				for(i=0;i<5;i++){
					if(diceVal[i]==5){
						Fives=Fives+diceVal[i];
					}
				}
				UTotal=UTotal+Fives;
				printf("\nFives has been filled");
				printf("\nThe Total for Fives is: %d",Fives);
			
				//Category set to chosen
				catCheck[4]=1;
				break;
			case 6:
				for(i=0;i<5;i++){
					if(diceVal[i]==6){
						Sixes=Sixes+diceVal[i];
					}
				}
				UTotal=UTotal+Sixes;
				printf("\nSixes has been filled");
				printf("\nThe Total for Sixes is: %d",Sixes);
			
				//Category set to chosen
				catCheck[5]=1;
				break;
		}
	}
							
	else {
		do {
			printf("\nWhich section would you like to put your dice roll?");
			printf("\nT for 3 of a kind, F for 4 of a kind, H for Full House, S for small straight");
			printf("\nL for large straight, Y for Yahtzee, or C for Chance (put your anwser in caps) ");
			scanf(" %c",&LTierChoice);
			if(LTierChoice=='T') {
				LTierNum=6;
			}
			else if(LTierChoice=='F') {
				LTierNum=7;
			}
			else if(LTierChoice=='H') {
				LTierNum=8;
			}
			else if(LTierChoice=='S') {
				LTierNum=9;
			}
			else if(LTierChoice=='L') {
				LTierNum=10;
			}
			else if(LTierChoice=='Y') {
				LTierNum=11;
			}
			else if(LTierChoice=='C') {
				LTierNum=12;
			}
		}while((LTierChoice!='T'&&LTierChoice!='F'&&LTierChoice!='H'&&LTierChoice!='S'&&LTierChoice!='L'&&LTierChoice!='Y'&&LTierChoice!='C')||catCheck[LTierNum]==1);
		
		
		//Switch case for the different sections in the lower tier
		switch (LTierChoice){
			case 'T':
				for(int k=0;k<6;k++) {
					if(counter[k]>=3) {
						for(i=0;i<5;i++) {
							ThreeOfKind=ThreeOfKind+diceVal[i];
						}
						break;
					}
					else {
						ThreeOfKind=0;
					}
				}
				LTotal=LTotal+ThreeOfKind;
				printf("\nThree of a Kind has been filled");
				printf("\nThe Total for Three of a Kind is: %d",ThreeOfKind);
				//Set Category as Chosen
				catCheck[6]=1;
				break;
			case 'F':
				for(int k=0;k<6;k++) {
					if(counter[k]>=4) {
						for(i=0;i<5;i++){
							FourOfKind=FourOfKind+diceVal[i];
						}
						break;
					}
					else {
						FourOfKind=0;
					}
				}
				LTotal=LTotal+FourOfKind;
				printf("\nFour of a kind has been filled");
				printf("\nThe total for Four of a Kind is: %d",FourOfKind);
				
				//Set Category as Chosen
				catCheck[7]=1;
				break;
			case 'H':
				
				asc_sort(diceVal,5);
			
				if (((diceVal[0]==diceVal[1]) && (diceVal[0]==diceVal[2])&&(diceVal[3]=diceVal[4])) || ((diceVal[0]==diceVal[1]) && (diceVal[2]==diceVal[3])&&(diceVal[2]=diceVal[4])))  {
					FullHouse=25;
				}
				
				LTotal=LTotal+FullHouse;
				printf("\nFull House has been filled");
				printf("\nTotal for Full House is: %d", FullHouse);
				
				//Set Category as Chosen
				catCheck[8]=1;
				break;
			case 'S':
				asc_sort(diceVal,5);
				
				curSeqLen=1;
				
				lastDie=diceVal[0];
				if ((diceVal[0] >= 4)  || (diceVal[4] <=3))  {
					SmallStraight=0;
				}
				
				for (int i=1;i<5;i++) {
					// the current die is one greater than the last one, the numbers are in sequence

                    if (diceVal[i] == lastDie+1) {
						curSeqLen++;
					}
					
					// the current die is the same as the last die, nothing is needed to be done
                    // as i will be incremened in the for loop... 

                    else if (diceVal[i] == lastDie) {

                    // the consecutive dice are not in order, still might be a straight in there though
                    // like in the case that i is small when this is reached, ex. {1, 3, 4, 5,6 }

                    } 
                    else {

                    curSeqLen=1;

                    }

                            

                    // obviously, a small straight is true when the sequence is 4 or longer

                    if (curSeqLen >=4) {

						SmallStraight=30;

                        break;

                    }

                    lastDie = diceVal[i];
				}

				LTotal=LTotal+SmallStraight;
				printf("\nSmall Straight has been filled");
				printf("\nTotal for Small Straight is: %d",SmallStraight);
				//Set Category as Chosen
				catCheck[9]=1;
				break;
			case 'L':
				asc_sort(diceVal,5);

                curSeqLen=1;

                lastDie=diceVal[0];

                for (int i = 1; i < 5; i++) {

					// the current die is one greater than the last one, the numbers are in sequence

                    if (diceVal[i] == lastDie+1) {

						curSeqLen++;

                    }

					if (curSeqLen >=5) {

						LargeStraight=40;

                        break;

                    }

                    lastDie = diceVal[i];
				}
                LTotal=LTotal+LargeStraight;

                printf("\nLarge Straight has been filled");
				printf("\nTotal for Large Straight is: %d",LargeStraight);
				//Set Category as Chosen
				catCheck[10]=1;
                break;
			case 'Y':
				for(int k=0;k<6;k++) {
					if(counter[k]==5) {
						Yahtzee=50;
					}
					else {
						Yahtzee=0;
					}
				}
				LTotal=LTotal+Yahtzee;
				
				printf("\nYahtzee has been filled");
				printf("\nTotal for Yahtzee is: %d",Yahtzee);
				//Set Category as Chosen
				catCheck[11]=1;
				break;
			case 'C':
				for(i=0;i<5;i++){
					Chance=Chance+diceVal[i];
				}
				LTotal=LTotal+Chance;
				printf("\nChance has been filled");
				printf("\nTotal for Chance is: %d",Chance);
				//Set Category as Chosen
				catCheck[12]=1;
				break;
		}
								
	
	}

	Total[0]=UTotal+Total[0]; //Putting the upper tier total in the first element of the total array
	Total[1]=LTotal+Total[1]; //putting the lower tier total in the second element of the array
	
}
//Generate a random number that each horse has ran to
int randNumber(void)
{
	int lower = 1, upper = 20;

	int num = (rand() % (upper - lower + 1)) + lower;

	return num;
}

//Have a delay inbetween each horses race
void delay(int seconds) {
	int milliseconds = 1000*seconds;
	
	clock_t start_time = clock();
	
	while (clock() <start_time+milliseconds);
}

// Sort Array Ascending of Yatzee dice

/* Function definition for asc_sort */

void asc_sort(int diceVal[5], int n)
{
	int i, j, temp;

	for(i=0;i< n-1;i++)

	{
		for(j=i+1;j< n;j++)
		{
			if(diceVal[i]>diceVal[j])
			{
				temp = diceVal[i];
				diceVal[i] = diceVal[j];
				diceVal[j] = temp;

			}
		}
	}
}
