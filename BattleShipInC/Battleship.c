#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Battleship.h"




// Main Function
int main ()

{
//list of define variables
//Players
short player = 0;
short shot = 0;
int menuSelect = 0;

//Directions
int north = 0;
int south = 0;
int east = 0;
int west = 0;

//counters
int i = 0;
int counter = 0;
char shipSymbol = '\0';

//new vars
Player playerOne;
Player playerTwo;


char enter;

srand(time(0));



//Funtions with clears in between
    welcomeScreen ();

//clear screen
    clearScreen();

//Player one initialization
    initializePlayer(&playerOne, PLAYERONE);



//clear screen
    clearScreen();

//player two initialization
    initializePlayer(&playerTwo, PLAYERTWO);



//clears screen
    clearScreen();


//call Menu
    menuSelect = displayMenu();

//clear screen
    clearScreen();
//switch for manual or random

    switch (menuSelect)
    {

        //prints if 1 is chosen
    case MANUAL:

        printf("%s selected to place the ships manually\n",playerOne . name);
        manualShipPlace(&playerOne);


        break;
        //prints if 2 is chosen
    case RANDOM:

        printf("%s selected to place the ships randomly\n",playerOne . name);
        randomShipPlace(&playerOne);


        break;

    }
        randomShipPlace(&playerTwo);

        //displayGameBoard(playerOne);

        //displayGameBoard(playerTwo);

        playGame(&playerOne, &playerTwo);


    return 0;




//End functions

    return 0;
}

// Welcome Screen Function
void welcomeScreen()
{

// String of printF statements
    printf("BBBBB    AAAA   TTTTTT  TTTTTT   LL      EEEEEE  SSSSS   HH  HH  II  PPPP\n");
    printf("BB  BB  AA  AA    TT      TT     LL      EE     SS       HH  HH  II  PP  PP\n");
    printf("BBBB    AA  AA    TT      TT     LL      EEEE    SSSSS   HHHHHH  II  PPPP\n");
    printf("BB  BB  AAAAAA    TT      TT     LL      EE          SS  HH  HH  II  PP\n");
    printf("BBBBB   AA  AA    TT      TT     LLLLLL  EEEEEE  SSSSS   HH  HH  II  PP\n");
    printf(" \n");
    printf(" \n");
    printf("Rules of the game: \n");
    printf("1. This is a two player game \n");
    printf("2. Player 1 is you and Player 2 is the computer \n");
    printf("3. Player 1 will be prompted if user want to manually input coordinates\n");
    printf("   for the game board or have the computer randomly generate a game board \n");
    printf("4. There are five types of ships to be placed by longest length to the \n");
    printf("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser \n");
    printf("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells \n");
    printf("5. The computer randomly generates which player goes first \n");
    printf("6. The game begins as each player tries to guess the location of the ships \n");
    printf("   of the opposing player's game board; [x] hit and [~] miss \n");
    printf("7. First player to guess the location of all ships wins \n");
    printf("\n");

   // Tells user to hit enter and will clear to next function
    printf("                                Hit <Enter> to continue\n");


    //Variable
    char e;
    //scanf to store input
    scanf("%c", &e);
    printf("user entered %c", e);

    }

    //Menu function
int displayMenu()
{
    //variable
    int select;

    //while statement for menu selection
    while ((select != MANUAL)&&(select != RANDOM))
           {
                //String of printf statements for menu
    printf("Select the option for human player ship placement:\n");
    printf("[1] Manually\n");
    printf("[2] Randomly\n");
    printf("Enter option:\n");

    //Stores selection
    select = getchar();

    //prevent any value other than 1 or 2 from bringing up game board
    if ((select != MANUAL)&&(select != RANDOM))
        //tells player selection was invalid
        printf("Invalid option. Please try again\n");

        fflush(stdin);
           }


//end function
    return (select);
}

//Game Board function
void displayGameBoard(Player player)
{
    //loop variables
    int row;
    int col;

        //unsure how to generate player 2 as needed. Sorry.
        printf("\n");
        printf("%s's Game Board\n",player . name);
        printf("\n");



    //String of printf statements for board
    printf("---------------------------------------------\n");
    printf("|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n");
    printf("---------------------------------------------\n");

    for (row = 0;row < ROWS; row++){
        printf("| %d ", row);

        for (col = 0; col < COLS; col++){
                printf("| %c ",player.gameBoard.board[row][col]);

        }
                printf("\n");
        }
    printf("---------------------------------------------\n");




//end function
return;
}

//clear function
void clearScreen()
{
   system("cls");
   //system("clear");

   return;
}


void initializeBoard(Player * player)
{
    memset(player -> gameBoard.board, WATER, sizeof(player -> gameBoard.board));
}

