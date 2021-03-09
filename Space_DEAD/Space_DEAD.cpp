#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <string>
#include <string.h>
using namespace std;

string DeleteSpace(string x)
{
	string z;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == ' ' && x[i + 1] == ' ')//Условие(если встречается несколько пробелов подряд)
		{
			continue;//пропускаем итерацию
		}
		else//иначе
		{
			z += x[i];
		}
	}
	return z;
}

int main()
{
	string text; // Строка, куда будет записан текст
	vector <string> arr;
	vector <string> arr2;

	ifstream read("C:\\Users\\Kiril\\OneDrive\\Рабочий стол\\File_2.txt");  // Поток для чтения. В скобках записывается путь к файлу

	if (read.is_open()) // Проверяет, открылся ли файл.
	{
		while (!read.eof())
		{
			getline(read, text);//Записывает текст из файла в строку.
			arr.push_back(text);
		}
		read.close();
	}

	for (auto& var : arr)
	{
		arr2.push_back(DeleteSpace(var));
	}

	ofstream write;// открывем поток для записи
	write.open("D:\\Projects\\Space_DEAD\\Debug\\result2.txt");//Указываем путь к новому файлу
	if (write.is_open())
	{
		for (int i = 0; i < arr2.size(); i++)
		{
			write << arr2[i] << endl;
		}
	}
	write.close();
	system("pause");
	return 0;
}
