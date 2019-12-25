#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>//Для работы с файлами
#include <sstream>//Для работы со строками
#include <string>
#include <cstdio>//feof
#define MAX_LINE 100
using namespace std;
int main(void)
{
	ifstream in;//Файл для чтения
	setlocale(LC_ALL, "rus");//Подключение кодировки с русскими буквами
	char str[MAX_LINE];//Служебная строка для ввода данных в консоль
	FILE *fpin;
	int choise;
	int cnt = 0;
	int size = 0;
	char mas[MAX_LINE];
	bool flag1, flag2, flag3;
	flag1 = flag2 = flag3 = 0;
	int flag4 = 0;//флаг что не после букв
	cout << "1 - Чтение из из фала строк, имеющих двоухзначные числа\n2 - Выход\n\n";//Информация для пользователя
	cout << "Выбирете команду:\n";
	gets_s(str);
	choise = atoi(str);
	char ch;
	switch (choise)
	{
	case 1: system("cls");
		try
		{
		in.open("test.txt");
		if (!in)//Ошибка открытия файла
		{
			exception err("Ошибка открытия файла\n");
			throw err;
		}
		if (in.peek() == -1)
		{
			exception err("\nОткрываемый файл пустой\n");
			throw err;
		}
			while (((ch = in.get()) != EOF))
			{
				size++;
				if (ch >= '0' && ch <= '9') 
				{
					flag1 = 1;//Сейчас цифра
					cnt++;
				}
				else
				{
					if (flag2 == 1 && (ch == ' '|| ch =='\n'))
					{
						flag3 = 1;
						cnt = 0;
						flag1 = 0;
						flag2 = 0;
						flag4 = 0;
					}
					else
					{
						if (ch == ' ')
							flag4 = 0;
						else
							flag4 = 1;
						flag2 = 0;
						flag1 = 0;
						cnt = 0;
					}
				}

				if (flag1 == 1 && cnt == 2 && flag4 ==0) //2 цифры подряд
				{
					flag2 = 1;
				}
				if (flag1 == 1 && cnt == 3)//3 цифры подряд
				{
					flag1 = 0;
					flag2 = 0;
					cnt = 0;
					flag4 = 0;
				}
				if ((ch == '\n' && flag2==1) || (ch == '\n' && flag3==1))
				{
					mas[size-1] = '\0';
					cout << mas << "\n";
					cnt = 0;
					flag1 = flag2 = flag3=flag4=0;
					
					for (int i = 0; i < size; i++)
					{
						mas[i] = 0;
					}
					size = 0;
					continue;
				}
				else if (ch == '\n')
				{
					flag1 = flag2 = flag3 = flag4 = 0;
					for (int i = 0; i < size; i++)
					{
						mas[i] = 0;
					}
					size = 0;
				}
			if(size != 0)
				mas[size-1] = ch;
				
			}
		in.close(); 
		}
		catch(exception& err)
		{
			cout << err.what() << endl << endl;
		}
		if (flag3 == 1 || flag2 == 1)
		{
			mas[size] = '\0';
			cout << mas<<"\n";
			cnt = 0;
			flag1 = flag2 = flag3 =flag4= 0;
		}
		cout << "\nНажмите любую кнопку...\n";
		_getch();
		return 0;
		break;
	case 2:
		return 0;
		break;
	}
}

