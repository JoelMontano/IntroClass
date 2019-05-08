/* Joel Montano
Cop 3223C Section 5
1/18/2019 */

//Pre-Processor Directives
#include <stdio.h>
#include <math.h>

//Constants
#define total_dist 7228.0

//Main Function
int main(){

    //Set Variables
    int crew_size, km_in_day;
    float total_days, oranges;

    //Ask User How many km in a day
    printf("How many kilometers can your ship travel in a day?\n");
    scanf("%d",&km_in_day);

    //Ask User how many crew members there are
    printf("How many sailors are in your crew?\n");
    scanf("%d",&crew_size);

    //Calculate how many days the trip will last
    total_days = total_dist/km_in_day;
    //printf("Your trip will take %.2f days.\n",total_days);

    //Tell user how many oranges they need for the trip
    oranges = total_days*crew_size*0.5;
    printf("You need %.2f oranges for the trip!",oranges);

return 0;
}
