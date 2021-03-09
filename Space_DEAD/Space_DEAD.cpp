#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <string>
#include <string.h>
using namespace std;

string DeleteSpace(string value)
{
	string result;
	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] == ' ' && value[i + 1] == ' ')//Условие(если встречается несколько пробелов подряд)
		{
			continue;//пропускаем итерацию
		}
		else//иначе
		{
			result += value[i];
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");

	string text, path; // Строка, куда будет записан текст
	vector <string> arr;
	vector <string> arr2;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Укажите путь к файлу: ";
	getline(cin, path);

	ifstream read(path);  // Поток для чтения. В скобках записывается путь к файлу

	if (read.is_open()) // Проверяет, открылся ли файл.
	{
		while (!read.eof())
		{
			getline(read, text);//Записывает текст из файла в строку.
			arr.push_back(text);
		}
		read.close();
	}
	else
	{
		cout << "Не удалось открыть файл!" << endl;
	}

	for (auto& var : arr)
	{
		arr2.push_back(DeleteSpace(var));
	}

	path.clear();
	cout << "Укажите путь сохранения отредактированного файла: ";
	getline(cin, path);

	ofstream write;// открывем поток для записи
	write.open(path);//Указываем путь к новому файлу
	if (write.is_open())
	{
		for (int i = 0; i < arr2.size(); i++)
		{
			write << arr2[i] << endl;
		}
	}
	write.close();

	SetConsoleOutputCP(866);
	SetConsoleCP(866);

	cout << "Повторяющиеся пробелы в тексте удалены: ";

	system("pause");
	return 0;
}
