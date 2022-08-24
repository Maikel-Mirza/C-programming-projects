/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Maikel Mirzadegan
	ID     : 032299158
	Email  : mmirzadegan@senecacollege.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATHLENGTH 70
#define MIN_PATHLENGTH 10
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PlayerInfo {
	int numOfLives;
	char characterSymbol;
	int numOfTreasures;
};

struct GameInfo {
	int numOfMoves;
	int pathLength;
};


int main()
{
	
	int bomb[MAX_PATHLENGTH];
	int treasure[MAX_PATHLENGTH];

	printf("================================");
	printf("\n");
	printf("         Treasure Hunt!\n");
	printf("================================");
	printf("\n\n");
	printf("PLAYER Configuration");
	printf("\n");
	printf("--------------------");
	printf("\n");
	
	struct PlayerInfo player;
	int i=0; //counter
	
	
		printf("Enter a single character to represent the player: ");
		scanf(" %c", &player.characterSymbol);
		do
		{
			i++;
			printf("Set the number of lives: ");
			scanf(" %d", &player.numOfLives);
			if (player.numOfLives < 1)
			{
				printf("     Must be between 1 and 10!\n");
			}

			else if (player.numOfLives > 10)
			{
				printf("     Must be between 1 and 10!\n");
			}


		} while (!(player.numOfLives >= 1  && player.numOfLives <=10));

		printf("Player configuration set-up is complete\n");

		struct GameInfo game;

		printf("\n");
		printf("GAME Configuration");
		printf("\n");
		printf("------------------");
		printf("\n");

		do
		{
			printf("Set the path length (a multiple of 5 between 10-70): ");
			scanf(" %d", &game.pathLength);
			
			if (!(game.pathLength >= 10 && game.pathLength <= 70 && game.pathLength % 5 == 0))
				printf("    Must be a multiple of 5 and between 10-70!!!\n");

		} while (!(game.pathLength >= 10 && game.pathLength <= 70 && game.pathLength%5==0));

		do 
		{
			printf("Set the limit for number of moves allowed: ");
			scanf(" %d", &game.numOfMoves);

			if (!(game.numOfMoves >= player.numOfLives && game.numOfMoves <= 0.75 * game.pathLength))
				printf("    Value must be between %d and %d\n", player.numOfLives, (int)(0.75 * game.pathLength));


		} while (!(game.numOfMoves >= player.numOfLives && game.numOfMoves <= 0.75 * game.pathLength));
		printf("\nBOMB Placement\n");
		printf("--------------\n");
		printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	
		for (i=0; i<= 6; i++)
		{
			printf("   Positions [%2d-%2d]: ", (i*5)+1, (i+1) *5);
			scanf("%d %d %d %d %d", &bomb[i*5], &bomb[(i * 5) +1], &bomb[(i * 5) + 2], &bomb[(i * 5) + 3], &bomb[(i * 5) + 4]);
		}
		printf("BOMB placement set\n\n");
		printf("TREASURE Placement\n");
		printf("--------------\n");
		printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");


		for (i=0; i<= 6; i++)
		{
			printf("   Positions [%2d-%2d]: ", (i*5) + 1, (i+1) * 5);
			scanf("%d %d %d %d %d", &treasure[i*5], &treasure[(i * 5) + 1], &treasure[(i * 5) + 2], &treasure[(i * 5) + 3], &treasure[(i * 5) + 4]);
		}
		printf("TREASURE placement set\n\n");
		printf("\nGAME configuration set-up is complete...\n\n");
		printf("------------------------------------\n");
		printf("TREASURE HUNT Configuration Settings\n");
		printf("------------------------------------\n");
		printf("Player:\n");
		printf("   Symbol    : %c\n", player.characterSymbol);
		printf("   Lives     : %d\n", player.numOfLives);
		printf("   Treasure  : [ready for gameplay]\n");
		printf("   History   : [ready for gameplay]\n");
		printf("\n");
		printf("Game:\n");
		printf("   Path Length: %d\n", game.pathLength);
		
		printf("   Bombs      : ");
				for (i = 0; i < game.pathLength; i++)
				{
					printf("%d", bomb[i]);

				}
			printf("\n");
			printf("   Treasure   : ");
			for (i = 0; i < game.pathLength; i++)
			{
				printf("%d", treasure[i]);

			}
		
		printf("\n\n");
		printf("====================================\n");
		printf("~ Get ready to play TREASURE HUNT! ~\n");
		printf("====================================\n");

	return 0;
}


