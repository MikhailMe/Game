#include "main.h"

int main(int argc,														// ���������� ���������� ��������� ������
		 char *argv[])													// ���������
{
	setlocale(LC_ALL, "Russian");
	if (argc == 1)
	{
		SetConsoleCP(866);
		cout << "������ �1: ��������� �� ������!" << endl;
		exit(1);
	}
	else 
	{
		if ((!strcmp(argv[1], "/h")) || (!strcmp(argv[1], "/?")))		// ������� ���������, ��� ������ ������� strcmp ���������� 0.
		{
			help();														// ������� ������ �������
			_getch();
			return -1;
		}
		else if (argv[2] == 0)
		{
			SetConsoleCP(866);
			cout << "��������� �������� ���������.\n���� �����: " << argv[1] << endl;
			cout << "���� ������ �� �����." << endl;
			cout << "���� ������ ����� �� ���������: output.txt" << endl;
			argv[2] = ("output.txt");
		}
		else
			cout << "��������� �������� ���������.\n���� �����: " << argv[1] << "\n���� ������: " << argv[2] << "\n\n";
	}
	Files fin, fout;													// ������� ������ Files, ��� ����� ����� � ������
	fin.openFile(argv[1], ios::in);										// �������� ����� ����� 
	string main_word;													// ������ ��� ��������� �����
	SetConsoleCP(1251);
	fin.file >> main_word;												// ���������� ��������� �����
	if (!fin.file)
	{
		SetConsoleCP(866);
		cout << "������ �4: � �������� ����� ��� ����������!" << endl;
		exit(4);
	}
	fin.closeFile();													// �������� �����
	string try_word;													// ������ ��� ��������� �����
	string want;														// ���������� ��� ����������� ����� �� ��� ��������� ����� ��� ���
	list<string> words; 												// ������ ��� �������� ����
	while (try_word != "�����")
	{
		SetConsoleCP(866);
		cout << "�������� ��������� ����� �� �����: " << endl;
		cout << "______________________________" << endl;
		cout << "     " << main_word << endl;
		cout << "______________________________" << endl;
		cout << "��� ������ ���������� ��������� : �����" << endl;
		cout << "\n������ ��� ������������ ���� : " << endl;
		print_list_con(words);
		m1:
		cout << "\n���� ����� : ";
		SetConsoleCP(1251);
		cin >> try_word;												// ���� �����-�������
		want = try_word;
		if (want == "�����")											// ����� �� ����� �����?
			break;
		Game obj(main_word, try_word);									// ������� ������ ������ ��� ���������� ��������
		obj.init_one(main_word);										// �������������� ����� ��� ��������� �����
		obj.init_one(try_word);											// �������������� ����� ��� ���������� �����
		if (obj.get_try_str().size() == 1)								// ���� ������� 1 ����� ������ ������ ���� ����� ��������� �� ��
		{
			SetConsoleCP(866);
			cout << "\n������ ����� ����������� ���� �� ����� " << try_word << " :" << endl;
			print_list_1b(try_word, words);								// ����� �������, ���������� ����� ��������� ����� �� �������� �����
			goto m1;
		}
		SetConsoleCP(866);
		if (obj.get_main_str().size() < obj.get_try_str().size())		// ��������� ���� � �������� � ��������� �����
			cout << "�������������� �1: � �������� ����� ������ ����!" << endl;
		else if (obj.equal())											// ����� ������� �������� �� ������������ ��������� � ���������� ����
		{
				cout << "\n�� ����� �������� �����!" << endl;
				cout << "��� �� ������!" << endl;
		}
		else if (obj.get_try_str().size() < 3)							// ���������� ������� �����, ��������� �� 3� � ����� ����
		{
			cout << "������ �6: ������� �������� �����! (�� ����� 3� ����)" << endl;
		}
		else if (!obj.contain(words))									// �������� �� ���� �����, ������� ��� ���� ������� �����
		{
			obj.check(words);											// ����� ������� �������� ����������� ���� ���������� � ��������� ����
		}
		SetConsoleCP(866);
		cout << "\n������� ����� ������� ��� �����������.." << endl;
		_getch();														// ���������� ������� ��� �������� ���������
		system("cls");													// ������� ������ �������
	}
	fout.openFile(argv[2], ios::out);									// �������� ����� ������
	information(fout.file, words,main_word);							// ����� ����������� � ���� ������
	fout.closeFile();													// �������� ����� ������
	SetConsoleCP(866);
	cout << "���������� ������ ���������.." << endl;
	_getch();															// ���������� ������� ��� �������� ���������
	return 0;															// �������� ���������� ������ ���������
}