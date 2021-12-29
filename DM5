#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

ofstream outputFile("D:\\DMTESTFILE\\test.txt");

// Дано множество {a,b,c,d,e,f}. Построить все слова длины 4, в которых больше
// двух букв а. Вывод в файл.
// Дано множество {a,b,c,d,e,f}. Построить все слова длины 7, в которых больше двух
// букв а. Вывод в файл.
// 1) (длина слова = 4) 21 слово
// 2) (длина слова = 7) 26811 слов
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
        if (ch1 > 2)
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
            ostringstream indexIncrimentor;
            indexIncrimentor << i + 1;

            PermWithRep(str + indexIncrimentor.str(), limit + 1, n, k);
        }
}
int main()
{

    int alphabetNumber = 6;
    int wordLength = 7; // или wordLength = 4
    cout << "Enter alphabet number: " << alphabetNumber << endl;
    cout << "Enter the word's length: " << wordLength << endl;
    PermWithRep("", 1, alphabetNumber, wordLength);
    cout << "FINISHED! Check out the result file!";
}

