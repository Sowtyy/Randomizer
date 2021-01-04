// Randomizer
// Version 1.0.6
// Created by Sowtyy on 31.10.2020 @ 6:00 am

#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;


int SetCursorPosition(int X = 0, int Y = 0)
{
	COORD cords;
	cords.X = X; cords.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);
	
	for (int i = 0; i < 35; i++)
	{
		cout << "                                                                                                                        \n";
	}
	cords.X = X; cords.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);

	return 0;
}

int main()
{
	srand(time(0));
	int chMode = 0;
	int ranNum = 0;
	int cuSmNum = 0;
	int cuLaNum = 0;
	int keyPr = 0;


	SetCursorPosition(0, 0);
	
	do
	{
		cout << " Choose a mode:\n\n\n [1]    -  Heads or Tails\n [2]    -  0 ~ 10000\n [3]    -  0 ~ 1000\n [4]    -  0 ~ 100\n [5]    -  0 ~ 10\n [6]    -  Set Your Range\n\n [ESC]  -  Exit\n ";
		_kbhit();
		chMode = _getch();

		SetCursorPosition(0, 0);

		switch (chMode)
		{
			case 49:
			{
				do
				{
					cout << " +----------------------+\n |    Heads or Tails    |\n +----------------------+\n\n\n  ";

					ranNum = rand() % 2; ranNum = rand() % 2; ranNum = rand() % 2;
					if (ranNum == 0)
					{
						cout << "Tails";
					}
					else if (ranNum == 1)
					{
						cout << "Heads";
					}
					
					cout << "\n\n\n\n [ENTER]  -  To try again\n [ESC]    -  To return to the main menu\n ";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
					Sleep(50);
				}
				while (keyPr != 27);
				break;
			}
			case 50:
			{
				do
				{
					cout << " +----------------------+\n |       0 ~ 10000      |\n +----------------------+\n\n\n  ";
					
					ranNum = rand() % 10001; ranNum = rand() % 10001; ranNum = rand() % 10001;
					cout << ranNum;

					cout << "\n\n\n\n [ENTER]  -  To try again\n [ESC]    -  To return to the main menu\n ";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
					Sleep(50);
				}
				while (keyPr != 27);
				break;
			}
			case 51:
			{
				do
				{
					cout << " +----------------------+\n |       0 ~ 1000       |\n +----------------------+\n\n\n  ";
					
					ranNum = rand() % 1001; ranNum = rand() % 1001; ranNum = rand() % 1001;
					cout << ranNum;

					cout << "\n\n\n\n [ENTER]  -  To try again\n [ESC]    -  To return to the main menu\n ";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
					Sleep(50);
				}
				while (keyPr != 27);
				break;
			}
			case 52:
			{
				do
				{
					cout << " +----------------------+\n |       0 ~ 100        |\n +----------------------+\n\n\n  ";
					
					ranNum = rand() % 101; ranNum = rand() % 101; ranNum = rand() % 101;
					cout << ranNum;

					cout << "\n\n\n\n [ENTER]  -  To try again\n [ESC]    -  To return to the main menu\n ";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
					Sleep(50);
				}
				while (keyPr != 27);
				break;
			}
			case 53:
			{
				do
				{
					cout << " +----------------------+\n |        0 ~ 10        |\n +----------------------+\n\n\n  ";
					
					ranNum = rand() % 11; ranNum = rand() % 11; ranNum = rand() % 11;
					cout << ranNum;

					cout << "\n\n\n\n [ENTER]  -  To try again\n [ESC]    -  To return to the main menu\n ";

					_kbhit();
					keyPr = _getch();

					SetCursorPosition(0, 0);
					Sleep(50);
				}
				while (keyPr != 27);
				break;
			}
			case 54:
			{
				do
				{
					cout << " +----------------------+\n |     Custom Range     |\n +----------------------+\n\n\n";
					
					cout << " Enter smallest number : ";
					cin >> cuSmNum;
					
					cout << " Enter largest number (less than 30000) : ";
					cin >> cuLaNum;

					SetCursorPosition(0, 0);

					do
					{
						cout << " +----------------------+\n |     Custom Range     |   " << cuSmNum << " ~ " << cuLaNum << "\n +----------------------+\n\n\n  ";

						//ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1;   <-- didn't work as expected
						ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1);
						cout << ranNum;

						cout << "\n\n\n\n [ENTER]  =  To try again with the same range\n [R]      =  To try again and set a new range\n [ESC]    =  To return to the main menu\n ";

						Sleep(50);

						_kbhit();
						keyPr = _getch();

						SetCursorPosition(0, 0);
					}
					while (keyPr != 82 && keyPr != 114 && keyPr != 27);
				}
				while (keyPr == 82 || keyPr == 114);
				break;
			}
		}
	}
	while (chMode != 27);
	
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tv1.0.6" << endl << endl << "\t\t\t\t\t\t\t\t\t\tby Sowtyy" << endl << "\t\t\t\t\t\t\t\t\t\t31.10.2020 @ 6:00 am";
	Sleep(1000);
	
	return 0;
}