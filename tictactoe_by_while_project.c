#include<stdio.h>

void interastucture(); 
 
 
int winnerdecider();

 
char chart[]={'0','1','2','3','4','5','6','7','8','9'};




int main(){

  
                // made by roshanjagdesh 

int i;


printf("\n\n******************************************\n");
printf("____WELCOME TO RJ GAMING_ZONE____\n\n");

int player=1,input;
        /* here we use player variable for player and Inatialize it with one for player one */
interastucture();

while (1) 
{
     player=(player%2==0)? 2 : 1;   // for change player number in print statement  

    char sign = (player==1)? 'X' : 'R';
    /* char sign used for the sign of the player where captital X is used for player one and R for second */
        /* x means any unknwon and R is my name first later so i used */

    printf("player %d enter the input your wish number : ",player);

    scanf("%d",&input);    // for user choice about number

    if(input < 1 || input > 9 || chart[input]=='X' || chart[input]=='R')  

    /* we need input from 1 to 9 and taken value will never be picked again */
  {
    printf("please enter valid number ....\n");

    continue; // this will help to run if we remove then program will simple exit after invalid input
  }
   
    chart[input]=sign;
    interastucture();


    int result=winnerdecider();          // here we store winner decider

    if(result==1)
{
    printf("\n\t player %d is winner \n\n",player);
    printf("=========================\n");
    printf("=========================\n");


    return 0;
}
    else if (result==0)
{
    printf("\n\t draw \n\n");
    printf("=========================\n");
    printf("=========================\n");

}


       player++;


   }

            // this section will ask user will you you play again or not
char play_again;
    printf("Do you want to play again? (yes/no): ");
    scanf(" %c", &play_again);

    if (play_again == 'y' || play_again == 'Y') {
        // call main and chart will be auto reset
        for ( i = 1; i <= 9; i++)
            chart[i] = i + '0'; // Resetting to numbers
             main();
    } else {
        printf("Thank you for playing!\n");
    }

    return 0;




}


/*     interface of the game  */

void interastucture(){
printf("=========================\n");
printf("       TIC TAC TOE       \n");
printf("=========================\n");

printf("    |     |    \n");
printf("  %c |  %c  | %c  \n",chart[1],chart[2],chart[3]);
printf("____|_____|____\n");
printf("    |     |    \n");
printf(" %c  |  %c  | %c  \n",chart[4],chart[5],chart[6]);
printf("____|_____|____\n");
printf("    |     |    \n");
printf("  %c |  %c  | %c  \n",chart[7],chart[8],chart[9]);
printf("    |     |    \n");


}

int winnerdecider(){

if(chart[1]==chart[2] && chart[2]==chart[3])    // when first row is same
return 1;

if(chart[1]==chart[4] && chart[4]==chart[7]) // when first coloumn is same
return 1;

if(chart[7]==chart[8] && chart[8]==chart[9])  //when last row is same
return 1;

if(chart[3]==chart[6] && chart[6]==chart[9]) // when last coloumn is same 
return 1;

if(chart[1]==chart[5] && chart[5]==chart[9]) //when digonal is same 
return 1;

if(chart[3]==chart[5] && chart[5]==chart[7]) // opposite digonal is same 
return 1;

if(chart[2]==chart[5] && chart[5]==chart[8])  //middle row coloumn same
return 1;

if(chart[4]==chart[5] && chart[5]==chart[6])  //middle row is same 
return 1;


int counter=0;
for( i=1;i<=9;i++)

{
     if(chart[i]=='X' || chart[i]=='R')
     counter++;

}
   if (counter==9){
    return 0;
   }

return -1;

}

