#include <stdio.h>
#include "IOFileManager.h" //Header with reading and writing IO file functions

//Data from input file
int currentPlayer;
int playerScores[];
int numberOfPlayers;
int numberOfPenguinPerPlayer;
char gamePhase[25];

int numberOfMapRows;
char mapRows[10][10];

//Functions 
void IncreaseCurrentPlayerIndex();

int main()
{
	//READ VALUES FROM OUTPUTFILE() (function in IOFileManager.h)
	//PRINT THE MAP(mapRows) (optional)

	if (gamePhase == "placement")
	{
		int p;
		for (p = 0; p < numberOfPenguinPerPlayer; p++)
		{
			//PLACE PENGUIN(p)
		}

		if (currentPlayer == numberOfPlayers)
		{
			//CHANGE GAMEPHASE TO MOVEMENT()
		}
	}
	else if (gamePhase == "movement")
	{
		int p;
		for (p = 0; p < numberOfPenguinPerPlayer; p++)
		{
			int ways; //= FIND POSSIBLE WAYS OF MOVEMENT FOR PENGUIN()
			if (ways > 0)
			{
				//FIND THE BEST WAY FOR PENGUIN(p)
				//MOVE PENGUIN(p) (1. Collect fish from the current tile(change playerScores[] 2. Place penguin on next tile(change mapRows[][] data))
			}
			else
			{
				//penguin is blocked - move next penguin or end this turn if all other penguins were moved already
			}
		}
	}

	IncreaseCurrentPlayerIndex(); //Increase current player index (Read David's concept)
								  //CREATE OUTPUT FILE() (function in IOFileManager.h)
	return 0;

}


void IncreaseCurrentPlayerIndex()
{
	if (currentPlayer == 0)
	{
		currentPlayer = 2; //Double incremantation (Read David's concept)
	}
	else
	{
		if (currentPlayer == numberOfPlayers)
		{
			currentPlayer = 1;
		}
		else
		{
			currentPlayer++;
		}
	}
}

