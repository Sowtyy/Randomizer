// Randomizer
// Version 1.2.0
// Created by Sowtyy on 01.11.2020 @ 8:50 pm

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
		SetConsoleColor(8);  cout << " |      "; SetConsoleColor(7); cout << "RANDOMIZER"; SetConsoleColor(8); cout << " 1.2.0"; SetConsoleColor(8); cout << "| \n";
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
				}
				while (cuSmNum > cuLaNum);

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
				while (keyPr != 82 && keyPr != 114 && keyPr != 170 && keyPr != 138 && keyPr != 27);
			}
			while (keyPr == 82 || keyPr == 114 || keyPr == 170 || keyPr == 138);
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
			case 55:
			{
				int chLine = 0;
				int nLines = 0;
				int Line1 = 0, Line2 = 0, Line3 = 0, Line4 = 0, Line5 = 0, Line6 = 0, Line7 = 0, Line8 = 0, Line9 = 0, Line10 = 0, Line11 = 0, Line12 = 0,
					Line13 = 0, Line14 = 0, Line15 = 0, Line16 = 0, Line17 = 0, Line18 = 0, Line19 = 0, Line20 = 0;

				do
				{
					keyPr = 0;

					SetConsoleColor(8); cout << " +----------------------+\n";
					SetConsoleColor(8); cout << " |"; SetConsoleColor(7); cout << "  Custom Random Text  "; SetConsoleColor(8); cout << "| \n";
					SetConsoleColor(8); cout << " +----------------------+\n";

					ShowConsoleCursor(1);

					SetConsoleColor(7);

					SetCursorPosition(0, 8);
					
					cout << "  1"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line1 << endl;
					cout << "  2"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line2 << endl;
					cout << "  3"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line3 << endl;
					cout << "  4"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line4 << endl;
					cout << "  5"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line5 << endl;
					cout << "  6"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line6 << endl;
					cout << "  7"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line7 << endl;
					cout << "  8"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line8 << endl;
					cout << "  9"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line9 << endl;
					cout << " 10"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line10 << endl;
					SetCursorPosition(19, 8);
					cout << " 11"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line11 << endl;
					SetCursorPosition(19, 9);
					cout << " 12"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line12 << endl;
					SetCursorPosition(19, 10);
					cout << " 13"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line13 << endl;
					SetCursorPosition(19, 11);
					cout << " 14"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line14 << endl;
					SetCursorPosition(19, 12);
					cout << " 15"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line15 << endl;
					SetCursorPosition(19, 13);
					cout << " 16"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line16 << endl;
					SetCursorPosition(19, 14);
					cout << " 17"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line17 << endl;
					SetCursorPosition(19, 15);
					cout << " 18"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line18 << endl;
					SetCursorPosition(19, 16);
					cout << " 19"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line19 << endl;
					SetCursorPosition(19, 17);
					cout << " 20"; SetConsoleColor(8); cout << ": "; SetConsoleColor(7); cout << Line20 << endl;

					SetCursorPosition(0, 5);

					cout << " Choose line/option : ";
					cin >> chLine;
					
					switch (chLine)
					{
						case 1:
						{
							SetCursorPosition(5, 8);

							if (Line1 == 0)
							{
								cin >> Line1;								
								if (Line1 != 0)
									nLines++;
							}
							else if (Line1 != 0)
							{
								cin >> Line1;
								if (Line1 == 0)
									nLines--;
							}
							break;
						}
						case 2:
						{
							SetCursorPosition(5, 9);

							if (Line2 == 0)
								cin >> Line2;
								if (Line2 != 0)
									nLines++;
							else if (Line2 != 0)
							{
								cin >> Line2;
								if (Line2 == 0)
									nLines--;
							}
							break;
						}
						case 3:
						{
							SetCursorPosition(5, 10);

							if (Line3 == 0)
							{
								cin >> Line3;
								if (Line3 != 0)
									nLines++;
							}
							else if (Line3 != 0)
							{
								cin >> Line3;
								if (Line3 == 0)
									nLines--;
							}
							break;
						}
						case 4:
						{
							SetCursorPosition(5, 11);

							if (Line4 == 0)
							{
								cin >> Line4;
								if (Line4 != 0)
									nLines++;
							}
							else if (Line4 != 0)
							{
								cin >> Line4;
								if (Line4 == 0)
									nLines--;
							}
							break;
						}
						case 5:
						{
							SetCursorPosition(5, 12);

							if (Line5 == 0)
							{
								cin >> Line5;
								if (Line5 != 0)
									nLines++;
							}
							else if (Line5 != 0)
							{
								cin >> Line5;
								if (Line5 == 0)
									nLines--;
							}
							break;
						}
						case 6:
						{
							SetCursorPosition(5, 13);

							if (Line6 == 0)
							{
								cin >> Line6;
								if (Line6 != 0)
									nLines++;
							}
							else if (Line6 != 0)
							{
								cin >> Line6;
								if (Line6 == 0)
									nLines--;
							}
							break;
						}
						case 7:
						{
							SetCursorPosition(5, 14);

							if (Line7 == 0)
							{
								cin >> Line7;
								if (Line7 != 0)
									nLines++;
							}
							else if (Line7 != 0)
							{
								cin >> Line7;
								if (Line7 == 0)
									nLines--;
							}
							break;
						}
						case 8:
						{
							SetCursorPosition(5, 15);

							if (Line8 == 0)
							{
								cin >> Line8;
								if (Line8 != 0)
									nLines++;
							}
							else if (Line8 != 0)
							{
								cin >> Line8;
								if (Line8 == 0)
									nLines--;
							}
							break;
						}
						case 9:
						{
							SetCursorPosition(5, 16);

							if (Line9 == 0)
							{
								cin >> Line9;
								if (Line9 != 0)
									nLines++;
							}
							else if (Line9 != 0)
							{
								cin >> Line9;
								if (Line9 == 0)
									nLines--;
							}
							break;
						}
						case 10:
						{
							SetCursorPosition(5, 17);

							if (Line10 == 0)
							{
								cin >> Line10;
								if (Line10 != 0)
									nLines++;
							}
							else if (Line10 != 0)
							{
								cin >> Line10;
								if (Line10 == 0)
									nLines--;
							}
							break;
						}
						case 11:
						{
							SetCursorPosition(24, 8);

							if (Line11 == 0)
							{
								cin >> Line11;
								if (Line11 != 0)
									nLines++;
							}
							else if (Line11 != 0)
							{
								cin >> Line11;
								if (Line11 == 0)
									nLines--;
							}
							break;
						}
						case 12:
						{
							SetCursorPosition(24, 9);

							if (Line12 == 0)
							{
								cin >> Line12;
								if (Line12 != 0)
									nLines++;
							}
							else if (Line12 != 0)
							{
								cin >> Line12;
								if (Line12 == 0)
									nLines--;
							}
							break;
						}
						case 13:
						{
							SetCursorPosition(24, 10);

							if (Line13 == 0)
							{
								cin >> Line13;
								if (Line13 != 0)
									nLines++;
							}
							else if (Line13 != 0)
							{
								cin >> Line13;
								if (Line13 == 0)
									nLines--;
							}
							break;
						}
						case 14:
						{
							SetCursorPosition(24, 11);

							if (Line14 == 0)
							{
								cin >> Line14;
								if (Line14 != 0)
									nLines++;
							}
							else if (Line14 != 0)
							{
								cin >> Line14;
								if (Line14 == 0)
									nLines--;
							}
							break;
						}
						case 15:
						{
							SetCursorPosition(24, 12);

							if (Line15 == 0)
							{
								cin >> Line15;
								if (Line15 != 0)
									nLines++;
							}
							else if (Line15 != 0)
							{
								cin >> Line15;
								if (Line15 == 0)
									nLines--;
							}
							break;
						}
						case 16:
						{
							SetCursorPosition(24, 13);

							if (Line16 == 0)
							{
								cin >> Line16;
								if (Line16 != 0)
									nLines++;
							}
							else if (Line16 != 0)
							{
								cin >> Line16;
								if (Line16 == 0)
									nLines--;
							}
							break;
						}
						case 17:
						{
							SetCursorPosition(24, 14);

							if (Line17 == 0)
							{
								cin >> Line17;
								if (Line17 != 0)
									nLines++;
							}
							else if (Line17 != 0)
							{
								cin >> Line17;
								if (Line17 == 0)
									nLines--;
							}
							break;
						}
						case 18:
						{
							SetCursorPosition(24, 15);

							if (Line18 == 0)
							{
								cin >> Line18;
								if (Line18 != 0)
									nLines++;
							}
							else if (Line18 != 0)
							{
								cin >> Line18;
								if (Line18 == 0)
									nLines--;
							}
							break;
						}
						case 19:
						{
							SetCursorPosition(24, 16);

							if (Line19 == 0)
							{
								cin >> Line19;
								if (Line19 != 0)
									nLines++;
							}
							else if (Line19 != 0)
							{
								cin >> Line19;
								if (Line19 == 0)
									nLines--;
							}
							break;
						}
						case 20:
						{
							SetCursorPosition(24, 17);

							if (Line20 == 0)
							{
								cin >> Line20;
								if (Line20 != 0)
									nLines++;
							}
							else if (Line20 != 0)
							{
								cin >> Line20;
								if (Line20 == 0)
									nLines--;
							}
							break;
						}
						case 111:
						{
							do
							{
								ClearScreen();

								SetConsoleColor(8); cout << " +----------------------+\n";
								SetConsoleColor(8); cout << " |"; SetConsoleColor(7); cout << "  Custom Random Text  "; SetConsoleColor(8); cout << "| \n";
								SetConsoleColor(8); cout << " +----------------------+\n";

								cout << "\n\n\n";

								SetConsoleColor(7);

								uniform_int_distribution<int> dist(1, nLines);
								ranNum = dist(mt);

								SetCursorPosition(2, 5);

								switch (ranNum)
								{
									case 1:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line1; break;
									case 2:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line2; break;
									case 3:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line3; break;
									case 4:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line4; break;
									case 5:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line5; break;
									case 6:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line6; break;
									case 7:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line7; break;
									case 8:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line8; break;
									case 9:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line9; break;
									case 10:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line10; break;
									case 11:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line11; break;
									case 12:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line12; break;
									case 13:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line13; break;
									case 14:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line14; break;
									case 15:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line15; break;
									case 16:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line16; break;
									case 17:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line17; break;
									case 18:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line18; break;
									case 19:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line19; break;
									case 20:
										cout << ranNum; SetConsoleColor(8); cout << " : "; SetConsoleColor(7); cout << Line20; break;
								}

								cout << "\n\n\n\n";

								SetConsoleColor(7); cout << " [ENTER]"; SetConsoleColor(8); cout << " - To try again with the same text\n";
								SetConsoleColor(7); cout << " [R]";     SetConsoleColor(8); cout << "     - To try again and enter new text\n";
								SetConsoleColor(7); cout << " [ESC]";   SetConsoleColor(8); cout << "   - To return to the main menu\n ";

								_kbhit();
								keyPr = _getch();
							}
							while (keyPr != 82 && keyPr != 114 && keyPr != 170 && keyPr != 138 && keyPr != 27);

							nLines = 0;
							Line1 = 0, Line2 = 0, Line3 = 0, Line4 = 0, Line5 = 0, Line6 = 0, Line7 = 0, Line8 = 0, Line9 = 0, Line10 = 0, Line11 = 0, Line12 = 0,
								Line13 = 0, Line14 = 0, Line15 = 0, Line16 = 0, Line17 = 0, Line18 = 0, Line19 = 0, Line20 = 0;
						}
					}
					ClearScreen();
					
					if (keyPr == 27 || chLine == 0)
						break;
				}
				while (keyPr != 27 || keyPr == 82 || keyPr == 114 || keyPr == 170 || keyPr == 138);
			}
		}
	}
	while (chMode != 27);

	SetConsoleColor(7);
	
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\tv1.2.0" << endl << endl << "\t\t\t\t\t\t\t\t\t\tby Sowtyy" << endl << "\t\t\t\t\t\t\t\t\t\t01.11.2020 @ 8:50 pm";
	Sleep(1000);
	
	return 0;
}