#include <stdio.h>
#include <string.h>
#include "IOFileManager.h"


extern int currentPlayer;
extern int playersScores[10]; //1,2,3,... not 0,1,2,3,...
extern int numberOfPlayers;
extern int numberOfPenguinPerPlayer;
extern int numberOfPlacedPenguins;
extern char gamePhase[25];
extern int numberOfMapRows;

extern char map[20][20];

char scoresRow[25];

void Debug()
{
	/*
	printf("%d\n", currentPlayer);
	for (int i = 0; i < numberOfPlayers; i++) { printf("%s ", playerScores[i]); }
	printf("%d\n", numberOfPlayers);
	printf("%d\n", numberOfPenguinPerPlayer);
	printf("%s", gamePhase);
	for (int i = 0; i < numberOfMapRows; i++) { printf("%s", mapRows[i]); }
	*/
}

void ReadDataFromInputFile() //Loop through all lines of the InputFile and assign data to the variables // MATEUSZ SZYMOÑSKI
{
	int line = 0;
	numberOfMapRows = 0;
	FILE* inputFile = fopen("data.bin", "r"); //Open the file for reading
	if (inputFile == NULL) { printf("Error opening file\n"); }
	else { printf("Success opening file\n"); } //Check if the file has been opened
	char tempData[25]; //String where lines of text in the file will be stored temporary

	while (!feof(inputFile))
	{
		fgets(tempData, 25, inputFile);
		if (line == 0) { currentPlayer = tempData[0] - '0'; StrCopy(tempData, scoresRow); }
		if (line == 1) { numberOfPlayers = tempData[0] - '0'; ReadPlayersScores(); }
		if (line == 2) { numberOfPenguinPerPlayer = tempData[0] - '0'; }
		if (line == 3) { StrCopy(tempData, gamePhase); }
		if (line > 3) { StrCopy(tempData, map[numberOfMapRows]); numberOfMapRows++; }
		line++;
	}
	fclose(inputFile);

	int r; for (r = 0; r < numberOfMapRows; r++) //Find number of penguins on map
	{	
		int c; for (c = 0; c < 20; c++)
		{		
			if (map[r][c] != NULL && map[r][c] != ' ' && !isdigit(map[r][c])) { numberOfPlacedPenguins++; }
		}		
	}
	numberOfPlacedPenguins -= numberOfMapRows;

}

void ReadPlayersScores() //Read players scores from IOFile to playersScoresArray (
{
	int i;
	for (i = 1; i < numberOfPlayers + 1; i++)
	{
		int a, b = 0;
		a = scoresRow[i * 3 - 1] - '0';
		b = scoresRow[i * 3] - '0';
		playersScores[i] = a * 10 + b;
	}
}

void WriteDataToOutputFile()
{
	/*
	FILE* outputFile = fopen("data.bin", "w"); //Open the file for reading
	if (outputFile == NULL) { printf("Error opening file\n"); }
	else { printf("Success opening file\n"); } //Check if the file has been opened

	//
	// fputs(currentPlayer, outputFile);
	// To complete
	//

	fclose(outputFile);
	*/
}


