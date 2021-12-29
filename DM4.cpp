#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

ofstream outputFile("D:\\DMTESTFILE\\test.txt");

//- Дано множество {a,b,c,d,e,f}. Построить все слова длины 7, в которых ровно 1
//буква повторяются 2 раза, ровно одна буква повторяется 3 раза остальные буквы не повторяются.
//Вывод в файл.
// Всего 50400 слов
bool IsContained(string word, char ch, int count)
{
	int num = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == ch) num++;
		if (num > count) return false;
	}
	return num == count;
}

bool IsRepeating(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	string word = "";
	int flag = 0;
	char first = ' ';
	char second = ' ';
	word += to_string(a1);
	word += to_string(a2);
	word += to_string(a3);
	word += to_string(a4);
	word += to_string(a5);
	word += to_string(a6);
	word += to_string(a7);
	for (int i = 0; i < word.length(); i++)
	{
		if (IsContained(word, word[i], 2))
			first = word[i];
		if (IsContained(word, word[i], 3))
			second = word[i];
	}
	if (first == ' ' || second == ' ') return false;
	for (int i = 0; i < word.length(); i++)
		if (word[i] == first || word[i] == second) word.erase(i, 1);
	for (int i = 0; i < word.length(); i++)
		for (int j = i + 1; j < word.length(); j++)
			if (word[i] == word[j]) return false;
	return true;
}

void PermWithRep(string str, int limit, int n, int k)
{
	int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0, ch5 = 0, ch6 = 0, ch7 = 0;
	if (limit > k)
	{

		for (int i = 0; i < k; i++)
		{
			if (str[i] == '1') ch1++;
			if (str[i] == '2') ch2++;;
			if (str[i] == '3') ch3++;
			if (str[i] == '4') ch4++;
			if (str[i] == '5') ch5++;
			if (str[i] == '6') ch6++;
			if (str[i] == '7') ch7++;
		}
		if (IsRepeating(ch1, ch2, ch3, ch4, ch5, ch6, ch7))
		{
			for (int i = 0; i < k; i++)
			{
				if (str[i] == '1') str[i] = 'a';
				if (str[i] == '2') str[i] = 'b';
				if (str[i] == '3') str[i] = 'c';
				if (str[i] == '4') str[i] = 'd';
				if (str[i] == '5') str[i] = 'e';
				if (str[i] == '6') str[i] = 'f';
			}
			outputFile << str << endl;
		}
	}
	else
		for (int i = 0; i < n; i++)
		{
			ostringstream indexIncrementer;
			indexIncrementer << i + 1;
			PermWithRep(str + indexIncrementer.str(), limit + 1, n, k);
		}
}
int main()
{
	int alphabetNumber = 6;
	int wordLength = 7;
	cout << "Enter alphabet number: " << alphabetNumber << endl;
	cout << "Enter the word's length: " << wordLength << endl;
	PermWithRep("", 1, alphabetNumber, wordLength);
	cout << "FINISHED! Check out the result file!";
}
