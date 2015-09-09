#pragma once 

#include <iostream>
#include <map>
#include <list>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

// главный класс для игры (для хранения и обработки информации о данных, используемых в игре)
class Game
{
protected:
	map<char, int> main_table;					// карта для исходного слова (символ - количество)
	map<char, int> sec_table;					// карта для вводимых слов (символ - количество)
	string main_w;								// строка, содержащая исходное слово
	string try_w;								// строка, содержащая вводимое слово
public:
	Game(string main_w1, string try_w1);
	void init_one(string &word);
	void check(list<string> &words);
	bool equal();
	bool contain(list<string> words);
	string get_main_str() { return main_w; }
	string get_try_str() { return try_w; }
};