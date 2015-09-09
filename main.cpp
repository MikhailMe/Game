#include "main.h"

int main(int argc,														// количество аргументов командной строки
		 char *argv[])													// аргументы
{
	setlocale(LC_ALL, "Russian");
	if (argc == 1)
	{
		SetConsoleCP(866);
		cout << "Ошибка №1: Аргументы не заданы!" << endl;
		exit(1);
	}
	else 
	{
		if ((!strcmp(argv[1], "/h")) || (!strcmp(argv[1], "/?")))		// функция сравнения, при равных строках strcmp возвращает 0.
		{
			help();														// функция вызова справки
			_getch();
			return -1;
		}
		else if (argv[2] == 0)
		{
			SetConsoleCP(866);
			cout << "Программа запущена корректно.\nФайл ввода: " << argv[1] << endl;
			cout << "Файл вывода не задан." << endl;
			cout << "Файл вывода задан по умолчанию: output.txt" << endl;
			argv[2] = ("output.txt");
		}
		else
			cout << "Программа запущена корректно.\nФайл ввода: " << argv[1] << "\nФайл вывода: " << argv[2] << "\n\n";
	}
	Files fin, fout;													// объекты класса Files, для файла ввода и вывода
	fin.openFile(argv[1], ios::in);										// открытие файла ввода 
	string main_word;													// строка для исходного слова
	SetConsoleCP(1251);
	fin.file >> main_word;												// считывание исходного слова
	if (!fin.file)
	{
		SetConsoleCP(866);
		cout << "Ошибка №4: в исходном файле нет информации!" << endl;
		exit(4);
	}
	fin.closeFile();													// закрытие слова
	string try_word;													// строка для вводимого слова
	string want;														// переменная для определения будут ли ещё вводиться слова или нет
	list<string> words; 												// список для введеных слов
	while (try_word != "ВЫХОД")
	{
		SetConsoleCP(866);
		cout << "Попробуй составить слова из слова: " << endl;
		cout << "______________________________" << endl;
		cout << "     " << main_word << endl;
		cout << "______________________________" << endl;
		cout << "Для выхода необходимо прописать : ВЫХОД" << endl;
		cout << "\nСписок уже составленных слов : " << endl;
		print_list_con(words);
		m1:
		cout << "\nВаше слово : ";
		SetConsoleCP(1251);
		cin >> try_word;												// ввод слова-попытки
		want = try_word;
		if (want == "ВЫХОД")											// хочет ли игрок выйти?
			break;
		Game obj(main_word, try_word);									// создаем объект класса для дальнейших действий
		obj.init_one(main_word);										// инициализируем карту для исходного слова
		obj.init_one(try_word);											// инициализируем карту для введенного слова
		if (obj.get_try_str().size() == 1)								// если вводишь 1 букву выдает список слов ранее введенных на неё
		{
			SetConsoleCP(866);
			cout << "\nСписок ранее составленых слов на букву " << try_word << " :" << endl;
			print_list_1b(try_word, words);								// вызов функции, печатающую слова введенные ранее на введеную букву
			goto m1;
		}
		SetConsoleCP(866);
		if (obj.get_main_str().size() < obj.get_try_str().size())		// сравнение букв в исходном и введенном слове
			cout << "Предупреждение №1: в исходном слове меньше букв!" << endl;
		else if (obj.equal())											// вызов функции проверки на идентичность исходного и введенного слов
		{
				cout << "\nВы ввели исходное слово!" << endl;
				cout << "Так не честно!" << endl;
		}
		else if (obj.get_try_str().size() < 3)							// необходимо вводить слова, состоящие из 3х и более букв
		{
			cout << "Ошибка №6: слишком короткое слово! (не менее 3х букв)" << endl;
		}
		else if (!obj.contain(words))									// проверка на ввод слова, которое уже было введено ранее
		{
			obj.check(words);											// вызов функции проверки соответсвия букв введенного и исходного слов
		}
		SetConsoleCP(866);
		cout << "\nНажмите любую клавишу для продолжения.." << endl;
		_getch();														// считывание символа для задержки программы
		system("cls");													// очистка экрана консоли
	}
	fout.openFile(argv[2], ios::out);									// открытие файла вывода
	information(fout.file, words,main_word);							// вывод результатов в файл вывода
	fout.closeFile();													// закрытие файла вывода
	SetConsoleCP(866);
	cout << "завершение работы программы.." << endl;
	_getch();															// считывание символа для задержки программы
	return 0;															// успешное завершение работы программы
}