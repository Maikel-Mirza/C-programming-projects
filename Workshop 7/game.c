/*
  *****************************************************************************
                            Workshop - #7 (Part-2)
  Full Name  :    Maikel Mirzadegan
  Student ID#:    032299158
  Email      :    mmirzadegan@senecacollege.ca
  Section    :    NPP


  Authenticity Declaration:
  I declare this submission is the result of my own work and has not been
  shared with any other student or 3rd party content provider. This submitted
  piece of work is entirely of my own creation.
  *****************************************************************************
*/
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
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

// void printStats(struct PlayerInfo *pi, struct GameInfo *gi, int lastMove, int movesLeft);

int main()
{
  struct PlayerInfo player; // playerInfo Structure
  struct GameInfo game;     // gameInfo Structure
  int i, k = 1;             // counter used game and treasure arrays
  const char undiscovered = '-', bomb = '!', treasure = '$', bothbat = '&', neitherbat = '.';
  int flag = 0;
  double temp;
  int movePosition = 1;

  // Player configuration
  printf("================================\n");
  printf("         Treasure Hunt!\n");
  printf("================================\n\n");
  printf("PLAYER Configuration\n");
  printf("--------------------\n");
  printf("Enter a single character to represent the player: ");
  scanf(" %c", &player.icon); // symbol represents player character
  fseek(stdin, 0, SEEK_END);

  // set the number of lives a player will have in a game
  do
  {
    printf("Set the number of lives: ");
    scanf("%d", &player.lives);

    if (!(player.lives > 0 && player.lives <= 10))
    {
      printf("     Must be between 1 and 10!\n"); // error message
    }

  } while (!(player.lives > 0 && player.lives <= 10));
  for (i = 0; i < MAX_PATH_LENGTH; i++)
  {
    player.history[i] = 0;
  }

  printf("Player configuration set-up is complete\n\n");

  // game configuration
  printf("GAME Configuration\n");
  printf("------------------\n");

  // set the number of positions in a game
  do
  {
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &game.pathLength);
    fseek(stdin, 0, SEEK_END);
    if (!(game.pathLength >= MIN_PATH_LENGTH && game.pathLength <= MAX_PATH_LENGTH && game.pathLength % 5 == 0))
    // condition must be a multiple of 5
    {
      // error message if outside accepted range
      printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }
  } while (!(game.pathLength >= MIN_PATH_LENGTH && game.pathLength <= MAX_PATH_LENGTH && game.pathLength % 5 == 0));

  do
  {
    // max moves player can make
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.movesAllowed);
    fseek(stdin, 0, SEEK_END);
    if (!(game.movesAllowed >= player.lives && game.movesAllowed < (0.75 * game.pathLength)))
    {
      printf("    Value must be between 3 and 26\n"); // error message
    }
  } while (!(game.movesAllowed >= player.lives && game.movesAllowed < (0.75 * game.pathLength)));
  // value cannot be greater than 0.75% of game path length

  // bomb and treasure for loops run for game pathlength divided by 5
  int steps = game.pathLength / 5;
  int min = 1; // min position
  int max = 5; // max position
  printf("\nBOMB Placement\n");
  printf("--------------\n");
  printf("Enter the bomb positions in sets of 5 where a value\n"
         "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
         "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
         game.pathLength);
  for (i = 0; i < steps; i++) // runs bomb positions for game pathlength/5
  {
    printf("   Positions [%2d-%2d]: ", min, max);
    scanf("%d %d %d %d %d", &game.bombs[min], &game.bombs[(min) + 1],
          &game.bombs[(min) + 2], &game.bombs[(min) + 3], &game.bombs[(min) + 4]);
    min += 5; // accumulates min by 5 to get the right positions along the path
    max += 5; // accumulates max by 5 to get the right positions along the path
  }
  printf("BOMB placement set\n");
  printf("\nTREASURE Placement\n");
  printf("------------------\n");
  printf("Enter the treasure placements in sets of 5 where a value\n"
         "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
         "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
         game.pathLength);

  // reusing the steps calculation and position values
  steps = game.pathLength / 5;
  min = 1;
  max = 5;
  for (i = 0; i < steps; i++) // runs treasure positions for game pathlength/5
  {
    printf("   Positions [%2d-%2d]: ", min, max);
    scanf("%d %d %d %d %d", &game.treasures[min], &game.treasures[(min) + 1],
          &game.treasures[(min) + 2], &game.treasures[(min) + 3], &game.treasures[(min) + 4]);
    min += 5; // accumulates min and max positions numbers along the path by 5
    max += 5;
  }
  // printout of configuration settings
  printf("TREASURE placement set\n\n");
  printf("GAME configuration set-up is complete...\n\n");
  printf("------------------------------------\n");
  printf("TREASURE HUNT Configuration Settings\n");
  printf("------------------------------------\n");
  // two members initialized from playerinfo - character, lives
  printf("Player:\n");
  printf("   Symbol     : %c", player.icon);
  printf("\n   Lives      : %d", player.lives);
  printf("\n   Treasure   : [ready for gameplay]\n");
  printf("   History    : [ready for gameplay]\n\n");
  // three members initialized from gameinfo - length, bombs, treasures
  printf("Game:\n");
  printf("   Path Length: %d\n", game.pathLength);
  printf("   Bombs      : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.bombs[i]); // bomb inputs will be printed
  }
  printf("\n   Treasure   : ");
  for (i = 0; i < game.pathLength; i++)
  {
    printf("%d", game.treasures[i]); // treasure inputs will be printed
  }
  // treasure hunt banner
  // Main loop begins
  int movesCounter = 0;
  printf("\n\n====================================\n");
  printf("~ Get ready to play TREASURE HUNT! ~\n");
  printf("====================================\n");
  temp = 0;
  player.treasuresFound = 0;
  while (1)
  {
    if (temp == 0)
      ++temp;
    else
    {
      printf("\n");
      for (i = 0; i < game.pathLength; i++)
      {
        if (player.history[i] == 1 && i == (movePosition - 1))
        {
          printf("%c", player.icon);
        }
        else
          printf(" ");
      }
    }
    printf("\n");
    for (i = 0; i < game.pathLength; i++)
    {
      if (player.history[i] == 0)
        printf("%c", undiscovered);
      else if (game.bombs[i] == 1 && game.treasures[i] == 1)
      {
        printf("%c", bothbat);
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
        printf("%c", neitherbat);
    }
    printf("\n");
    for (i = 0; i < game.pathLength; i++)
    {
      if ((i + 1) % 10 == 0)
      {
        ++flag;
        printf("%d", flag);
      }
      else
        printf("|");
    }
    flag = 0;
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
      break;
    while (1)
    {
      printf("Next Move [1-%d]: ", game.pathLength);
      scanf("%d", &movePosition);
      if (movePosition < 1 || movePosition > game.pathLength)
        printf("Out of Range!!!\n");
      else
        break;
    }
    if (player.history[movePosition - 1] == 1)
    {
      printf("\n===============> Dope! You've been here before!\n");
    }
    else
    {
      player.history[movePosition - 1] = 1;
      game.movesAllowed -= 1;
      if (game.bombs[movePosition - 1] == 1 && game.treasures[movePosition - 1] == 1)
      {
        player.lives -= 1;
        player.treasuresFound += 1;
        printf("\n===============> [%c] !!! BOOOOOM !!! [%c]", bothbat, bothbat);
        printf("\n===============> [%c] $$$ Life Insurance Payout!!! [%c]\n", bothbat, bothbat);
        if (player.lives == 0)
          printf("\nNo more LIVES remaining!\n");
        else if (game.movesAllowed == 0)
          printf("\nNo more MOVES remaining!\n");
      }
      else if (game.bombs[movePosition - 1] == 1)
      {
        player.lives -= 1;
        printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n", bomb, bomb);
        if (player.lives == 0)
          printf("\nNo more LIVES remaining!\n");
        else if (game.movesAllowed == 0)
          printf("\nNo more MOVES remaining!\n");
      }
      else if (game.treasures[movePosition - 1] == 1)
      {
        player.treasuresFound += 1;
        printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n", treasure, treasure);
      }
      else
      {
        printf("\n===============> [%c] ...Nothing found here... [%c]\n", neitherbat, neitherbat);
      }
    }
  }
  // Main loop ends
  printf("##################\n");
  printf("#   Game over!   #\n");
  printf("##################\n\n");
  printf("You should play again and try to beat your score!!\n");

  return 0;
}