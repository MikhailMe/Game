#pragma once

#define _CRT_SECURE_NO_WARNINGS					// ��� ������������� ������ (������������� ������ ������ strcpy)
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <Windows.h>

using namespace std;

// ����� ��� ������ � �������
class Files
{
private:
	char *filename;								// ��� �����
public:
	fstream file;
	void openFile(char *filename, ios_base::openmode mode);
	void closeFile();
};