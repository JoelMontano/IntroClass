/* Joel Montano
COP 3223C Section 5
2/7/2019 */

//Pre-Processor Directives
#include <stdio.h>


//Main function
int main(void){
    int days_obs=0, num_trips=0,day_count=0,i=0, j=0;
    float trip_length=0, trip_total=0, avg_trip=0;

    //Gets how many days observed
    printf("How many days will you observe the landing crew?\n");
    scanf("%d",&days_obs);

    //Gets trip number
    while (i < days_obs){

        printf("How many trips were completed in day #%d?\n",day_count+1);
        scanf("%d",&num_trips);

    //Gets total distance traveled
    while (j< num_trips){

        printf("How long was trip #%d?\n",j+1);
        scanf("%f",&trip_length);
        trip_total = trip_total + trip_length;
        j++;

    }
    //Calculates average and sets up variables for next iteration
    avg_trip = trip_total/j;
    day_count += 1;
    printf("Day #%d: The average trip time was %.3f\n",day_count,avg_trip);
    i++;

    //Resets the values for the next iteration
    j=0;
    trip_length=0;
    trip_total=0;
}
return 0;
}
