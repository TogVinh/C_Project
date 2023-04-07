#include "VeMenu.h"
#include <fstream>
#include <vector>
#include <conio.h>
#include <Windows.h>



void INTRO()
{
	ifstream FileIn, FileIn1;
	FileIn.open("INTRO.pro");
	FileIn1.open("INTRO1.pro");
	
	if (!FileIn)
	{
		cout << "\nKhong co file intro\n";
		system("pause");
		clrscr();
		return;
		
	}
	if (!FileIn1)
	{
		cout << "\nKhong co file intro\n";
		system("pause");
		clrscr();
		return;
	}

	while (!FileIn1.eof())
	{
		textcolor(9);
		string x;
		getline(FileIn1, x);
		cout << x << endl;
	}

	int idx = 40;
	int color = 7;
	while (!FileIn.eof())
	{
		char x;
		FileIn >> x;
		gotoxy(idx + 3, 15);
		textcolor(color);
		if (x == '_')
		{
			x = ' ';
		}
		cout << x;
		Sleep(80);
		idx++; color++;
		if (color == 16)
		{
			color = 7;
		}
		if (idx == 67)
		{
			break;
		}
	}
	textcolor(9);
	gotoxy(43, 16);
	cout << "NHAN PHIM BAT KI DE BAT DAU" << endl;
	gotoxy(43, 17);
	textcolor(15);
	system("pause");
	clrscr();
	GetAsyncKeyState(VK_RETURN);
}
void LOAD()
{

	for (int j = 0; j < 5; j++)
	{
		gotoxy(48, 15);
		cout << "LOADING";
		for (int i = 0; i < 3; i++)
		{
			Sleep(90);
			cout << ".";
		}
		clrscr();
	}

}


typedef struct BaiTap
{
	vector<string> ARRmorse;
	vector<char> ARRChar;
	int SoLuong;
};
void Push(vector<string> &ARR, string x)
{
	ARR.push_back(x);
}
void QuyUoc(vector<string> &ARR)
{
	Push(ARR, "._");//A
	Push(ARR, "_...");
	Push(ARR, "_._.");
	Push(ARR, "_..");
	Push(ARR, ".");
	Push(ARR, ".._.");
	Push(ARR, "__.");//G
	Push(ARR, "....");
	Push(ARR, "..");
	Push(ARR, ".___");
	Push(ARR, "_._");
	Push(ARR, "._..");//L
	Push(ARR, "__");//M
	Push(ARR, "_.");//N
	Push(ARR, "___");//O
	Push(ARR, ".__.");//P
	Push(ARR, "__._");
	Push(ARR, "._.");
	Push(ARR, "...");
	Push(ARR, "_");
	Push(ARR, ".._");
	Push(ARR, "..._");
	Push(ARR, ".__");
	Push(ARR, "_.._");
	Push(ARR, "_.__");//Y
	Push(ARR, "__..");
	Push(ARR, "_____");//0
	Push(ARR, ".____");//1
	Push(ARR, "..___");
	Push(ARR, "...__");
	Push(ARR, "...._");
	Push(ARR, ".....");
	Push(ARR, "_....");
	Push(ARR, "__...");
	Push(ARR, "___..");
	Push(ARR, "____.");
	Push(ARR, "/");

}
void GiaiMa(vector<string> input, BaiTap bt, ofstream &FileOut)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < bt.SoLuong; j++)
		{
			if (input[i] == bt.ARRmorse[j])
			{
				//Ghi vào file 
				FileOut << bt.ARRChar[j];
				break;
			}
		}
	}
}


void MaHoa(BaiTap bt, ifstream &FileIn, ofstream &FileOut)
{
	string VanBan;
	while (!FileIn.eof())
	{
		getline(FileIn, VanBan);
	}
	
	for (int i = 0; i < VanBan.length(); i++)
	{
		for (int j = 0; j < bt.SoLuong; j++)
		{
			if (VanBan[i] == bt.ARRChar[j])
			{
				FileOut << bt.ARRmorse[j] << ' ';
				break;
			}
		}
	}

}

