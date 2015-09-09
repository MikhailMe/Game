#pragma once

#define _CRT_SECURE_NO_WARNINGS					// для игнорирования ошибки (использование старой версии strcpy)
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <Windows.h>

using namespace std;

// класс для работы с файлами
class Files
{
private:
	char *filename;								// имя файла
public:
	fstream file;
	void openFile(char *filename, ios_base::openmode mode);
	void closeFile();
};