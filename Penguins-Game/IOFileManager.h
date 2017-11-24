#include <stdio.h>

extern int currentPlayer;
extern int playerScores[];
extern int numberOfPlayers;
extern int numberOfPenguinPerPlayer;
extern char gamePhase[25];
extern int numberOfMapRows;

extern char mapRows[10][10];

void ReadFromInputFile();
void WriteToOutputFile();
void StrCopy(char*, char*);

void PrintRead()
{
	printf("%d\n\n", 001);


	ReadFromInputFile();
	WriteToOutputFile();

	/*
	printf("%d\n", currentPlayer);

	for (int i = 0; i < numberOfPlayers; i++)
	{
	printf("%s ", playerScores[i]);
	}

	printf("%d\n", numberOfPlayers);
	printf("%d\n", numberOfPenguinPerPlayer);
	printf("%s", gamePhase);
	for (int i = 0; i < numberOfMapRows; i++)
	{
	printf("%s", mapRows[i]);
	}
	*/
}

void ReadFromInputFile()
{
	int line = 0;
	numberOfMapRows = 0;
	FILE* inputFile = fopen("data.bin", "r"); //Open the file for reading
	if (inputFile == NULL) { printf("Error opening file\n"); }
	else { printf("Success opening file\n"); } //Check if the file has been opened
	char tempData[25]; //String where lines of text in the file will be stored temporary

	while (!feof(inputFile)) //Loop through all lines of the text in the file
	{
		fgets(tempData, 25, inputFile);
		//fscanf(inputFile, "%s\n", tempData); //Read the line and store it in the data string

		if (line == 0) {
			currentPlayer = tempData[0] - '0';

			fscanf(inputFile, "%s\n", tempData);
			printf("%s", tempData);

			//playerScores[]
			//StrCopy(tempData, mapRows[numberOfMapRows]);
			//fscanf for i > 5
		}
		if (line == 1) { numberOfPlayers = tempData[0] - '0'; }
		if (line == 2) { numberOfPenguinPerPlayer = tempData[0] - '0'; }
		if (line == 3) { StrCopy(tempData, gamePhase); }
		if (line > 3) { StrCopy(tempData, mapRows[numberOfMapRows]); numberOfMapRows++; }
		line++;
	}
	fclose(inputFile);

}

void WriteToOutputFile()
{
	FILE* outputFile = fopen("data.bin", "w"); //Open the file for reading
	if (outputFile == NULL) { printf("Error opening file\n"); }
	else { printf("Success opening file\n"); } //Check if the file has been opened
	fputs(currentPlayer, outputFile);


	fclose(outputFile);
}


void StrCopy(char* str_1, char* str_2)
{
	while (*str_1 != '\0')
	{
		*str_2 = *str_1++;
		++str_2;
	}
}
