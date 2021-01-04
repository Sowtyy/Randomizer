// Randomizer
// Version 1.1.1
// Created by Sowtyy on 31.10.2020 @ 7:35 pm

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
	
	string blk(120, ' ');

	for (int i = 0; i < 30; i++)
	{
		cout << blk;
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);
}

int main()
{
	int chMode = 0;
	int ranNum = 0;
	int cuSmNum = 0;
	int cuLaNum = 0;
	int keyPr = 0;

	random_device rd;
	mt19937 mt(rd());;


	SetCursorPosition(0, 0);
	
	do
	{
		cout << " Choose a mode:\n\n\n";
		cout << " [1] - Heads or Tails\n";
		cout << " [2] - 0 ~ 10000\n";
		cout << " [3] - 0 ~ 1000\n";
		cout << " [4] - 0 ~ 100\n";
		cout << " [5] - 0 ~ 10\n";
		cout << " [6] - Custom Range\n\n";
		cout << " [ESC] - Exit\n";

		_kbhit();
		chMode = _getch();

		SetCursorPosition(0, 0);

		switch (chMode)
		{
			case 49:
			{
				do
				{
					cout << " +----------------------+\n";
					cout << " |    Heads or Tails    |\n";
					cout << " +----------------------+\n\n\n";

					uniform_int_distribution<int> dist(0, 1);
					ranNum = dist(mt);
					
					if (ranNum == 0)
					{
						cout << "  Tails";
					}
					else if (ranNum == 1)
					{
						cout << "  Heads";
					}
					
					cout << "\n\n\n\n";
					cout << " [ENTER]  -  To try again\n";
					cout << " [ESC]    -  To return to the main menu\n";
					
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
					cout << " +----------------------+\n";
					cout << " |       0 ~ 10000      |\n";
					cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 10000);
					ranNum = dist(mt);
					
					cout << "  " << ranNum;

					cout << "\n\n\n\n";
					cout << " [ENTER]  -  To try again\n";
					cout << " [ESC]    -  To return to the main menu\n";
					
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
					cout << " +----------------------+\n";
					cout << " |       0 ~ 1000       |\n";
					cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 1000);
					ranNum = dist(mt);

					cout << "  " << ranNum;

					cout << "\n\n\n\n";
					cout << " [ENTER]  -  To try again\n";
					cout << " [ESC]    -  To return to the main menu\n";
					
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
					cout << " +----------------------+\n";
					cout << " |        0 ~ 100       |\n";
					cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 100);
					ranNum = dist(mt);

					cout << "  " << ranNum;

					cout << "\n\n\n\n";
					cout << " [ENTER]  -  To try again\n";
					cout << " [ESC]    -  To return to the main menu\n";
					
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
					cout << " +----------------------+\n";
					cout << " |        0 ~ 10        |\n";
					cout << " +----------------------+\n\n\n";
					
					uniform_int_distribution<int> dist(0, 10);
					ranNum = dist(mt);

					cout << "  " << ranNum;

					cout << "\n\n\n\n";
					cout << " [ENTER]  -  To try again\n";
					cout << " [ESC]    -  To return to the main menu\n";

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
					cout << " +----------------------+\n";
					cout << " |     Custom Range     |\n";
					cout << " +----------------------+\n\n\n";
					
					cout << " Enter smallest number : ";
					cin >> cuSmNum;
					
					cout << " Enter largest number : ";
					cin >> cuLaNum;

					SetCursorPosition(0, 0);

					do
					{
						cout << " +----------------------+\n";
						cout << " |     Custom Range     |"; cout << "   " << cuSmNum << " ~ " << cuLaNum << endl;
						cout << " +----------------------+\n\n\n";

						//ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1;   <-- didn't work as expected
						//ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1); ranNum = cuSmNum + rand() % (cuLaNum - cuSmNum + 1);   <-- old method
						uniform_int_distribution<int> dist(cuSmNum, cuLaNum);
						ranNum = dist(mt);
						
						cout << "  " << ranNum;

						cout << "\n\n\n\n";
						cout << " [ENTER] = To try again with the same range\n";
						cout << " [R]     = To try again and set a new range\n";
						cout << " [ESC]   = To return to the main menu\n";

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
	
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tv1.1.1" << endl << endl << "\t\t\t\t\t\t\t\t\t\tby Sowtyy" << endl << "\t\t\t\t\t\t\t\t\t\t31.10.2020 @ 7:35 pm";
	Sleep(1000);
	
	return 0;
}