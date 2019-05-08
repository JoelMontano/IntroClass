/* Joel Montano
COP 3223C Section 5
1/31/2019 */

//Pre-Processor Directives
#include <stdio.h>

//Constant costs
#define usedcost 5.0
#define newcost 15.0
//Main function
int main(){
    //variable declaration
    int type, numnew = 0, numused = 0, totalnew = 0, totalused = 0;
    float total = 0, avgcost = 0;

    //print menu for the user
    printf("Please select one of the following\n");
    printf("\t1 - Buy New Gear\n");
    printf("\t2 - Buy Used Gear\n");
    printf("\t3 - Quit\n");
    scanf("%d",&type);

    //User shops until user quits
    while(type != 3){
        switch (type){
        //New Gear
        case 1:
            printf("How many pieces of new gear would you like?\n");
            scanf("%d",&numnew);
            totalnew += numnew;
            total += numnew*newcost;
            break;
        case 2:
            printf("How many pieces of used gear would you like?\n");
            scanf("%d",&numused);
            totalused += numused;
            total += numused*usedcost;
            break;
        case 3:
            break;
        default:
            printf("Sorry, that is not a valid option.\n");
            break;
        }//end switch

    //Reprint menu
    printf("Please select one of the following\n");
    printf("\t1 - Buy New Gear\n");
    printf("\t2 - Buy Used Gear\n");
    printf("\t3 - Quit\n");
    scanf("%d",&type);
    } //end while loop

    //tell user what they bought and for how much
    printf("Your total is %.2f gold pieces\n",total);
    printf("You purchased %d piece(s) of new gear and %d piece(s) of used gear\n",totalnew,totalused);

    //get the average cost for the user
    avgcost = total / (totalnew + totalused);

    //prevent the user from seeing a weird number if nothing is purchased
    if(total > 0)
    printf("The cost per piece of gear is %.2f pieces of gold", avgcost);

return 0;
}
