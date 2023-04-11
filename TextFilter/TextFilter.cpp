/*Класс Vector.Класс string.
Разработать программу, фильтрующую текст из заданного файла.
Задача программы заключается в считывании файла и отображении его на экране(постранично),
используя замену заданного набора символов на пробелы.Программа должна предлагать следующие варианты наборов символов для фильтрации :
- символы латиницы;
- символы кириллицы;
- символы пунктуации;
- цифры.
Фильтры могут накладываться последовательно.При повторной установке существующего фильтра данный фильтр должен сниматься.
В коде программы следует обязательно использовать класс Vector и класс string.*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

void PrintPage(vector<char> page);

string _LoadTextFile(string filename)
{
	string line;

	ifstream myfile(filename);

	if (myfile.is_open())
	{
		getline(myfile, line);

		if (getline(myfile, line))
		{
			cout << "\nFile [" << filename << "] is opened\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	return line;
}

vector<vector<char>> GetPages(string line)
{
	vector<vector<char>> pages;

	vector<char> page;

	int i = 0, pageNum = 0;

	while (i <= line.length())
	{
		for (int j = 0; j <= 9849; j++)
		{
			page.push_back(line[i]);

			if (i < line.length()) i++;

			/*if (j > line.length())
			{
				pages.push_back(page);
				return pages;
			}*/
		}
		pages.push_back(page);

		if (i >= line.length()) return pages;

		page.erase(page.begin(), page.end());
	}

	return pages;
}

vector<vector<char>> GetDelLatinPages(vector<string> input)
{
	vector<string>::iterator it;

	vector<vector<char>> pages;

	vector<char> page;

	string line;

	int i = 0, pageNum = 0;

	for (it = input.begin(); it != input.end(); it++)
	{
		while (i <= line.length())
		{
			for (int j = 0; j <= 9849; j++)
			{
				if (!(
					(int(line[i]) >= 65) &&
					(int(line[i]) <= 90) ||
					(int(line[i]) >= 97) &&
					(int(line[i]) <= 122)
					))			page.push_back(line[i]);
				else
					page.push_back(' ');

				if (i < line.length()) i++;
			}
			pages.push_back(page);

			if (i >= line.length()) return pages;

			page.erase(page.begin(), page.end());

		}
	}

	return pages;
}

vector<vector<char>> GetDelCyrPages(string line)
{
	vector<vector<char>> pages;

	vector<char> page;

	int i = 0, pageNum = 0;

	while (i <= line.length())
	{
		for (int j = 0; j <= 9849; j++)
		{
			if (!(
				(int(line[i]) >= 192) &&
				(int(line[i]) <= 255)
				))			page.push_back(line[i]);
			else
				page.push_back(' ');

			if (i < line.length()) i++;
		}
		pages.push_back(page);

		if (i >= line.length()) return pages;

		page.erase(page.begin(), page.end());

	}

	return pages;
}

vector<vector<char>> GetDelPunctPages(string line)
{
	vector<vector<char>> pages;

	vector<char> page;

	int i = 0, pageNum = 0;

	while (i <= line.length())
	{
		for (int j = 0; j <= 9849; j++)
		{
			if (!(
				(int(line[i]) >= 33) &&
				(int(line[i]) <= 47) ||
				(int(line[i]) >= 58) &&
				(int(line[i]) <= 64) ||
				(int(line[i]) >= 91) &&
				(int(line[i]) <= 96) ||
				(int(line[i]) >= 123) &&
				(int(line[i]) <= 127)
				))			page.push_back(line[i]);
			else
				page.push_back(' ');

			if (i < line.length()) i++;
		}
		pages.push_back(page);

		if (i >= line.length()) return pages;

		page.erase(page.begin(), page.end());

	}

	return pages;
}

vector<vector<char>> GetDelNumPages(string line)
{
	vector<vector<char>> pages;

	vector<char> page;

	int i = 0, pageNum = 0;

	while (i <= line.length())
	{
		for (int j = 0; j <= 9849; j++)
		{
			if (!(
				(int(line[i]) >= 48) &&
				(int(line[i]) <= 57)
				))			page.push_back(line[i]);
			else
				page.push_back(' ');

			if (i < line.length()) i++;
		}
		pages.push_back(page);

		if (i >= line.length()) return pages;

		page.erase(page.begin(), page.end());

	}

	return pages;
}


void PrintPage(vector<char> page)
{
	system("cls");

	ostream_iterator<char> out(cout, "");

	copy(page.begin(), page.end(), out);

	cout << endl;
}

void PrintAllPages(vector<vector<char>> pages)
{
	cout << pages.size() << " pages.";

	for (int i = 0; i < pages.size(); i++)
	{
		system("cls");

		PrintPage(pages[i]);

		cout << "\t\t\t\t\t\t\t\t\t\t\tPage " << i + 1 << endl;

		system("pause");
	}
}
void PrintMenu()
{
	char Menu[] = "\tM E N U:\n1.Delete latin characters\n2.Delete cyrillic characters\n3.Delete punctuation characters\n4.Delete number characters\n5.Original text\n0.Exit\n";
	system("cls");
	cout << Menu;
}

wstring _LoadCyrTextFile(string filename)
{
	std::wifstream in(filename, std::ios::binary);
	wchar_t wbuf[128] = { 0 };
	in.rdbuf()->pubsetbuf(wbuf, 128);

	//BOM check
	wchar_t bom{};
	in.read(&bom, 1);
	if (bom == 0xfeff)
		std::cout << "UTF16-LE\n";

	//read file
	std::wstring str;
	std::getline(in, str);
	in.close();

	return str;
}


vector<string> LoadTextFile(string filename)
{
	ifstream infile(filename);

	string line;

	vector<string> input;

	while (std::getline(infile, line))
	{
		input.push_back(line);
	}

	return input;
}

int main()

{
	//string line;

	string filename = "Text.txt";

	vector<string> input = LoadTextFile(filename);

	vector<vector<char>> pages;

	while (true)
	{
		PrintMenu();
		char res = _getch();
		switch (res)
		{
		case '1': GetDelLatinPages(line);	//Delete latin characters
			PrintAllPages(pages);
			break;

		case '2': GetDelCyrPages(line);       //Delete cyrillic characters
			PrintAllPages(pages);
			break;

		case '3': GetDelPunctPages(line);         //Delete punctuation characters
			PrintAllPages(pages);
			break;

		case '4': GetDelNumPages(line);               // Delete number characters
			PrintAllPages(pages);
			break;

		case '5': 									//Back to default text
			input = LoadTextFile(filename);
			pages = GetPages(input);
			PrintAllPages(pages);
			break;

		case '0':										// Exit
			cout << "\nThank you!" << endl;
			system("exit");
			return 0;
			break;

		default:

			cout << "\nERROR! Pressed wrong key\n";
			system("pause");
			break;
		}
	}


	return 0;
}