int main()
{
	NoTYPE();
	//Giới thiệu
	INTRO();
	LOAD();
	
	
	
	//Khởi tạo giá trị cho ARRChar
	char tempchar[100];
	
	int idtemchar = 0;
	for (int i = 65; i <= 90; i++)
	{
		tempchar[idtemchar] = i;
		//cout << tempchar[idtemchar] << endl;
		idtemchar++;
		
	}
	//A, B,...z 0
	char a[100];
	for (int i = 0; i < idtemchar; i++)
	{
		a[i] = tempchar[i];
	}
	for (int i = 48; i <= 57; i++)
	{
		char c = i;
		a[idtemchar] = c;
		idtemchar++;
	}
	a[idtemchar] = ' ';


	//khởi tạo giá trị cho ARRmorse và push vào vector
	BaiTap bt;
	vector<string> ARR;
	QuyUoc(ARR);
	bt.ARRmorse.resize(ARR.size());
	for (int i = 0; i < ARR.size(); i++)
	{
		//Khởi tạo các giá trị cho struct BaiTap
		bt.ARRmorse[i] = ARR[i];
		bt.ARRChar.push_back(a[i]);
	}
	bt.SoLuong = ARR.size();
	
	//Kiểm tra File
	ifstream FileIn1("INPUT.txt", ios_base::in);
	if (!FileIn1)
	{
		cout << "Khong Co File Giai Ma\n";
		system("pause");
	}
	
	//XỬ LÝ CHÍNH
	
	gt2:
	Sleep(200);
	clrscr();
	int LuaChon = CHOSSEMENU("Giai Ma", "Ma Hoa", " EXIT", 51);
	if (LuaChon == 0)
	{
		gt1:
		Sleep(200);
		//LOAD LẠI DATA
		ifstream FileIn("ENCRIPT.txt", ios_base::in);
		ofstream FileOut("CLEAR.txt", ios_base::out);

		//Kiểm tra File Có Tồn Tại Không
		if (!FileIn)
		{
			cout << "\nKHONG CO FILE ENCRIPT.txt\n";
			system("pause");
			return 0;
		}

		//Xử lý, Lấy giữu liệu Từ FileIn vào vector input
		vector<string> input;
		while (!FileIn.eof())
		{
			string x;
			getline(FileIn, x, ' ');
			input.push_back(x);
		}

		//Xử lý
		GiaiMa(input, bt, FileOut);
		FileIn.close();
		FileOut.close();

		
		
		clrscr();
		int Chosse = CHOSSEMENU("Open File Decode", "Open File Encode", "      BACK", 47);
		if (Chosse == 0)
		{
			system("CLEAR.txt");
			goto gt1;
		}
		else if (Chosse == 1)
		{
			system("ENCRIPT.txt");
			goto gt1;
		}
		else
		{
			goto gt2;
		}
	}
	else if (LuaChon == 1)
	{
		gt3:
		clrscr();
		Sleep(200);
		int Chosse = CHOSSEMENU("Open File Decode", "Open File Encode", "      BACK", 47);
		//MÃ HOÁ
		ifstream FileIn1("INPUT.txt", ios_base::in);
		ofstream FileOut1("OUTPUT.txt", ios_base::out);
		MaHoa(bt, FileIn1, FileOut1);
		FileIn1.close();
		FileOut1.close();
		if (Chosse == 0)
		{
			system("INPUT.txt");
			goto gt3;
		}
		else if (Chosse == 1)
		{
			system("OUTPUT.txt");
			goto gt3;
		}
		else
		{
			goto gt2;
		}
	}
	else
	{
		clrscr();
		gotoxy(48, 13);
		cout << "GOODBYE...";
		Sleep(2000);
		return 0;
	}

	

	
	system("pause");
	return 0;
}