//Initializes player
void initializePlayer(Player * player, char * name)
{   //user puts in name
   char playerName[20];
   GameBoard playerBoard;
   Ship ships[NUM_SHIPS];
   printf("Enter %s's name\n", name);
   gets(playerName);
//stores player name
   strcpy(player -> name, playerName);
   player -> gameBoard = playerBoard;
   memcpy(player -> ships, ships, NUM_SHIPS);
//board
   initializeBoard(player);
   //displayGameBoard(*player);
   //getchar();
   clearScreen();
//ship
   initializeShips(player);
   //displayShips(*player);
   //getchar();


return;
}
//Display Ships function
void displayShips(Player player)
{
    int shipNum;
    printf("%s's Ship Data\n\n", player.name);
    for (shipNum = 0; shipNum < NUM_SHIPS; shipNum++)
    {   //print statements for ship info
        printf("Name: %s\n", player.ships[shipNum].name);
        printf("Length: %d\n", player.ships[shipNum].length);
        printf("Symbol: %c\n", player.ships[shipNum].symbol);
        printf("Is sunk: %s\n", ((player.ships[shipNum].sunk)?"True":"False"));
        printf("Location: row: %d col: %d\n\n", player.ships[shipNum].start.row,player.ships[shipNum].start.col);
    }
}
//initialize ships
void initializeShips(Player * player)
{

    int shipNum;
    for (shipNum =0; shipNum < NUM_SHIPS; shipNum++)
    {
        Ship boat;
        //switch for ship info
        switch (shipNum)
        {

            case battleship:
            strcpy(boat.name, "BATTLESHIP");
            boat.length = BATTLESHIP_SZ;
            boat.symbol = BATTLESHIP;
            break;

            case carrier:
            strcpy(boat.name, "CARRIER");
            boat.length = CARRIER_SZ;
            boat.symbol = CARRIER;
            break;

            case cruiser:
            strcpy(boat.name, "CRUISER");
            boat.length = CRUISER_SZ;
            boat.symbol = CRUISER;
            break;

            case destroyer:
            strcpy(boat.name, "DESTROYER");
            boat.length = DESTROYER_SZ;
            boat.symbol = DESTROYER;
            break;

            case submarine:
            strcpy(boat.name, "SUBMARINE");
            boat.length = SUBMARINE_SZ;
            boat.symbol = SUBMARINE;
            break;
        }

        boat.sunk = false;
        boat.start.col = -1;
        boat.start.row = -1;
        player->ships[shipNum] = boat;

    }

}
bool isValid(Player player, int row, int col, int length, char orient)
{
int loopRow; //Row loop variable
int loopCol; //column loop variable
bool valid = true;

if((row<0 || (row + length)>9))
    return false;

if((col<0 || (col + length)>9))
    return false;

if(orient != 'H' && orient != 'V')
    return false;

switch(orient)
{
case HORIZONTAL:
    for(loopCol=col; loopCol< (length + col); loopCol++)
    {
        if (player.gameBoard.board[row][loopCol] != WATER)
        {
            return false;
        }
    }
    break;

case VERTICAL:
    for(loopRow=row; loopRow<(length + row);loopRow++)
    {
        if(player.gameBoard.board[loopRow][col] != WATER)
        {
            return false;
        }
    }
    break;
}
return valid;
}
void placeShip(Player * player, int row, int col, Ship ship, char orient)
{
int loopRow; //Row loop variable
int loopCol; //column loop variable



switch(orient)
{
case HORIZONTAL:
    for(loopCol=col; loopCol<(ship.length + col); loopCol++)
    {
        player->gameBoard.board[row][loopCol] = ship.symbol;
    }
    break;

    case VERTICAL:
    for(loopRow=row; loopRow<(ship.length + row); loopRow++)
    {
        player->gameBoard.board[loopRow][col] = ship.symbol;
    }
    }
}
void manualShipPlace(Player * player)
{
int shipNum;
int row;
int col;
char orient;

bool valid = false;

for(shipNum = 0; shipNum<NUM_SHIPS; shipNum++)
{
    while (valid == false)
    {
        displayGameBoard(*player);
        printf("Enter the row and col (e.g. 0 0) for the first cell of ship %s:\n", player->ships[shipNum].name);
        printf("Row col ");
        scanf("%d %d", &row, &col);

        fflush(stdin);

        printf("What is the orientation for this ship? Enter H for horizontal, V for vertical\n");
        scanf("%c", &orient);
        orient = toupper(orient);

        printf("Checking row %d orient %c...\n", row, col, orient);

        valid = isValid(*player, row, col, player->ships[shipNum].length, orient);

        if(valid)
        {
            placeShip(player, row, col, player->ships[shipNum], orient);

        }
        else
        {
            valid = false;
            printf("Invalid, try again\n");
        }
        }
        valid = false;
        }
}
void randomShipPlace(Player * player)
{
    int shipNum;
    int row;
    int col;
    int const DIR = 2;
    int const H = 0;
    int const V = 1;
    char orient;
    int rdm;

    bool valid = false;

    fflush(stdin);

    for (shipNum = 0; shipNum<NUM_SHIPS; shipNum++)
    {
        while (valid == false)
        {
            row = (rand() %ROWS);
            col = (rand() %COLS);
            rdm  = (rand() %DIR);

            if(rdm == H)
                orient = HORIZONTAL;
            else if( rdm == V)
                orient = VERTICAL;

            valid = isValid(*player, row, col, player->ships[shipNum].length, orient);

            if (valid)
            {
                placeShip(player, row, col, player->ships[shipNum], orient);

            }
        }
        valid = false;

    }
}



