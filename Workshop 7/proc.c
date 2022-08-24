#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MIN_LIVES 1        // min amount of lives a player can have
#define MAX_LIVES 10       // max lives a player can have
#define MULTIPLE_OF_FIVE 5 // used for making sure pathlength is a multiple of 5
#include <stdio.h>
#include <stdlib.h>

struct PlayerInfo
{
    int lives;                     // number of lives player can have in a game
    char icon;                     // characters symbol for player
    int treasuresFound;            // counter for number of treasures found
    char history[MAX_PATH_LENGTH]; // array for past positions
} player;
struct GameInfo
{
    int movesAllowed;                   // max number of moves a player can make in a game
    int treasures[MAX_PATH_LENGTH + 1]; // array for where treasure is buried
    int pathLength;                     // sets the pathlength
    int bombs[MAX_PATH_LENGTH + 1];     // array for where bombs are buried
} game;

int main(void)
{
    struct PlayerInfo player; // playerInfo Structure
    struct GameInfo game;     // gameInfo Structure
    int i;                    // counter used game and treasure arrays
    int k = 1;                // flag
    // these variables are used to print the board options that I want depending on the entered value
    const char undiscovered = '-', bomb = '!', treasure = '$',
               bomb_Treasure = '&', not_bomb_not_treasure = '.';
    int rulerFlag = 0;  // used as a flag when printing board options
    double conditional; // a flag used to print player icon
    int nextMove = 1;   // where a player will input what move they make in the game

    // Player configuration BEGINS
    printf("================================\n");
    printf("Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.icon);
    fseek(stdin, 0, SEEK_END);

    // set the number of lives a player will have in a game
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        fseek(stdin, 0, SEEK_END);
        if ((player.lives < 1) || (player.lives > MAX_LIVES))
        {
            // error message
            printf("     Must be between 1 and %d!\n", MAX_LIVES);
        }
        else
        {
            break;
        }
    } while ((player.lives < 1) || (player.lives > MAX_LIVES));

    for (i = 0; i < MAX_PATH_LENGTH; ++i)
    {
        player.history[i] = 0;
    }
    // Player configuration ENDS

    printf("Player configuration set-up is complete\n");
    printf("\n");
    // game configuration BEGINS
    printf("GAME Configuration\n");
    printf("------------------\n");

    // set the number of positions in a game
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        fseek(stdin, 0, SEEK_END);
        if ((game.pathLength < MIN_PATH_LENGTH) ||
            (game.pathLength > MAX_PATH_LENGTH) ||
            (game.pathLength % MULTIPLE_OF_FIVE != 0))
        // condition must be a multiple of 5
        {
            // error message if outside accepted range
            printf("     Must be a multiple of %d and between %d-%d!!!\n",
                   MULTIPLE_OF_FIVE,
                   MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
        else
        {
            break;
        }
    } while ((game.pathLength < MIN_PATH_LENGTH) ||
             (game.pathLength > MAX_PATH_LENGTH) ||
             (game.pathLength % MULTIPLE_OF_FIVE != 0));
    // used for placing a limit to maxmoves a player can make
    int moveLimit = (double)game.pathLength * 75.0 / 100.0;
    do
    {
        // max moves player can make
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.movesAllowed);
        fseek(stdin, 0, SEEK_END);
        if ((game.movesAllowed < player.lives) || (game.movesAllowed > moveLimit))
        {
            // error message
            printf("    Value must be between %d and %d\n", player.lives, moveLimit);
        }
        else
        {
            break;
        }
    } while ((game.movesAllowed < player.lives) || (game.movesAllowed > moveLimit));
    // value cannot be greater than 0.75% of game path length
    // game configuration ENDS

    // bomb and treasure for loops run for game pathlength divided by 5
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           game.pathLength);
    int steps = game.pathLength / 5;
    int min = 0;                // min position
    int max = 5;                // max position
    for (i = 0; i < steps; ++i) // runs bomb positions for game pathlength/5
    {
        printf("Positions [%2d-%2d]: ", min + 1, max);
        scanf("%d %d %d %d %d", &game.bombs[min], &game.bombs[(min) + 1],
              &game.bombs[(min) + 2], &game.bombs[(min) + 3], &game.bombs[(min) + 4]);
        min += 5; // accumulates min by 5 to get the right positions along the path
        max += 5; // accumulates max by 5 to get the right positions along the path
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           game.pathLength);
    // reusing the steps calculation and position values
    steps = game.pathLength / 5;
    min = 0;
    max = 5;
    for (i = 0; i < steps; ++i) // runs treasure positions for game pathlength/5
    {
        printf("Positions [%2d-%2d]: ", min + 1, max);
        scanf("%d %d %d %d %d", &game.treasures[min], &game.treasures[(min) + 1],
              &game.treasures[(min) + 2], &game.treasures[(min) + 3], &game.treasures[(min) + 4]);
        min += 5; // accumulates min by 5 to get the right positions along the path
        max += 5; // accumulates max by 5 to get the right positions along the path
    }
    // printout of configuration settings
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    // two members initialized from playerinfo - character, lives
    printf("Player:\n");
    printf("Symbol : %c\n", player.icon);
    printf("Lives : %d\n", player.lives);
    printf("Treasure : [ready for gameplay]\n");
    printf("History : [ready for gameplay]\n\n");
    // three members initialized from gameinfo - length, bombs, treasures
    printf("Game:\n");
    printf("Path Length: %d\n", game.pathLength);
    printf("Bombs : ");
    for (i = 0; i < game.pathLength; ++i)
    {
        printf("%d", game.bombs[i]); // bomb inputs will be printed
    }
    printf("\n");
    printf("Treasure : ");
    for (i = 0; i < game.pathLength; ++i)
    {
        printf("%d", game.treasures[i]); // treasure inputs will be printed
    }

    // treasure hunt banner
    // Main loop begins
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    conditional = 0;
    player.treasuresFound = 0; // starts from 0

    while (1) // main loop of program that runs till lives/moves expire
    {
        if (conditional == 0)
            ++conditional;
        else
        {
            printf("\n");
            for (i = 0; i < game.pathLength; i++)
            {
                if (player.history[i] == 1 && i == (nextMove - 1))
                {
                    printf("%c", player.icon); // character symbol for game
                }
                else
                    printf(" ");
            }
        }
        printf("\n");
        for (i = 0; i < game.pathLength; i++) // this is how the different board options get printed
        {
            if (player.history[i] == 0)
                printf("%c", undiscovered);
            else if (game.bombs[i] == 1 && game.treasures[i] == 1)
            {
                printf("%c", bomb_Treasure);
            }
            else if (game.bombs[i] == 1)
            {
                printf("%c", bomb);
            }
            else if (game.treasures[i] == 1)
            {
                printf("%c", treasure);
            }
            else
                printf("%c", not_bomb_not_treasure);
        }
        printf("\n");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                ++rulerFlag;
                printf("%d", rulerFlag);
            }
            else
                printf("|"); // the rulers line marker
        }
        rulerFlag = 0;
        printf("\n");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("0");
                k = 1;
            }
            else
                printf("%d", k++);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", player.lives, player.treasuresFound, game.movesAllowed);
        printf("+---------------------------------------------------+\n");
        if (player.lives == 0 || game.movesAllowed == 0)
            break; // exit if there are no lives or moves

        while (1) // loop sets player position in game
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &nextMove); // what position
            if (nextMove < 1 || nextMove > game.pathLength)
                printf("Out of Range!!!\n"); // error if out of range
            else
                break; // exit if correct
        }

        if (player.history[nextMove - 1] == 1)
        {
            // if you go to the same position more than once
            printf("\n===============> Dope! You've been here before!\n");
        }
        else
        {
            player.history[nextMove - 1] = 1;
            game.movesAllowed -= 1;

            if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 1)
            {
                player.lives -= 1;
                player.treasuresFound += 1;
                // bomb and treasure in same location
                printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", bomb_Treasure, bomb_Treasure);
                printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]\n", bomb_Treasure, bomb_Treasure);
                if (player.lives == 0)
                {
                    // print this when lives run out
                    printf("\nNo more LIVES remaining!\n");
                }
                else if (game.movesAllowed == 0)
                    // print this when moves run out
                    printf("\nNo more MOVES remaining!\n");
            }
            else if (game.bombs[nextMove - 1] == 1)
            {
                player.lives -= 1;
                // there is a bomb
                printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n",
                       bomb, bomb);
                if (player.lives == 0)
                {
                    // print this when lives run out
                    printf("\nNo more LIVES remaining!\n");
                }
                else if (game.movesAllowed == 0)
                    // no more moves
                    printf("\nNo more MOVES remaining!\n");
            }
            else if (game.treasures[nextMove - 1] == 1)
            {
                player.treasuresFound += 1;
                // you find treasure
                printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n", treasure, treasure);
            }
            else
            {
                // you find nothing
                printf("\n===============> [%c] ...Nothing found here... [%c]\n", not_bomb_not_treasure, not_bomb_not_treasure);
            }
        }
    }

    // Main loop ends
    // print game over banner
    printf("\n##################");
    printf("\n# Game over!#");
    printf("\n##################\n");
    printf("\nYou should play again and try to beat your score!\n");
    return 0;
}
