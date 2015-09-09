#include "main.h"

// �������-������
void help()
{
	cout << "�������:\n" << endl;
	cout << "����� �������� ������" << endl;
	cout << "���������-����. ������������ ������� ��������� ����� �� ��������� �����." << endl;
	cout << "������ �������������� ������� ���� : programm.exe input.txt output.txt" << endl;
	cout << "� �������� ����� ������ ���������� ���� ����� ����� �� ������� �����" << endl;
}

// �������, ���������� ������ ���� ���� � ���� ������
void print_list(fstream &fout,												// ���������� ��� ����� ������
				list<string> &words)										// �������� ������ ��� ������������ ����
{
	words.sort();
	bool flag = false;
	string temp;
	int k = 0;
	for (char ch = '�'; ch <= '�'; ++ch)
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


// �������, ���������� ������ ���� ���� � �������
void print_list_con(list<string> &words)									// �������� ������ ��� ������������ ����
{
	if (words.empty())
	{
		cout << "���� �� �� ��������� �� ������ ����� :(" << endl;
	}
	else {
		words.sort();
		bool flag = false;
		string temp;
		int k = 0;
		for (char ch = '�'; ch <= '�'; ++ch)
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

// �������, ���������� ������ ���� ������������ �� ������������ �����
void print_list_1b(string &try_word,										// ������, ���������� ��������� �����
					list<string> &words)									// �������� ������ ��� ������������ ����
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

// ������� ������ ���� ����������� ���������� � ���� ������
void information(fstream &fout,												// ���������� ��� ����� ������
				list<string> words,											// �������� ������ ��� ������������ ����
				string &word)												// ������, ���������� �������� �����
{
	fout << "������� : " << endl;
	fout << "� �������� ����� �������� �����. ������������ ������ ��������� ����� ����� �� ����" << endl
		<< "��������� �����(����� ����� ������ ���� �� ����� 3 ��������)." << endl
		<< "�������� ����� ������ ������������ �� ������. ����� ����� �������� � ����������." << endl
		<< "��� ������ ����� ������ ����� �� ����� ������ ���������� ������ ���� ��� ��������� " << endl
		<< "���� �� ��� �����. ���� ��������� ����� ��� ���������� ��� �� �������� - ������ " << endl
		<< "���������� ���������." << endl
		<< "�� ��������� ������ � ���� ����������� ������������ ���������� ���������, �������� �����, " << endl
		<< "������ ������������ ���� � ��������� - ���������� ����������� ����." << endl
		<< "������ ������������ ���� ��������� �� �������� � ���������� ������� (������" << endl
		<< "��������� ����� �������� ������ ���������� � ����� ������).\n" << endl;
	SetConsoleCP(866);
	fout << "\n�������� �����: " << setw(16) << word << endl;
	fout << "\n������������ ����� : \n" << endl;
	SetConsoleCP(866);
	print_list(fout, words);
	fout << "\n���������: " << setw(4) << words.size();
}