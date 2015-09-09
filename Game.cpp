#include "Game.h"

// Конструктор
Game::Game(string main_w1,						// строка, содержащая исходное слово
		   string try_w1)						// строка, содрежащая вводимое слово
{
	main_w = main_w1;
	for (unsigned int i = 0; i < main_w.size(); ++i)
		main_table.insert(pair<char,int> {main_w[i], 1});

	try_w = try_w1;
	for (unsigned int i = 0; i < try_w.size(); ++i)
		sec_table.insert(pair<char, int> {try_w[i], 1});

}

// функция инициализации карты (буква - количество)
void Game::init_one(string &word)				// строка, содержащая слово, которе необходимо разложить по символам
{
	if (word == main_w)
	{
		for (map<char, int>::iterator spec = main_table.begin(); spec != main_table.end(); ++spec)
		{
			int temp = 0;
			for (unsigned int i = 0; i < word.size(); ++i)
			if ((*spec).first == word[i])
				++temp;
			(*spec).second = temp;
		}
	}
	else if (word == try_w)
	{
		for (map<char, int>::iterator spec = sec_table.begin(); spec != sec_table.end(); ++spec)
		{
			int temp = 0;
			for (unsigned int i = 0; i < word.size(); ++i)
			if ((*spec).first == word[i])
				++temp;
			(*spec).second = temp;
		}
	}
}

// функция проверки соответсвия букв введенного и исходного слов
void Game::check(list<string> &words)			// линейный список для составленных слов
{
	int save = 0;
	for (map <char, int>::iterator spec = sec_table.begin(); spec != sec_table.end(); ++spec)
	{
		for (map <char, int>::iterator cur = main_table.begin(); cur != main_table.end(); ++cur)
		{
			if ((*spec).first == (*cur).first && (*spec).second <= (*cur).second)
				save += (*spec).second;
		}
	}		

	if (save == try_w.size())
	{
		words.push_back(try_w);
		SetConsoleCP(866);
		cout << "\nВведенное слово подходит условиям!" << endl;
	}
	else
	{
		SetConsoleCP(866);
		cout << "\nОшибка №5: Введенное слово не удовлетворяет условиям" << endl;
		cout << "В веденном слове есть буквы, которые отсутствуют в исходном" << endl;
	}
}

// функция проверки на идентичность исходного и введенного слов
bool Game::equal()
{
	if (main_w.size() == try_w.size())
	{
		bool flagok = true;
		for (unsigned int i = 0; i < main_w.size(); ++i)
		{
			if (main_table[i] != sec_table[i])
				flagok = false;
		}
		if (flagok)
			return true;
		else return false;
	}
	else return false;
}

// функция, проверяющая наличия слова в линейном списке
bool Game::contain(list<string> words)			// линейный список для составленных слов
{
	for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		if (*it == try_w)
		{
			SetConsoleCP(866);
			cout << "Предупреждение №2: Вы уже вводили данное слово!" << endl;
			return true;
		}
	}
	return false;
}