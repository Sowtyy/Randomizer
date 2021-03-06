// Randomizer
// Version 1.2.3
// Created by Sowtyy on 07.11.2020 @ 9:00 am

#include <iostream>
#include <random>
#include <conio.h>
#include <windows.h>
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
	cursInfo.dwSize = 1;
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
	//string strTitle = "Randomizer 1.1.4 ";
	//wchar_t wTitle[1];
	//mbstowcs(wTitle, strTitle.c_str(), strTitle.length());
	//LPWSTR ptr = wTitle;
	//SetConsoleTitle(ptr); <-- didn't compile

	//SetConsoleTitle(L"Randomizer 1.1.4"); <-- didn't compile

	int chMode = 0;
	int ranNum = 0;
	int cuSmNum = 0;
	int cuLaNum = 0;
	int keyPr = 0;

	random_device rd;
	mt19937 mt(rd());

	ClearScreen();

	do
	{
		ShowConsoleCursor(0);

		SetConsoleColor(8);  cout << " +----------------------+\n";
		SetConsoleColor(8);  cout << " |      "; SetConsoleColor(7); cout << "RANDOMIZER"; SetConsoleColor(8); cout << " 1.2.3"; SetConsoleColor(8); cout << "| \n";
		SetConsoleColor(8);  cout << " +----------------------+\n\n\n";
		SetConsoleColor(7);  cout << " [1]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 10000\n";
		SetConsoleColor(7);  cout << " [2]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 1000\n";
		SetConsoleColor(7);  cout << " [3]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 100\n";
		SetConsoleColor(7);  cout << " [4]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " 0 ~ 10\n";
		SetConsoleColor(7);  cout << " [5]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " Heads or Tails\n";
		SetConsoleColor(7);  cout << " [6]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " Custom Number Range\n";
		SetConsoleColor(7);  cout << " [7]"; SetConsoleColor(8); cout << " -"; SetConsoleColor(7); cout << " Custom Random Text\n\n\n";
		SetConsoleColor(8);  cout << " [ESC] - Exit\n ";

		_kbhit();
		chMode = _getch();

		ClearScreen();

		if (chMode == 53)
		{
			do
			{
				SetConsoleColor(8); cout << " +----------------------+\n";
				SetConsoleColor(8); cout << " |    "; SetConsoleColor(7); cout << "Heads or Tails    "; SetConsoleColor(8); cout << "| \n";
				SetConsoleColor(8); cout << " +----------------------+\n";

				uniform_int_distribution<int> dist(0, 3);
				ranNum = dist(mt);

				SetCursorPosition(0, 9);

				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

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
			} while (keyPr != 27);
		}
		else if (chMode == 54)
		{
			do
			{
				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |  "; SetConsoleColor(7); cout << "Custom Number Range "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";

					SetConsoleColor(7); cout << " Enter smallest number : ";

					SetCursorPosition(0, 11);

					if (cuSmNum > cuLaNum)
					{
						SetCursorPosition(0, 11);
						SetConsoleColor(12); cout << " Error:"; SetConsoleColor(8); cout << " The smallest number must not be greater than the largest.\n\n";
					}

					SetConsoleColor(8); cout << " Note:"; SetConsoleColor(8); cout << " Do not enter any non-numeric characters here.";

					SetCursorPosition(25, 5);

					SetConsoleColor(7);

					ShowConsoleCursor(1);

					cin >> cuSmNum;

					SetConsoleColor(7); cout << "\n Enter largest number : ";
					cin >> cuLaNum;

					ShowConsoleCursor(0);

					ClearScreen();
				} while (cuSmNum > cuLaNum);

				do
				{
					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |  "; SetConsoleColor(7); cout << "Custom Number Range "; SetConsoleColor(8); cout << "| "; cout << "   "; SetConsoleColor(7); cout << cuSmNum << " ~ " << cuLaNum << endl;
					SetConsoleColor(8); cout << " +----------------------+\n\n\n";

					//ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1;   <-- didn't work as expected
					//ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1);   <-- old method
					uniform_int_distribution<int> dist(cuSmNum, cuLaNum);
					ranNum = dist(mt);

					SetCursorPosition(0, 9);

					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again with the same range\n";
					SetConsoleColor(7); cout << " [R]";     SetConsoleColor(8); cout << "     - Try again and set a new range\n";
					SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

					SetCursorPosition(0, 5);

					SetConsoleColor(14);

					Sleep(50);

					cout << "  " << ranNum;

					_kbhit();
					keyPr = _getch();

					ClearScreen();
				} while (keyPr != 82 && keyPr != 114 && keyPr != 170 && keyPr != 138 && keyPr != 27);
			} while (keyPr == 82 || keyPr == 114 || keyPr == 170 || keyPr == 138);
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

				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

				SetCursorPosition(0, 5);

				SetConsoleColor(14);

				Sleep(50);

				cout << "  " << ranNum;

				_kbhit();
				keyPr = _getch();

				ClearScreen();
			} while (keyPr != 27);
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

				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

				SetCursorPosition(0, 5);

				SetConsoleColor(14);

				Sleep(50);

				cout << "  " << ranNum;

				_kbhit();
				keyPr = _getch();

				ClearScreen();
			} while (keyPr != 27);
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

				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

				SetCursorPosition(0, 5);

				SetConsoleColor(14);

				Sleep(50);

				cout << "  " << ranNum;

				_kbhit();
				keyPr = _getch();

				ClearScreen();
			} while (keyPr != 27);
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

				SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again\n";
				SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

				SetCursorPosition(0, 5);

				SetConsoleColor(14);

				Sleep(50);

				cout << "  " << ranNum;

				_kbhit();
				keyPr = _getch();

				ClearScreen();
			} while (keyPr != 27);
			break;
		}
		case 55:
		{
			bool qtHelp = 0;
			int cPosX = 0;
			int cPosY = 5;
			int nLines = 0;
			char Line1[15] = { 48 }, Line2[15] = { 48 }, Line3[15] = { 48 }, Line4[15] = { 48 }, Line5[15] = { 48 }, Line6[15] = { 48 }, Line7[15] = { 48 },
				Line8[15] = { 48 }, Line9[15] = { 48 }, Line10[15] = { 48 }, Line11[15] = { 48 }, Line12[15] = { 48 }, Line13[15] = { 48 }, Line14[15] = { 48 },
				Line15[15] = { 48 }, Line16[15] = { 48 }, Line17[15] = { 48 }, Line18[15] = { 48 }, Line19[15] = { 48 }, Line20[15] = { 48 };

			do
			{
				do
				{
					keyPr = 0;

					SetCursorPosition(0, 0);

					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |"; SetConsoleColor(7); cout << "  Custom Random Text  "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n";

					SetConsoleColor(7);


					if (cPosX == 0 && cPosY == 5)
					{
						SetCursorPosition(1, 5);
						SetConsoleColor(144); cout << " 1"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line1 << endl;
					}
					else
					{
						SetCursorPosition(1, 5);
						SetConsoleColor(7); cout << " 1"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line1 << endl;
					}
					if (cPosX == 0 && cPosY == 6)
					{
						SetCursorPosition(1, 6);
						SetConsoleColor(144); cout << " 2"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line2 << endl;
					}
					else
					{
						SetCursorPosition(1, 6);
						SetConsoleColor(7); cout << " 2"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line2 << endl;
					}
					if (cPosX == 0 && cPosY == 7)
					{
						SetCursorPosition(1, 7);
						SetConsoleColor(144); cout << " 3"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line3 << endl;
					}
					else
					{
						SetCursorPosition(1, 7);
						SetConsoleColor(7); cout << " 3"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line3 << endl;
					}
					if (cPosX == 0 && cPosY == 8)
					{
						SetCursorPosition(1, 8);
						SetConsoleColor(144); cout << " 4"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line4 << endl;
					}
					else
					{
						SetCursorPosition(1, 8);
						SetConsoleColor(7); cout << " 4"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line4 << endl;
					}
					if (cPosX == 0 && cPosY == 9)
					{
						SetCursorPosition(1, 9);
						SetConsoleColor(144); cout << " 5"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line5 << endl;
					}
					else
					{
						SetCursorPosition(1, 9);
						SetConsoleColor(7); cout << " 5"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line5 << endl;
					}
					if (cPosX == 0 && cPosY == 10)
					{
						SetCursorPosition(1, 10);
						SetConsoleColor(144); cout << " 6"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line6 << endl;
					}
					else
					{
						SetCursorPosition(1, 10);
						SetConsoleColor(7); cout << " 6"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line6 << endl;
					}
					if (cPosX == 0 && cPosY == 11)
					{
						SetCursorPosition(1, 11);
						SetConsoleColor(144); cout << " 7"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line7 << endl;
					}
					else
					{
						SetCursorPosition(1, 11);
						SetConsoleColor(7); cout << " 7"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line7 << endl;
					}
					if (cPosX == 0 && cPosY == 12)
					{
						SetCursorPosition(1, 12);
						SetConsoleColor(144); cout << " 8"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line8 << endl;
					}
					else
					{
						SetCursorPosition(1, 12);
						SetConsoleColor(7); cout << " 8"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line8 << endl;
					}
					if (cPosX == 0 && cPosY == 13)
					{
						SetCursorPosition(1, 13);
						SetConsoleColor(144); cout << " 9"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line9 << endl;
					}
					else
					{
						SetCursorPosition(1, 13);
						SetConsoleColor(7); cout << " 9"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line9 << endl;
					}
					if (cPosX == 0 && cPosY == 14)
					{
						SetCursorPosition(1, 14);
						SetConsoleColor(144); cout << "10"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line10 << endl;
					}
					else
					{
						SetCursorPosition(1, 14);
						SetConsoleColor(7); cout << "10"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line10 << endl;
					}
					if (cPosX == 0 && cPosY == 15)
					{
						SetCursorPosition(20, 5);
						cPosX = 19;
						cPosY = 5;

						SetConsoleColor(144); cout << "11"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line11 << endl;
					}
					else
					{
						SetCursorPosition(20, 5);
						SetConsoleColor(7); cout << "11"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line11 << endl;
					}
					if (cPosX == 19 && cPosY == 4)
					{
						SetCursorPosition(1, 14);
						cPosX = 0;
						cPosY = 14;

						SetConsoleColor(144); cout << "10"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line10 << endl;
					}
					if (cPosX == 19 && cPosY == 5)
					{
						SetCursorPosition(20, 5);
						SetConsoleColor(144); cout << "11"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line11 << endl;
					}
					else
					{
						SetCursorPosition(20, 5);
						SetConsoleColor(7); cout << "11"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line11 << endl;
					}
					if (cPosX == 19 && cPosY == 6)
					{
						SetCursorPosition(20, 6);
						SetConsoleColor(144); cout << "12"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line12 << endl;
					}
					else
					{
						SetCursorPosition(20, 6);
						SetConsoleColor(7); cout << "12"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line12 << endl;
					}
					if (cPosX == 19 && cPosY == 7)
					{
						SetCursorPosition(20, 7);
						SetConsoleColor(144); cout << "13"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line13 << endl;
					}
					else
					{
						SetCursorPosition(20, 7);
						SetConsoleColor(7); cout << "13"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line13 << endl;
					}
					if (cPosX == 19 && cPosY == 8)
					{
						SetCursorPosition(20, 8);
						SetConsoleColor(144); cout << "14"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line14 << endl;
					}
					else
					{
						SetCursorPosition(20, 8);
						SetConsoleColor(7); cout << "14"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line14 << endl;
					}
					if (cPosX == 19 && cPosY == 9)
					{
						SetCursorPosition(20, 9);
						SetConsoleColor(144); cout << "15"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line15 << endl;
					}
					else
					{
						SetCursorPosition(20, 9);
						SetConsoleColor(7); cout << "15"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line15 << endl;
					}
					if (cPosX == 19 && cPosY == 10)
					{
						SetCursorPosition(20, 10);
						SetConsoleColor(144); cout << "16"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line16 << endl;
					}
					else
					{
						SetCursorPosition(20, 10);
						SetConsoleColor(7); cout << "16"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line16 << endl;
					}
					if (cPosX == 19 && cPosY == 11)
					{
						SetCursorPosition(20, 11);
						SetConsoleColor(144); cout << "17"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line17 << endl;
					}
					else
					{
						SetCursorPosition(20, 11);
						SetConsoleColor(7); cout << "17"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line17 << endl;
					}
					if (cPosX == 19 && cPosY == 12)
					{
						SetCursorPosition(20, 12);
						SetConsoleColor(144); cout << "18"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line18 << endl;
					}
					else
					{
						SetCursorPosition(20, 12);
						SetConsoleColor(7); cout << "18"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line18 << endl;
					}
					if (cPosX == 19 && cPosY == 13)
					{
						SetCursorPosition(20, 13);
						SetConsoleColor(144); cout << "19"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line19 << endl;
					}
					else
					{
						SetCursorPosition(20, 13);
						SetConsoleColor(7); cout << "19"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line19 << endl;
					}
					if (cPosX == 19 && cPosY == 14)
					{
						SetCursorPosition(20, 14);
						SetConsoleColor(144); cout << "20"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line20 << endl;
					}
					else
					{
						SetCursorPosition(20, 14);
						SetConsoleColor(7); cout << "20"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line20 << endl;
					}
					if (cPosX == 0 && cPosY == 4)
					{
						SetCursorPosition(20, 14);
						cPosX = 19;
						cPosY = 14;

						SetConsoleColor(144); cout << "20"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line20 << endl;
					}
					if (cPosX == 19 && cPosY == 15)
					{
						SetCursorPosition(1, 5);
						cPosX = 0;
						cPosY = 5;

						SetConsoleColor(144); cout << " 1"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line1 << endl;
					}

					SetCursorPosition(0, 18);

					SetConsoleColor(7); cout << " [>]"; SetConsoleColor(8); cout << "     - Next cell\n";
					SetConsoleColor(7); cout << " [<]"; SetConsoleColor(8); cout << "     - Previous cell\n";
					if (nLines <= 0)
					{
						SetConsoleColor(8); cout << " [S]"; SetConsoleColor(8); cout << "     - Randomize\n";
					}
					else if (nLines >= 1)
					{
						SetConsoleColor(7); cout << " [S]"; SetConsoleColor(8); cout << "     - Randomize\n";
					}
					SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Edit highlighted cell / Save changes\n";
					SetConsoleColor(7); cout << " [ESC]"; SetConsoleColor(8); cout << "   - Return to the main menu\n\n";
					if (qtHelp == 0)
					{
						SetCursorPosition(1, 24);
						SetConsoleColor(7); cout << "[Q]"; SetConsoleColor(8); cout << "     - Show / hide help\n";
					}
					else if (qtHelp == 1)
					{
						SetCursorPosition(1, 24);
						SetConsoleColor(240); cout << "[Q]"; SetConsoleColor(8); cout << "     - Show / hide help\n";
					}

					SetConsoleColor(7);
					
					if (qtHelp == 1)
					{
						SetCursorPosition(55, 5);
						cout << "1) Each cell must be filled in order;";
						SetCursorPosition(55, 7);
						cout << "2) '0' means the cell is disabled and does not count;";
						SetCursorPosition(55, 9);
						cout << "3) You can enter '0' in a cell to disable it;";
						SetCursorPosition(55, 11);
						cout << "4) You cannot randomize until at least one cell is filled;";
						SetCursorPosition(55, 15);
						cout << "You can close this help section by pressing [Q] again.";
					}
					else if (qtHelp == 0)
					{
						for (int i = 5; i < 20; i++)
						{
							string blk(65, ' ');
							SetCursorPosition(55, i);
							cout << blk;
						}
					}

					_kbhit();
					keyPr = _getch();


					if (keyPr == 46 || keyPr == 62 || keyPr == 238 || keyPr == 158)
					{
						cPosY++;
						SetCursorPosition(cPosX, cPosY);
					}
					
					else if (keyPr == 44 || keyPr == 60 || keyPr == 161 || keyPr == 129)
					{
						cPosY--;
						SetCursorPosition(cPosX, cPosY);
					}

					if (keyPr == 113 || keyPr == 81 || keyPr == 169 || keyPr == 137)
					{
						if (qtHelp == 0)
							qtHelp = 1;
						else if (qtHelp == 1)
							qtHelp = 0;
					}

				} while (keyPr != 13 && keyPr != 27 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155);

				ShowConsoleCursor(1);
				
				if (cPosX == 0 && cPosY == 5 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 5);

					if (Line1[0] == 48)
					{
						cin >> Line1;
						if (Line1[0] != 48)
							nLines++;
					}
					else if (Line1[0] != 48)
					{
						cin >> Line1;
						if (Line1[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 6 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 6);

					if (Line2[0] == 48)
					{
						cin >> Line2;
						if (Line2[0] != 48)
							nLines++;
					}
					else if (Line2[0] != 48)
					{
						cin >> Line2;
						if (Line2[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 7 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 7);

					if (Line3[0] == 48)
					{
						cin >> Line3;
						if (Line3[0] != 48)
							nLines++;
					}
					else if (Line3[0] != 48)
					{
						cin >> Line3;
						if (Line3[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 8 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 8);

					if (Line4[0] == 48)
					{
						cin >> Line4;
						if (Line4[0] != 48)
							nLines++;
					}
					else if (Line4[0] != 48)
					{
						cin >> Line4;
						if (Line4[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 9 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 9);

					if (Line5[0] == 48)
					{
						cin >> Line5;
						if (Line5[0] != 48)
							nLines++;
					}
					else if (Line5[0] != 48)
					{
						cin >> Line5;
						if (Line5[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 10 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 10);

					if (Line6[0] == 48)
					{
						cin >> Line6;
						if (Line6[0] != 48)
							nLines++;
					}
					else if (Line6[0] != 48)
					{
						cin >> Line6;
						if (Line6[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 11 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 11);

					if (Line7[0] == 48)
					{
						cin >> Line7;
						if (Line7[0] != 48)
							nLines++;
					}
					else if (Line7[0] != 48)
					{
						cin >> Line7;
						if (Line7[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 12 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 12);

					if (Line8[0] == 48)
					{
						cin >> Line8;
						if (Line8[0] != 48)
							nLines++;
					}
					else if (Line8[0] != 48)
					{
						cin >> Line8;
						if (Line8[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 13 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 13);

					if (Line9[0] == 48)
					{
						cin >> Line9;
						if (Line9[0] != 48)
							nLines++;
					}
					else if (Line9[0] != 48)
					{
						cin >> Line9;
						if (Line9[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 0 && cPosY == 14 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(5, 14);

					if (Line10[0] == 48)
					{
						cin >> Line10;
						if (Line10[0] != 48)
							nLines++;
					}
					else if (Line10[0] != 48)
					{
						cin >> Line10;
						if (Line10[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 5 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 5);

					if (Line11[0] == 48)
					{
						cin >> Line11;
						if (Line11[0] != 48)
							nLines++;
					}
					else if (Line11[0] != 48)
					{
						cin >> Line11;
						if (Line11[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 6 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 6);

					if (Line12[0] == 48)
					{
						cin >> Line12;
						if (Line12[0] != 48)
							nLines++;
					}
					else if (Line12[0] != 48)
					{
						cin >> Line12;
						if (Line12[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 7 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 7);

					if (Line13[0] == 48)
					{
						cin >> Line13;
						if (Line13[0] != 48)
							nLines++;
					}
					else if (Line13[0] != 48)
					{
						cin >> Line13;
						if (Line13[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 8 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 8);

					if (Line14[0] == 48)
					{
						cin >> Line14;
						if (Line14[0] != 48)
							nLines++;
					}
					else if (Line14[0] != 48)
					{
						cin >> Line14;
						if (Line14[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 9 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 9);

					if (Line15[0] == 48)
					{
						cin >> Line15;
						if (Line15[0] != 48)
							nLines++;
					}
					else if (Line15[0] != 48)
					{
						cin >> Line15;
						if (Line15[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 10 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 10);

					if (Line16[0] == 48)
					{
						cin >> Line16;
						if (Line16[0] != 48)
							nLines++;
					}
					else if (Line16[0] != 48)
					{
						cin >> Line16;
						if (Line16[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 11 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 11);

					if (Line17[0] == 48)
					{
						cin >> Line17;
						if (Line17[0] != 48)
							nLines++;
					}
					else if (Line17[0] != 48)
					{
						cin >> Line17;
						if (Line17[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 12 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 12);

					if (Line18[0] == 48)
					{
						cin >> Line18;
						if (Line18[0] != 48)
							nLines++;
					}
					else if (Line18[0] != 48)
					{
						cin >> Line18;
						if (Line18[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 13 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 13);

					if (Line19[0] == 48)
					{
						cin >> Line19;
						if (Line19[0] != 48)
							nLines++;
					}
					else if (Line19[0] != 48)
					{
						cin >> Line19;
						if (Line19[0] == 48)
							nLines--;
					}
					
				}
				else if (cPosX == 19 && cPosY == 14 && keyPr != 115 && keyPr != 83 && keyPr != 235 && keyPr != 155 && keyPr != 27)
				{
					SetCursorPosition(24, 14);

					if (Line20[0] == 48)
					{
						cin >> Line20;
						if (Line20[0] != 48)
							nLines++;
					}
					else if (Line20[0] != 48)
					{
						cin >> Line20;
						if (Line20[0] == 48)
							nLines--;
					}
					
				}

				ShowConsoleCursor(0);

				if (keyPr == 115 && nLines >= 1 || keyPr == 83 && nLines >= 1 || keyPr == 235 && nLines >= 1 || keyPr == 155 && nLines >= 1)
				{
					do
					{
						ShowConsoleCursor(0);

						ClearScreen();

						SetConsoleColor(8); cout << " +----------------------+\n";
						SetConsoleColor(8); cout << " |"; SetConsoleColor(7); cout << "  Custom Random Text  "; SetConsoleColor(8); cout << "| \n";
						SetConsoleColor(8); cout << " +----------------------+\n";

						cout << "\n\n\n";

						SetConsoleColor(7);

						uniform_int_distribution<int> dist(1, nLines);
						ranNum = dist(mt);

						SetCursorPosition(0, 9);

						SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - Try again with the same text\n";
						SetConsoleColor(7); cout << " [R]";     SetConsoleColor(8); cout << "     - Try again and enter new text\n";
						SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - Return to the main menu\n ";

						SetCursorPosition(2, 5);

						Sleep(50);

						switch (ranNum)
						{
						case 1:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line1; break;
						case 2:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line2; break;
						case 3:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line3; break;
						case 4:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line4; break;
						case 5:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line5; break;
						case 6:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line6; break;
						case 7:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line7; break;
						case 8:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line8; break;
						case 9:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line9; break;
						case 10:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line10; break;
						case 11:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line11; break;
						case 12:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line12; break;
						case 13:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line13; break;
						case 14:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line14; break;
						case 15:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line15; break;
						case 16:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line16; break;
						case 17:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line17; break;
						case 18:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line18; break;
						case 19:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line19; break;
						case 20:
							SetConsoleColor(14); cout << ranNum; SetConsoleColor(8); cout << ": "; SetConsoleColor(14); cout << Line20; break;
						}

						_kbhit();
						keyPr = _getch();
					} while (keyPr != 82 && keyPr != 114 && keyPr != 170 && keyPr != 138 && keyPr != 27);

					nLines = 0;
					Line1[0] = { '0' }, Line1[1] = { '\0' }, Line1[2] = { '\0' }, Line1[3] = { '\0' }, Line1[4] = { '\0' }, Line1[5] = { '\0' }, Line1[6] = { '\0' },
						Line1[7] = { '\0' }, Line1[8] = { '\0' }, Line1[9] = { '\0' }, Line1[10] = { '\0' }, Line1[11] = { '\0' }, Line1[12] = { '\0' },
						Line1[13] = { '\0' }, Line1[14] = { '\0' };
					Line2[0] = { '0' }, Line2[1] = { '\0' }, Line2[2] = { '\0' }, Line2[3] = { '\0' }, Line2[4] = { '\0' }, Line2[5] = { '\0' }, Line2[6] = { '\0' },
						Line2[7] = { '\0' }, Line2[8] = { '\0' }, Line2[9] = { '\0' }, Line2[10] = { '\0' }, Line2[11] = { '\0' }, Line2[12] = { '\0' },
						Line2[13] = { '\0' }, Line2[14] = { '\0' };
					Line3[0] = { '0' }, Line3[1] = { '\0' }, Line3[2] = { '\0' }, Line3[3] = { '\0' }, Line3[4] = { '\0' }, Line3[5] = { '\0' }, Line3[6] = { '\0' },
						Line3[7] = { '\0' }, Line3[8] = { '\0' }, Line3[9] = { '\0' }, Line3[10] = { '\0' }, Line3[11] = { '\0' }, Line3[12] = { '\0' },
						Line3[13] = { '\0' }, Line3[14] = { '\0' };
					Line4[0] = { '0' }, Line4[1] = { '\0' }, Line4[2] = { '\0' }, Line4[3] = { '\0' }, Line4[4] = { '\0' }, Line4[5] = { '\0' }, Line4[6] = { '\0' },
						Line4[7] = { '\0' }, Line4[8] = { '\0' }, Line4[9] = { '\0' }, Line4[10] = { '\0' }, Line4[11] = { '\0' }, Line4[12] = { '\0' },
						Line4[13] = { '\0' }, Line4[14] = { '\0' };
					Line5[0] = { '0' }, Line5[1] = { '\0' }, Line5[2] = { '\0' }, Line5[3] = { '\0' }, Line5[4] = { '\0' }, Line5[5] = { '\0' }, Line5[6] = { '\0' },
						Line5[7] = { '\0' }, Line5[8] = { '\0' }, Line5[9] = { '\0' }, Line5[10] = { '\0' }, Line5[11] = { '\0' }, Line5[12] = { '\0' },
						Line5[13] = { '\0' }, Line5[14] = { '\0' };
					Line6[0] = { '0' }, Line6[1] = { '\0' }, Line6[2] = { '\0' }, Line6[3] = { '\0' }, Line6[4] = { '\0' }, Line6[5] = { '\0' }, Line6[6] = { '\0' },
						Line6[7] = { '\0' }, Line6[8] = { '\0' }, Line6[9] = { '\0' }, Line6[10] = { '\0' }, Line6[11] = { '\0' }, Line6[12] = { '\0' },
						Line6[13] = { '\0' }, Line6[14] = { '\0' };
					Line7[0] = { '0' }, Line7[1] = { '\0' }, Line7[2] = { '\0' }, Line7[3] = { '\0' }, Line7[4] = { '\0' }, Line7[5] = { '\0' }, Line7[6] = { '\0' },
						Line7[7] = { '\0' }, Line7[8] = { '\0' }, Line7[9] = { '\0' }, Line7[10] = { '\0' }, Line7[11] = { '\0' }, Line7[12] = { '\0' },
						Line7[13] = { '\0' }, Line7[14] = { '\0' };
					Line8[0] = { '0' }, Line8[1] = { '\0' }, Line8[2] = { '\0' }, Line8[3] = { '\0' }, Line8[4] = { '\0' }, Line8[5] = { '\0' }, Line8[6] = { '\0' },
						Line8[7] = { '\0' }, Line8[8] = { '\0' }, Line8[9] = { '\0' }, Line8[10] = { '\0' }, Line8[11] = { '\0' }, Line8[12] = { '\0' },
						Line8[13] = { '\0' }, Line8[14] = { '\0' };
					Line9[0] = { '0' }, Line9[1] = { '\0' }, Line9[2] = { '\0' }, Line9[3] = { '\0' }, Line9[4] = { '\0' }, Line9[5] = { '\0' }, Line9[6] = { '\0' },
						Line9[7] = { '\0' }, Line9[8] = { '\0' }, Line9[9] = { '\0' }, Line9[10] = { '\0' }, Line9[11] = { '\0' }, Line9[12] = { '\0' },
						Line9[13] = { '\0' }, Line9[14] = { '\0' };
					Line10[0] = { '0' }, Line10[1] = { '\0' }, Line10[2] = { '\0' }, Line10[3] = { '\0' }, Line10[4] = { '\0' }, Line10[5] = { '\0' },
						Line10[6] = { '\0' }, Line10[7] = { '\0' }, Line10[8] = { '\0' }, Line10[9] = { '\0' }, Line10[10] = { '\0' }, Line10[11] = { '\0' },
						Line10[12] = { '\0' }, Line10[13] = { '\0' }, Line10[14] = { '\0' };
					Line11[0] = { '0' }, Line11[1] = { '\0' }, Line11[2] = { '\0' }, Line11[3] = { '\0' }, Line11[4] = { '\0' }, Line11[5] = { '\0' },
						Line11[6] = { '\0' }, Line11[7] = { '\0' }, Line11[8] = { '\0' }, Line11[9] = { '\0' }, Line11[10] = { '\0' }, Line11[11] = { '\0' },
						Line11[12] = { '\0' }, Line11[13] = { '\0' }, Line11[14] = { '\0' };
					Line12[0] = { '0' }, Line12[1] = { '\0' }, Line12[2] = { '\0' }, Line12[3] = { '\0' }, Line12[4] = { '\0' }, Line12[5] = { '\0' },
						Line12[6] = { '\0' }, Line12[7] = { '\0' }, Line12[8] = { '\0' }, Line12[9] = { '\0' }, Line12[10] = { '\0' }, Line12[11] = { '\0' },
						Line12[12] = { '\0' }, Line12[13] = { '\0' }, Line12[14] = { '\0' };
					Line13[0] = { '0' }, Line13[1] = { '\0' }, Line13[2] = { '\0' }, Line13[3] = { '\0' }, Line13[4] = { '\0' }, Line13[5] = { '\0' },
						Line13[6] = { '\0' }, Line13[7] = { '\0' }, Line13[8] = { '\0' }, Line13[9] = { '\0' }, Line13[10] = { '\0' }, Line13[11] = { '\0' },
						Line13[12] = { '\0' }, Line13[13] = { '\0' }, Line13[14] = { '\0' };
					Line14[0] = { '0' }, Line14[1] = { '\0' }, Line14[2] = { '\0' }, Line14[3] = { '\0' }, Line14[4] = { '\0' }, Line14[5] = { '\0' },
						Line14[6] = { '\0' }, Line14[7] = { '\0' }, Line14[8] = { '\0' }, Line14[9] = { '\0' }, Line14[10] = { '\0' }, Line14[11] = { '\0' },
						Line14[12] = { '\0' }, Line14[13] = { '\0' }, Line14[14] = { '\0' };
					Line15[0] = { '0' }, Line15[1] = { '\0' }, Line15[2] = { '\0' }, Line15[3] = { '\0' }, Line15[4] = { '\0' }, Line15[5] = { '\0' },
						Line15[6] = { '\0' }, Line15[7] = { '\0' }, Line15[8] = { '\0' }, Line15[9] = { '\0' }, Line15[10] = { '\0' }, Line15[11] = { '\0' },
						Line15[12] = { '\0' }, Line15[13] = { '\0' }, Line15[14] = { '\0' };
					Line16[0] = { '0' }, Line16[1] = { '\0' }, Line16[2] = { '\0' }, Line16[3] = { '\0' }, Line16[4] = { '\0' }, Line16[5] = { '\0' },
						Line16[6] = { '\0' }, Line16[7] = { '\0' }, Line16[8] = { '\0' }, Line16[9] = { '\0' }, Line16[10] = { '\0' }, Line16[11] = { '\0' },
						Line16[12] = { '\0' }, Line16[13] = { '\0' }, Line16[14] = { '\0' };
					Line17[0] = { '0' }, Line17[1] = { '\0' }, Line17[2] = { '\0' }, Line17[3] = { '\0' }, Line17[4] = { '\0' }, Line17[5] = { '\0' },
						Line17[6] = { '\0' }, Line17[7] = { '\0' }, Line17[8] = { '\0' }, Line17[9] = { '\0' }, Line17[10] = { '\0' }, Line17[11] = { '\0' },
						Line17[12] = { '\0' }, Line17[13] = { '\0' }, Line17[14] = { '\0' };
					Line18[0] = { '0' }, Line18[1] = { '\0' }, Line18[2] = { '\0' }, Line18[3] = { '\0' }, Line18[4] = { '\0' }, Line18[5] = { '\0' },
						Line18[6] = { '\0' }, Line18[7] = { '\0' }, Line18[8] = { '\0' }, Line18[9] = { '\0' }, Line18[10] = { '\0' }, Line18[11] = { '\0' },
						Line18[12] = { '\0' }, Line18[13] = { '\0' }, Line18[14] = { '\0' };
					Line19[0] = { '0' }, Line19[1] = { '\0' }, Line19[2] = { '\0' }, Line19[3] = { '\0' }, Line19[4] = { '\0' }, Line19[5] = { '\0' },
						Line19[6] = { '\0' }, Line19[7] = { '\0' }, Line19[8] = { '\0' }, Line19[9] = { '\0' }, Line19[10] = { '\0' }, Line19[11] = { '\0' },
						Line19[12] = { '\0' }, Line19[13] = { '\0' }, Line19[14] = { '\0' };
					Line20[0] = { '0' }, Line20[1] = { '\0' }, Line20[2] = { '\0' }, Line20[3] = { '\0' }, Line20[4] = { '\0' }, Line20[5] = { '\0' },
						Line20[6] = { '\0' }, Line20[7] = { '\0' }, Line20[8] = { '\0' }, Line20[9] = { '\0' }, Line20[10] = { '\0' }, Line20[11] = { '\0' },
						Line20[12] = { '\0' }, Line20[13] = { '\0' }, Line20[14] = { '\0' };
				}

				ClearScreen();

				if (keyPr == 27)
					break;
			} while (keyPr != 27 || keyPr == 82 || keyPr == 114 || keyPr == 170 || keyPr == 138);
		}
		}
	} while (chMode != 27);

	SetConsoleColor(7);

	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\tv1.2.3" << endl << endl << "\t\t\t\t\t\t\t\t\t\tby Sowtyy" << endl << "\t\t\t\t\t\t\t\t\t\t07.11.2020 @ 9:00 am";
	Sleep(1000);

	return 0;
}