#include <stdio.h>
#include <string.h>

int main() 
    char word[20];			//Used to store the user word. Most words are less than 20 characters so the default size is 20.
    char stars[20];			//A string full of * that are replaced upon the user entering the right letter of the word.
    int counter = 0;			//A counter to use in the for loops.
    int len;				//len is the length of the word entered.
    char ch;				//ch is a temporary character variable.
    int guessses=0;			//strikes counts how many wrong characters the user has guessed.
    int flag = 0;			//The trigger variable serves as a flag in the for loops bellow.
    int win=0;			//wincounter keeps track of the number of correct guesses.
    int i;				//Another counter variable to be used in for loops.

  char word[][20] = {
		"pen", 
		"fruit",
		"summer",
		"water",
		"bear",
		"apple"	

for(counter = 0; counter<26; counter++)
    {
        if(win==len)			   
            printf("Good job! The word is \"%s\".\n", answer);
            break;
        }
if(strikes==10)
        {
             printf("Game Over! The word is \"%s\".\n", answer);
            break;
	}
printf("\n\n\n\n%s", stars);
printf("\n\nGuess a letter:");
        scanf(" %c",&ch);
 for(i=0; i<len; i++)            		
        {
            if(word[i]==ch)
            {
                stars[i]=ch;		    		
                flag++;			   	
                wincounter++;		    		
            }
        }

        if(flag==0)
        {
            strikes++;				    	

        flag = 0;				    
    }

  return 0;
}
