#define MAX_PATH_LENGTH 70
struct PlayerInfo
{
    int numOfLives;       // number of lives player can have in a game
    char charactersymbol; //characters symbol
    int numOfTreasures;  // counter for num of treasures
    int pastEnteredPositions[MAX_PATH_LENGTH]; // array for past positions
} player;