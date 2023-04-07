#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void NoTYPE()
{
	CONSOLE_CURSOR_INFO inffo;
	inffo.bVisible = false;
	inffo.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inffo);
}

void Chosse(int y)
{
	textcolor(12);
	gotoxy(45, y);
	cout << "->";
	textcolor(15);
}

void HienThiHD()
{

	//HƯỚNG DẪN
	textcolor(13);
	gotoxy(100, 18);
	cout << "~~~ Huong Dan ~~~";

	textcolor(10);
	gotoxy(110, 20);
	cout << "^";
	gotoxy(104, 21);
	cout << "UP:   |";

	gotoxy(104, 23);
	cout << "DOWN: |";
	gotoxy(110, 24);
	cout << "v";

	gotoxy(104, 25);
	cout << "CHOSSE: Enter";
}

void HienThiMenu(string lc1, string lc2, string lc3, int x)
{
	string s[10];
	s[0] = lc1;
	s[1] = lc2;
	s[2] = lc3;

	textcolor(13);
	gotoxy(48, 13);
	cout << "~~~~ MENU ~~~~";
	textcolor(15);
	gotoxy(x, 15);
	cout << s[0];
	gotoxy(x, 17);
	cout << s[1];
	gotoxy(x, 19);
	cout << s[2];
}
int CHOSSEMENU(string lc1, string lc2, string lc3, int x)
{
	NoTYPE();
	int check = 0;
	int SoLuongMenu = 2;
	int idy = 15;
	Chosse(15);
	while (true)
	{
		HienThiMenu(lc1, lc2, lc3, x);
		HienThiHD();
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (check == SoLuongMenu)
			{
				Sleep(150);
				clrscr();
				idy = 15;
				Chosse(idy);
				check = 0;

			}
			else
			{
				Sleep(150);
				clrscr();
				Chosse(idy + 2);
				idy += 2;
				check++;

			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (check != 0)
			{
				Sleep(150);
				idy -= 2;
				clrscr();
				Chosse(idy);
				check--;

			}
			else
			{
				Sleep(150);
				idy = 19;
				clrscr();
				Chosse(idy);
				check = SoLuongMenu;

			}
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			if (check == 0)
			{
				return 0;
			}
			else if (check == 1)
			{
				return 1;
			}
			else if (check == 2)
			{
				return 2;
			}
		}

	}

}
