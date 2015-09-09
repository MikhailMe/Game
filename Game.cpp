#include "Game.h"

// �����������
Game::Game(string main_w1,						// ������, ���������� �������� �����
		   string try_w1)						// ������, ���������� �������� �����
{
	main_w = main_w1;
	for (unsigned int i = 0; i < main_w.size(); ++i)
		main_table.insert(pair<char,int> {main_w[i], 1});

	try_w = try_w1;
	for (unsigned int i = 0; i < try_w.size(); ++i)
		sec_table.insert(pair<char, int> {try_w[i], 1});

}

// ������� ������������� ����� (����� - ����������)
void Game::init_one(string &word)				// ������, ���������� �����, ������ ���������� ��������� �� ��������
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

// ������� �������� ����������� ���� ���������� � ��������� ����
void Game::check(list<string> &words)			// �������� ������ ��� ������������ ����
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
		cout << "\n��������� ����� �������� ��������!" << endl;
	}
	else
	{
		SetConsoleCP(866);
		cout << "\n������ �5: ��������� ����� �� ������������� ��������" << endl;
		cout << "� �������� ����� ���� �����, ������� ����������� � ��������" << endl;
	}
}

// ������� �������� �� ������������ ��������� � ���������� ����
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

// �������, ����������� ������� ����� � �������� ������
bool Game::contain(list<string> words)			// �������� ������ ��� ������������ ����
{
	for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		if (*it == try_w)
		{
			SetConsoleCP(866);
			cout << "�������������� �2: �� ��� ������� ������ �����!" << endl;
			return true;
		}
	}
	return false;
}