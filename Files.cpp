#include "Files.h"

//�������� �����
void Files::openFile(char *filename,				// ��� �����
					ios_base::openmode mode)		// ��� �����(��������/��������/����������..)
{
	int len = strlen(filename);
	this->filename = new char[len + 1];
	strcpy(this->filename, filename);
	file.open(filename, mode);
	if (!file)
	{
		SetConsoleCP(866);
		cout << "������ �2: ����� " << filename << " ��� �� ����� " << endl;
		exit(2);
	}
}

//�������� �����
void Files::closeFile()
{
	file.close();
	if (!file)
	{
		SetConsoleCP(866);
		cout << "������ �3: ���� " << this->filename << " �� ����� ���� ������" << endl;
		exit(3);
	}
	delete[] this->filename;
}