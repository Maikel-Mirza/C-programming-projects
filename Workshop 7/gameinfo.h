#define MAX_PATH_LENGTH 70
struct GameInfo
{
    int maxNumOfMoves;       // max number of moves a player can make in a game
    int treasures[MAX_PATH_LENGTH]; // array for where treasure is buried along the path
    int pathLength; // array for number of position
    int bombs[MAX_PATH_LENGTH];
} game;