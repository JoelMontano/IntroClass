/* Joel Montano
COP 3223C Section 5
2/21/2019 */

//Pre-Processor Directives
#include <stdio.h>


//Main function
int main(){

    //declare variables60
    int i=0, j=0, k=0, max=0, monthpicked=0, header=0, daysinrange=0;
    float percentdays=0, currenttemp=0, dayavg=0, hottemp=0, coldtemp=0;
    char filename[20];

    //Asks for user input
    printf("Tell me about your crew's preferred temperature for sailing:\n");
    printf("What is the coldest temperature they can sail in?\n");
    scanf("%f",&coldtemp);

    printf("What is the hottest temperature they can sail in?\n");
    scanf("%f",&hottemp);

    printf("Please enter the name of the weather data file:\n");
    scanf("%s",&filename);

    //declare and initialize file pointer
    FILE * ifp = fopen(filename,"r");

    //reads the first line for number of iterations
    for(k=0;k<12;k++)
    {
        //reads the header
        fscanf(ifp, "%d", &header);
            for(i=0;i<header;i++)
            {
            //calculate how many days are in the temperature range
            fscanf(ifp,"%f",&currenttemp);
                if (currenttemp >= coldtemp && currenttemp <= hottemp)
                {
                    daysinrange++;
                    j++;
                }
                else
                {
                    j++;
                }
            //calculates the % of days that fall in the range
            dayavg = (float)daysinrange / (float)j * 100.0;
            }
        printf("Month %d: %.1f percent days in range.\n", k+1, dayavg);

            //Calculates which month to sail in
            if (dayavg > max)
            {
                max=dayavg;
                monthpicked = k+1;
            }
        //reset
        dayavg=0;
        j=0;
        daysinrange=0;
    }
    printf("You should leave for the Caribbean in month %d!\n", monthpicked);

    fclose(ifp);

return 0;
}

