// Randomizer
// Version 1.1.3
// Created by Sowtyy on 01.11.2020 @ 3:40 am

#include <iostream>
#include <random>
#include <conio.h>
#include <windows.h>
#include <winuser.h>
using namespace std;


void SetCursorPosition(int X = 0, int Y = 0)
{
	COORD cords;
	cords.X = X; cords.Y = Y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);
}

void ClearScreen()
{
	COORD cords;
	cords.X = 0; cords.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);

	string blk(120, ' ');

	for (int i = 0; i < 30; i++)
	{
		cout << blk;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);
}

void ShowConsoleCursor(bool S = 1)
{
	HANDLE hCurs = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursInfo;
	
	GetConsoleCursorInfo(hCurs, &cursInfo);
	cursInfo.bVisible = S;
	SetConsoleCursorInfo(hCurs, &cursInfo);
}


void SetConsoleColor(int C = 7)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int coCons = C;
	SetConsoleTextAttribute(hCons, coCons);
}



int main()
{
	SetConsoleTitle(L"Randomizer 1.1.3");
	
	int chMode = 0;
	int ranNum = 0;
	int cuSmNum = 0;
	int cuLaNum = 0;
	int keyPr = 0;

	random_device rd;
	mt19937 mt(rd());

	ShowConsoleCursor(0);

	ClearScreen();
	
	do
	{
		SetConsoleColor(8);  cout << " +----------------------+\n";
		SetConsoleColor(8);  cout << " |    "; SetConsoleColor(7); cout << "CHOOSE A MODE:    "; SetConsoleColor(8); cout << "| \n";
		SetConsoleColor(8);  cout << " +----------------------+\n\n\n";
		SetConsoleColor(7);  cout << " [1]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 10000\n";
		SetConsoleColor(7);  cout << " [2]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 1000\n";
		SetConsoleColor(7);  cout << " [3]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 100\n";
		SetConsoleColor(7);  cout << " [4]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 10\n";
		SetConsoleColor(7);  cout << " [5]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " Heads or Tails\n";
		SetConsoleColor(7);  cout << " [6]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " Custom Range\n\n\n";
		SetConsoleColor(8);  cout << " [ESC] - Exit\n ";

		_kbhit();
		chMode = _getch();

		ClearScreen();

		if (chMode == 53 || chMode == 101 || chMode == 69)
		{
			do
			{
				SetConsoleColor(8); cout << " +----------------------+\n";
				SetConsoleColor(8); cout << " |    "; SetConsoleColor(7); cout << "Heads or Tails    "; SetConsoleColor(8); cout << "| \n";
				SetConsoleColor(8); cout << " +----------------------+\n";

				uniform_int_distribution<int> dist(0, 3);
				ranNum = dist(mt);

				SetCursorPosition(0, 9);
				
				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << "  -  To try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "    -  To return to the main menu\n ";

				SetCursorPosition(0, 5);

				SetConsoleColor(14);

				Sleep(50);

				if (ranNum == 0 || ranNum == 2)
				{
					cout << "  Tails";
				}
				else if (ranNum == 1 || ranNum == 3)
				{
					cout << "  Heads";
				}

				_kbhit();
				keyPr = _getch();

				ClearScreen();
			}
			while (keyPr != 27);
		}
		else if (chMode == 54 || chMode == 99 || chMode == 67)
		{
			do
			{
				SetConsoleColor(8); cout << " +----------------------+\n";
				SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "Custom Range     "; SetConsoleColor(8); cout << "| \n";
				SetConsoleColor(8); cout << " +----------------------+\n\n\n";

				SetConsoleColor(7); cout << " Enter smallest number : ";
				
				SetConsoleColor(8); cout << "\n\n\n\n\n Do not enter any letters here.";
				
				SetCursorPosition(25, 5);
				
				SetConsoleColor(7);

				ShowConsoleCursor(1);

				cin >> cuSmNum;

				SetConsoleColor(7); cout << "\n Enter largest number : ";
				cin >> cuLaNum;

				ShowConsoleCursor(0);

				ClearScreen();

				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "Custom Range     "; SetConsoleColor(8); cout << "| "; cout << "   "; SetConsoleColor(7); cout << cuSmNum << " ~ " << cuLaNum << endl;
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";

					//ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1;   <-- didn't work as expected
					//ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1);   <-- old method
					uniform_int_distribution<int> dist(cuSmNum, cuLaNum);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);

					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - To try again with the same range\n";
					SetConsoleColor(7); cout << " [R]";     SetConsoleColor(8); cout << "     - To try again and set a new range\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - To return to the main menu\n ";

					SetCursorPosition(0, 5);
					
					SetConsoleColor(14);

					Sleep(50);
					
					cout << "  " << ranNum;

					_kbhit();
					keyPr = _getch();

					ClearScreen();
				}
				while (keyPr != 82 && keyPr != 114 && keyPr != 27);
			}
			while (keyPr == 82 || keyPr == 114);
		}

		switch (chMode)
		{
			case 49:
			{
				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "  0 ~ 10000      "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 10000);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);
					
					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << "  -  To try again\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "    -  To return to the main menu\n ";
					
					SetCursorPosition(0, 5);
					
					SetConsoleColor(14);

					Sleep(50);

					cout << "  " << ranNum;
					
					_kbhit();
					keyPr = _getch();
					
					ClearScreen();
				}
				while (keyPr != 27);
				break;
			}
			case 50:
			{
				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "  0 ~ 1000       "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 1000);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);

					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << "  -  To try again\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "    -  To return to the main menu\n ";

					SetCursorPosition(0, 5);

					SetConsoleColor(14);

					Sleep(50);
					
					cout << "  " << ranNum;
					
					_kbhit();
					keyPr = _getch();
					
					ClearScreen();
				}
				while (keyPr != 27);
				break;
			}
			case 51:
			{
				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "  0 ~ 100        "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 100);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);

					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << "  -  To try again\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "    -  To return to the main menu\n ";

					SetCursorPosition(0, 5);

					SetConsoleColor(14);

					Sleep(50);
					
					cout << "  " << ranNum;
					
					_kbhit();
					keyPr = _getch();
					
					ClearScreen();
				}
				while (keyPr != 27);
				break;
			}
			case 52:
			{
				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |     "; SetConsoleColor(7); cout << "   0 ~ 10        "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 10);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);

					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << "  -  To try again\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "    -  To return to the main menu\n ";

					SetCursorPosition(0, 5);

					SetConsoleColor(14);

					Sleep(50);
					
					cout << "  " << ranNum;

					_kbhit();
					keyPr = _getch();

					ClearScreen();
				}
				while (keyPr != 27);
				break;
			}
		}
	}
	while (chMode != 27);

	SetConsoleColor(7);
	
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\tv1.1.3" << endl << endl << "\t\t\t\t\t\t\t\t\t\tby Sowtyy" << endl << "\t\t\t\t\t\t\t\t\t\t01.11.2020 @ 3:40 am";
	Sleep(1000);
	
	return 0;
}