/* Joel Montano
COP 3223C Section 5
3/1/2019 */


#include <stdio.h>

#define SIZE 7
#define LIMIT 101

int main(){

    int guess[SIZE];
    int correct[SIZE];
    int freq[LIMIT];
    int i, j, check = 1, matches=0, open=1, attempt=1, count=0;
    char filename[10];

    //Retrieves the correct code
    printf("What is the name of the file?\n");
    scanf("%s",&filename);

    FILE * ifp = fopen(filename,"r");

    for(i=0; i<SIZE; i++)
        fscanf(ifp, "%d", &correct[i]);

    printf("To get to me treasure you'll have to figure out which of me 100 keys are usedin the 7 locks of me treasure chest.\n");

    //Allows for the user to keep guessing
    while (attempt == 1)
    {

        //User inputs guesses
        printf("Which keys will ye use?\n");

        for(i=0; i<SIZE; i++)
            scanf("%d", &guess[i]);

        //Initialize frequency test
        for(i=0; i<LIMIT; i++)
            freq[i] = 0;

        //Traverse the freq, adding our ticker
        for(i=0; i<SIZE; i++)
            freq[guess[i]]++;

        //Check that all frequencies are 1
        for (i=0; i<LIMIT; i++)
        {
            if(freq[i] > 1)
                check = 0;
        }
        //Continues with testing the guess if initial check is passed
        if (check)
        {
            for (i=0; i<SIZE; i++)
            {
                //Determines the correct order
                if (guess[i] == correct [i])
                    count++;
                    else
                    open=0;
                //Prevents false positive is last number is in the correct position
                if (count == 7)
                    open=1;
                //Determines the # of correct answers
                for (j=0; j<SIZE; j++)
                {
                    if (guess[i] == correct[j])
                    matches++;
                }
            }
                    //Correct guess
                if (open)
                {
                    printf("Arr! You've opened me treasure chest and found...A map! To the rest of me treasure on Treasure Island.\n");
                    attempt = 0;
                }
                //Resets if the user guessed incorrectly
                else
                {
                    printf("%d correct keys, but are they in the right order?\n",matches);
                    attempt = 1;
                    matches = 0;
                }
                }
                //Resets if the user inputs a repeat variable
            else
            {
                printf("You can only use each key once, matey!\n");
                matches = 0;
                check = 1;
            }
    }
return 0;
}


/*

    //  if(!check)  (Prof. Angell added this, not part of my submission)
    //{
    //print statement for duplicates
    //    continue;
    //}

*/
