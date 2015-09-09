#include "Files.h"

//Открытие файла
void Files::openFile(char *filename,				// имя файла
					ios_base::openmode mode)		// мод файла(открытия/закрытия/добавления..)
{
	int len = strlen(filename);
	this->filename = new char[len + 1];
	strcpy(this->filename, filename);
	file.open(filename, mode);
	if (!file)
	{
		SetConsoleCP(866);
		cout << "Ошибка №2: файла " << filename << " нет на диске " << endl;
		exit(2);
	}
}

//Закрытие файла
void Files::closeFile()
{
	file.close();
	if (!file)
	{
		SetConsoleCP(866);
		cout << "Ошибка №3: файл " << this->filename << " не может быть закрыт" << endl;
		exit(3);
	}
	delete[] this->filename;
}