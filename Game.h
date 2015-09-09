#pragma once 

#include <iostream>
#include <map>
#include <list>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

// ������� ����� ��� ���� (��� �������� � ��������� ���������� � ������, ������������ � ����)
class Game
{
protected:
	map<char, int> main_table;					// ����� ��� ��������� ����� (������ - ����������)
	map<char, int> sec_table;					// ����� ��� �������� ���� (������ - ����������)
	string main_w;								// ������, ���������� �������� �����
	string try_w;								// ������, ���������� �������� �����
public:
	Game(string main_w1, string try_w1);
	void init_one(string &word);
	void check(list<string> &words);
	bool equal();
	bool contain(list<string> words);
	string get_main_str() { return main_w; }
	string get_try_str() { return try_w; }
};