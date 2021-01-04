// Randomizer
// Version 1.0
// Created by Sowtyy on 30.10.2020 @ 4:40 pm

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
		cout << "                                                                                                   \n";
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

	while (true)
	{
		cout << "1  =  Heads or Tails\n2  =  0 ~ 10000\n3  =  0 ~ 1000\n4  =  0 ~ 100\n5  =  0 ~ 10\n6  =  Custom\n\nChoose : ";
		cin >> chMode;

		SetCursorPosition(0, 0);

		switch (chMode)
		{
			case 1:
			{
				do
				{
					ranNum = rand() % 2; ranNum = rand() % 2; ranNum = rand() % 2;
					if (ranNum == 0)
					{
						cout << "Tails";
					}
					else if (ranNum == 1)
					{
						cout << "Heads";
					}
					
					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
			case 2:
			{
				do
				{
					ranNum = rand() % 10001; ranNum = rand() % 10001; ranNum = rand() % 10001;
					cout << ranNum;

					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
			case 3:
			{
				do
				{
					ranNum = rand() % 1001; ranNum = rand() % 1001; ranNum = rand() % 1001;
					cout << ranNum;

					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
			case 4:
			{
				do
				{
					ranNum = rand() % 101; ranNum = rand() % 101; ranNum = rand() % 101;
					cout << ranNum;

					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
			case 5:
			{
				do
				{
					ranNum = rand() % 11; ranNum = rand() % 11; ranNum = rand() % 11;
					cout << ranNum;

					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
			case 6:
			{
				do
				{
					cout << "Enter the smallest number : ";
					cin >> cuSmNum; cout << endl;

					cout << "Enter the largest number (less than 30000) : ";
					cin >> cuLaNum; cout << endl;

					SetCursorPosition(0, 0);

					ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1; ranNum = (rand() + cuSmNum) % cuLaNum + 1;
					cout << ranNum;

					cout << "\n\n\nPress any key to try again or 'ESC' to return to main menu";
					
					_kbhit();
					keyPr = _getch();
					
					SetCursorPosition(0, 0);
				}
				while (keyPr != 27);
				break;
			}
		}
	}
	return 0;
}