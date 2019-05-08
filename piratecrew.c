/* Joel Montano
COP 3223C Section 5
1/25/2019 */

//Pre-Processor Directives
#include <stdio.h>

//Define Constants
#define SWIMLIMIT 100

//Main Function
int main(){
    //Variable declaration
    char treasure, swim;
    float dist;

    //user input
    printf("Do you like to search for treasure? (Y/N)\n");
    scanf("%c",&treasure);

    printf("Can you swim? (Y/N)\n");
    scanf(" %c",&swim);

    //Decide if user can join the crew
    if (swim == 'Y')
    {
        printf("How far can you swim?\n");
        scanf("%f",&dist);
    }
    if (dist >= SWIMLIMIT && treasure == 'Y')
        printf("You can join the crew!\n");
    else
        printf("You cannot join the crew!\n");

return 0;
}
