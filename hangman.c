#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int main() {

	srand(time(NULL));
	
	char guessWords[][20] = {
		"bear", 
		"summer",
		"water",
		"raven",
		"fruit",
		"apple"	
	};
	
	// index for random word
	int randomIndex = rand() % 6;
	
	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);
	
	int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	
	int loopIndex = 0;
	int reguessed = 0; // EDIT
	
	char guess[20];
	char letterEntered;	
	
    // game loop	
	while ( numCorrect < lengthOfWord ) {

		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				printf("%c",guessWords[randomIndex][loopIndex]);				
			} else {
				printf("*");
			}
		
		}	
		
		printf("\n");
		printf("Enter a guess letter:");
		fgets(guess, 20, stdin);

		
		letterEntered = guess[0];
		reguessed = 0; 
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				if(guessWords[randomIndex][loopIndex] == letterEntered) {
					reguessed = 1; 

				} 
				continue;
			}
		
			if( letterEntered == guessWords[randomIndex][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
		
		if( oldCorrect == numCorrect) {
			numLives--;
			printf("Sorry, wrong guess\n");
			if (numLives == 0) {
				break;
			}
		} else {
			printf("Correct guess :)\n");
		}
	
	} // while loop
	
if (numLives == 0) {
		printf("\nSorry you lose, the word was: %s\n",
		guessWords[randomIndex]);	
	} else  {	
		printf("\nYou win!\n");
	} 
	
	return 0;
}
