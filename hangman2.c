#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	
	char guessWords[][16] = {
		"fruit", 
		"bear",
		"summer",
		"raven",
		"water",
		"apple"	
	};
	
	int randomIndex = rand() % 6;
	
	int numLives = 10;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);

	int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	
	int quit = 0;	
	
	int loopIndex = 0;
	int reguessed = 0; // EDIT
	
	char guess[16];
	char letterEntered;	
	
 	
	while ( numCorrect < lengthOfWord ) {
	
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) 
		{
		
			if(letterGuessed[loopIndex] == 1) 
			{
				printf("%c",guessWords[randomIndex][loopIndex]);				
			} 
			else 
			{
				printf("*");
			}
		
		}	
		
		printf("\n");
	
		printf("Enter a letter:");
		fgets(guess, 16, stdin);
		}
		
		letterEntered = guess[0];
		reguessed = 0; 
		
		printf("You entered:%c\n",letterEntered);
		
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) 
		{
		
			if(letterGuessed[loopIndex] == 1) 
			{
				if(guessWords[randomIndex][loopIndex] == letterEntered) 
				{
					reguessed = 1; 
					break;
				} 
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex] ) 
			{
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
		
		if( oldCorrect == numCorrect && reguessed == 0) 
		{
			numLives--;
			printf("Sorry, wrong guess\n");
			if (numLives == 0) 
			{
				;
			}
		 else 
		 {
			printf("Correct guess :)\n");
		 }
	
		}
	
	if (numLives == 0) 
	{	
		printf("\nSorry you lose, the word was: %s\n",
		guessWords[randomIndex]);
	}
	else  
	{
		printf("\nYou win!\n");
	} 

	return 0;
}