//initiates game
void playGame(Player * playerOne, Player * playerTwo)
{

  int currentPlayer = PLAYER1;
  Location target;

  while (true)
  {
     switch (currentPlayer)
     {
         case PLAYER1:

                printf("%s's turn!\n", playerOne->name);
                displayGameBoard(*playerOne);
                //get target from player
                target = getTarget(*playerOne);
                checkShot(playerTwo, target);

                break;

           case PLAYER2:

                printf("%s's turn!", playerTwo->name);
                target = getRandomTarget();
                checkShot(playerOne, target);

                break;
     }

         currentPlayer = switchPlayer(currentPlayer);


         clearScreen();

     }


}
//switches players between rounds
int switchPlayer(int currentPlayer)
{
    if(currentPlayer == PLAYER1)
        return PLAYER2;

    else if(currentPlayer == PLAYER2)
        return PLAYER1;

}


Location getTarget(Player player)
{

    Location target;

    fflush (stdin);

    printf("%s Enter Target as row and col (ie. 2 4): ", player.name);

    scanf("%d %d", &target.row, &target.col);

    fflush(stdin);

    return target;

}


Location getRandomTarget()
{
    Location target;

    target.row = (rand() % ROWS);
    target.col = (rand() % COLS);

    return target;

}

void checkShot(Player * player, Location target)
{
    char symbol = player->gameBoard.board[target.row][target.col];

    switch(symbol)
    {
        case WATER:

            printf(" Row %d Col %d was a Miss!", target.row, target.col);
            getchar();
            updatePlayerData(player, target, MISS, symbol);

            break;

        //Order of HIT check
        case BATTLESHIP:
        case CARRIER:
        case CRUISER:
        case DESTROYER:
        case SUBMARINE:

            printf(" Row %d Col %d was a Hit!", target.row, target.col);
            getchar();
            updatePlayerData(player, target, HIT, symbol);

            break;

        case HIT:
        case MISS:
        default:

            printf(" Already guessed that location, you lost a turn!\n");
            getchar();

            break;

    }

}

void updatePlayerData(Player * player, Location location, char result ,char ship)
{
    player->gameBoard.board[location.row][location.col] = result;

    if (result == HIT)
    {
        checkShips(player, location, ship);
    }

}

void checkShips(Player * player, Location location, char ship)
{
    const int battleshipIdx = 0;
    const int carrierIdx = 1;
    const int cruiserIdx = 2;
    const int destroyerIdx = 3;
    const int submarineIdx = 4;

    int sunkCount = 0;
    int shipNum;

    switch(ship)
    {
        case BATTLESHIP:

            player->ships[battleshipIdx].length--;

            if(player->ships[battleshipIdx].length == 0)
                printf("%s's BATTLESHIP is sunk!", player->name);

            getchar();

            break;

        case CARRIER:

            player->ships[carrierIdx].length--;

            if(player->ships[carrierIdx].length == 0)
                printf("%s's CARRIER is sunk!", player->name);

            getchar();

            break;

        case CRUISER:

            player->ships[cruiserIdx].length--;

            if (player->ships[cruiserIdx].length == 0)
                printf("%s's CRUISER is sunk!", player->name);

            getchar();

            break;

        case DESTROYER:

            player->ships[destroyerIdx].length--;

            if (player->ships[destroyerIdx].length == 0)
                printf("%s's DESTROYER is sunk!", player->name);

            getchar();

            break;

        case SUBMARINE:

            player->ships[submarineIdx].length--;

            if (player->ships[submarineIdx].length == 0)
                printf("%s's SUBMARINE is sunk!", player->name);

            getchar();

            break;
    }

    for(shipNum = 0; shipNum < NUM_SHIPS; shipNum++)
    {
        if(player->ships[shipNum].length == 0)
            sunkCount++;

        if(sunkCount == NUM_SHIPS)
            endGame(*player);
    }

}
//ends game
void endGame(Player player)
{
    printf("%s has lost this game!", player.name);
    getchar();


    exit(0);

}




