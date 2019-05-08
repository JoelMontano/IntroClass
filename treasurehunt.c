/*Joel Montano
    Project 8
 */

#include <stdio.h>

#define CREWSIZE 4
#define GRID 3
#define MAX 20
#define TIMELIMIT 8

//pirate structure
typedef struct {
    int dig;
    int carry;
} pirate;

//map structure
typedef struct {
    int sand;
    int treasure;
} map;

//function prototypes
void init(map m[3][3], pirate c[4]); //initializes all of the map and crew
void printmap(map m[3][3]);//prints map status after each crew is assigned and after every hour
void printcrew(pirate p[4]); //separate from map print because only prints once an hour
int check(map m[3][3], int scan);//check function to see if everything is claimed
int assign(pirate p[4], map m[3][3], int sum);//function that assigns a pirate to a grid location, digs or picks up treasure


int main(void){
    map m[3][3];
    pirate c[4];
    int j, claimed = 0, sumtreasure=0, pretotal=0; //J represents the number of hours left
    init(m,c);

        //for loop that starts at the time limit, continues until time runs out or all the treasure is collected
        //if treasure is collected before time = 0, claimed = 1 and the loop breaks
        for(j=TIMELIMIT; j > 0; j--)
        {
            printf("You have %d hours left to dig up the treasure!\n",j);
            printcrew(c);
            printmap(m);
            sumtreasure += assign(c,m, pretotal);
            pretotal = 0;
            claimed = check(m, claimed);
            if (claimed == 1)
              break;
        }

    if(claimed == 1)
        printf("All of the treasure belongs to you now!\n");
    else
        printf("You are forced to evacuate the island, you have taken %d pieces of gold", sumtreasure);

return;

}
void init(map m[3][3], pirate c[4]){
    char filename[MAX];
    int i, j;

    //User inputs the map
    printf("You have arrived at Treasure Island!\n");
    printf("What is the name of your map?\n");
    scanf("%s", filename);

    FILE * ifp;
    ifp = fopen(filename,"r+");

    //Reads the file and assigns sand and treasure values to the map
    for (i=0; i<GRID; i++)
    {
        for(j=0; j<GRID; j++)
        {
            fscanf(ifp,"%d", &m[i][j].sand);
            fscanf(ifp,"%d", &m[i][j].treasure);
        }
    }
    //Reads the file and assigns dig and carry values to the pirates
    for (i=0; i<CREWSIZE; i++)
    {
        fscanf(ifp, "%d", &c[i].dig);
        fscanf(ifp, "%d", &c[i].carry);
    }
return;
}

void printcrew(pirate c[4]){
    int i;

    //prints the crew and their stats
    printf("Crew\tDig\tCarry\n");
    for (i=0; i<CREWSIZE; i++)
    {
        printf("%d\t", i+1);
        printf("%d\t", c[i].dig);
        printf("%d\n", c[i].carry);
    }
    printf("\n");

return;
}
void printmap(map m[3][3]){
    int i, j;

    //prints the current state of the map
    printf("Current Map Status\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            //updates the map based on the actions done.
            //logic goes from #s -> #t -> "-"
            if (m[i][j].sand > 0)
                printf("%ds\t", m[i][j].sand);
            else if (m[i][j].sand <= 0 && m[i][j].treasure > 0)
                printf("%dt\t", m[i][j].treasure);
            else if (m[i][j].sand <= 0 && m[i][j].treasure <= 0)
                printf("-\t");
        }
        printf("\n");
    }

printf("\n");
return;
}
int assign(pirate c[4], map m[3][3], int sum){
    int i = 0, claimed = 0, amount_carried = 0;
    int loc[2];

    for(i=0; i<4; i++)
    {
        //prompts user to enter location for the crew member
        printf("Where would you like to send crew member %d?\n",i+1);
        scanf("%d %d",&loc[0],&loc[1]);
        //subtracts 1 from the users input
        //usually people will put 1,1 for top left block but, makes it 0,0 to make it top left instead of middle block
        loc[0]--;
        loc[1]--;

        if (m[loc[0]][loc[1]].sand > 0)
        {
            //subtracts sand based on dig value for that pirate
            m[loc[0]][loc[1]].sand = m[loc[0]][loc[1]].sand - c[i].dig;

            //all sand is dug up, map is printed to reflect changes
            if (m[loc[0]][loc[1]].sand <= 0)
            {
                printf("You have removed all of the sand from this section!\n");
                printf("\n");
                if (i<3)
                    printmap(m);
            }
            //all sand isn't dug up, map is printed to reflect changes
            else
            {
                printf("You have removed some of the sand from this section!\n");
                printf("\n");
                if (i<3)
                    printmap(m);
            }
        }

        else if (m[loc[0]][loc[1]].sand <= 0 && m[loc[0]][loc[1]].treasure > 0)
        {

            //treasure at given location is subtracted based on carry value of pirate
            m[loc[0]][loc[1]].treasure = m[loc[0]][loc[1]].treasure - c[i].carry;

            //if all treasure is picked up, prints appropriate response, prints map, and calls check function
            //if all treasure is claimed, claimed = 1 to break loop and return to main
            if (m[loc[0]][loc[1]].treasure <= 0)
            {
                printf("You have taken all of the treasure from this section!\n");
                printf("\n");
                claimed = check(m, claimed);
                if (m[loc[0]][loc[1]].treasure == 0)
                    amount_carried += c[i].carry;
                else
                    amount_carried += c[i].carry + m[loc[0]][loc[1]].treasure;
                if (i<3)
                    printmap(m);
            }
            //prints appropriate response if some treasure is still left.
            //prints updated map
            else
            {
                printf("You have taken some of the treasure from the location!\n");
                printf("\n");
                amount_carried = amount_carried + c[i].carry;
                if (i<3)
                    printmap(m);
            }
        //breaks out of loop if no more treasure is left
        if (claimed == 1)
            break;
        }
        else if (m[loc[0]][loc[1]].sand <= 0 && m[loc[0]][loc[1]].treasure <= 0)
            printf("There is nothing there!\n");

}
return amount_carried;
}

int check(map m[3][3], int scan){
    int i, j, counter = 0;
    //checks the whole grid to see if any treasure is left
    for (i=0; i<GRID; i++)
    {
        for(j=0; j<GRID; j++)
        {
            if (m[i][j].treasure <= 0)
                counter++;
        }
    }
    //if all 9 blocks return 0 value for treasure, return a 1 value to break loops above
    //if not, 0 is returned to continue the loop
    if (counter == 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


