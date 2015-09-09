#include "main.h"

// функция-помощь
void help()
{
	cout << "Справка:\n" << endl;
	cout << "Автор Медведев Михаил" << endl;
	cout << "Программа-игра. Пользователь пробует составить слова из заданного слова." << endl;
	cout << "Запуск осуществляется строкой типа : programm.exe input.txt output.txt" << endl;
	cout << "В исходном файле должно находиться одно любое слово на русском языке" << endl;
}

// функция, печатающая список всех слов в файл вывода
void print_list(fstream &fout,												// переменная для файла вывода
				list<string> &words)										// линейный список для составленных слов
{
	words.sort();
	bool flag = false;
	string temp;
	int k = 0;
	for (char ch = 'а'; ch <= 'я'; ++ch)
	{
		flag = false;
		for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
		{
			temp = *it;
			if (temp[0] == ch)
			{
				++k;
				SetConsoleCP(866);
				fout << *it << setw(10);
				flag = true;
			}
			if (k == 7)
			{
				k = 0;
				fout << "\n";
			}
		}
		if (flag)
			fout << "\n";
	}
	fout << endl;
}


// функция, печатающая список всех слов в консоль
void print_list_con(list<string> &words)									// линейный список для составленных слов
{
	if (words.empty())
	{
		cout << "Пока вы не составили ни одного слова :(" << endl;
	}
	else {
		words.sort();
		bool flag = false;
		string temp;
		int k = 0;
		for (char ch = 'а'; ch <= 'я'; ++ch)
		{
			flag = false;
			for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
			{
				temp = *it;
				if (temp[0] == ch)
				{
					++k;
					SetConsoleCP(866);
					cout << *it << setw(10);
					flag = true;
				}
				if (k == 7)
				{
					k = 0;
					cout << "\n";
				}
			}
			if (flag)
				cout << "\n";
		}
		cout << endl;
	}
}

// функция, печатающая список слов начинающихся на определенную букву
void print_list_1b(string &try_word,										// строка, содержащая введенное слово
					list<string> &words)									// линейный список для составленных слов
{
	bool flag = false;
	for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		string tmp = *it;
		flag = false;
		for (unsigned int i = 0; i < 1; ++i)
		{
			if (tmp[0] == try_word[0])
			{
				SetConsoleCP(866);
				cout << *it << setw(10);
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "\n";
	}
}

// функция вывода всей необходимой информации в файл вывода
void information(fstream &fout,												// переменная для файла вывода
				list<string> words,											// линейный список для составленных слов
				string &word)												// строка, содержащая исходное слово
{
	fout << "Задание : " << endl;
	fout << "В исходном файле задается слово. Пользователь должен составить новые слова из букв" << endl
		<< "заданного слова(длина слова должна быть не менее 3 символов)." << endl
		<< "Исходное слово должно отображаться на экране. Новые слова вводятся с клавиатуры." << endl
		<< "При первой буквы нового слова на экран должен выводиться список всех уже введенных " << endl
		<< "слов на эту букву. Если введенное слово уже существует или не подходит - должно " << endl
		<< "выдаваться сообщение." << endl
		<< "По окончании работы в файл результатов записывается назначение программы, исходное слово, " << endl
		<< "список составленных слов и результат - количество придуманных слов." << endl
		<< "Список составленных слов выводится по столбцам в алфавитном порядке (каждая" << endl
		<< "следующая буква алфавита должна начинаться с новой строки).\n" << endl;
	SetConsoleCP(866);
	fout << "\nИсходное слово: " << setw(16) << word << endl;
	fout << "\nСоставленные слова : \n" << endl;
	SetConsoleCP(866);
	print_list(fout, words);
	fout << "\nРезультат: " << setw(4) << words.size();
}