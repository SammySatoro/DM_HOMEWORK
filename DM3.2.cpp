#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

ofstream outputFile("D:\\DMTESTFILE\\test.txt");

// - Дано множество {a,b,c,d,e,f}. Построить все слова длины 6, в которых ровно 2
// буквы повторяются 2 раза, остальные буквы не повторяются.Вывод в файл.
// 16200 слов всего

bool IsRepeating(int a1, int a2, int a3, int a4, int a5, int a6)
{
	string word = "";
	int flag;
	word += to_string(a1);
	word += to_string(a2);
	word += to_string(a3);
	word += to_string(a4);
	word += to_string(a5);
	word += to_string(a6);
	for (int i = 0; i < word.length(); i++)
	{
		flag = 0;
		for (int j = i; j < word.length(); j++)
		{
			if (word[i] == word[j])
				flag++;
			if (flag > 2)
			{
				return false;				
			}
		}
	}
	if (flag == 2)
	{
		return true;;
	}
}

void PermWithRep(string str, int limit, int n, int k)
{
	int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0, ch5 = 0, ch6 = 0;
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
		}
		if (IsRepeating(ch1, ch2, ch3, ch4, ch5, ch6))
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
	int wordLength = 6;
	cout << "Enter alphabet number: " << alphabetNumber << endl;
	cout << "Enter the word's length: " << wordLength << endl;
	PermWithRep("", 1, alphabetNumber, wordLength);
	cout << "FINISHED! Check out the result file!";
}
