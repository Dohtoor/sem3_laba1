// sem3_laba1.cpp 
// Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void deleteAfter(char* fBuffer) //функция для удаления текста после первой точки
{
	int index, i = 0;
	bool found = false;

	while ((fBuffer[i] != '\0') && (fBuffer[i] != '\n'))
	{
		if (fBuffer[i] == '.')
		{
			index = i;
			found = true;
			break;
		}
		i++;
	}

	if (!found)							//если точки нет, выходим из функции
		return;
	fBuffer[index + 1] = '\n';			//стираем после точки
	fBuffer[index + 2] = '\0';
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *inFile;
	inFile = fopen("file1.txt", "rt");
	if (inFile == NULL)
	{
		cout << "File doesn't exist";
		system("pause");
		return 0;
	}

	char buffer[256];
	FILE *outFile;
	outFile = fopen("file2.txt", "w");


	while (fgets(buffer, 256, inFile) != NULL)
	{
		deleteAfter(buffer);							//вызываем функцию
		fputs(buffer, outFile);							//записываем полученую строку в файл
	}

	fclose(inFile);
	fclose(outFile);
	return 0;
}

