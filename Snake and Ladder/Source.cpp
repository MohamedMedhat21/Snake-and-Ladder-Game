#include <iostream>
#include<Windows.h>
#include<iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
bool isfound = false, isbonus = false;
bool found = false;
int numofplayers;
int indexofarray = 0;
int score;
int numofrounds = 0;
int playerpostion[10];
string playernumber[10];
char alphabet = 'A';
int arr[10][10];
string winner;
pair <int, int > p[100];
int indexofpair = 0; 
int last;
int position = 0;
map <string, bool>bonus;
map <string, long long >scoreinfo;
struct namess
{
	string playernames;
}namearray[100];
void intro()
{
	cout << setw(110);
	cout << "Welcome to our Game...!!" << endl << endl;
	Sleep(1000); cout << setw(110);
	cout << "Press Any Key To Start" << endl;
	_getch();
}
void playersinfo()
{
	cout << "Enter the number of players" << ':' << " ";
	cin >> numofplayers;
	for (int i = 0; i < numofplayers; ++i) {
		cout << "Enter the name of the player" << i + 1 << " ";
		cin >> namearray[i].playernames;
		scoreinfo[namearray[i].playernames] += 0;
	}
	system("cls");
}
int dicenumber()
{
	int score;
	srand(time(NULL));
	score = 1 + (rand() % 6);    
	return score;
}
void game(namess namearray[])
{
	if (indexofarray == numofplayers)
	{
		indexofarray = 0;
	}
	cout << namearray[indexofarray].playernames << " " << "your turn :) " << endl;
	cout << "let's roll the dice to see your result ;)..so please enter key  " << endl;
	_getch();
	if (_getch())
	{
		_getch;
	}
	score = dicenumber();
	cout << "You Get " << score << endl;
	Sleep(400); 
	if (scoreinfo[namearray[indexofarray].playernames] + score > 100)
	{
		scoreinfo[namearray[indexofarray].playernames] += 0;
	}
	else
	{
		scoreinfo[namearray[indexofarray].playernames] += score;
	}
	for (int i = 0; i < numofplayers; ++i)
	{
		playerpostion[i] = scoreinfo[namearray[i].playernames];
	}
	position = scoreinfo[namearray[indexofarray].playernames];
	if (scoreinfo[namearray[indexofarray].playernames] == 85 || scoreinfo[namearray[indexofarray].playernames] == 48 || scoreinfo[namearray[indexofarray].playernames] == 29 || scoreinfo[namearray[indexofarray].playernames] == 11)
	{
		isbonus = true;
		bonus[namearray[indexofarray].playernames] = true;
	}
	Sleep(700);
	for (int i = 0; i < 10; ++i)
	{
		if (scoreinfo[namearray[indexofarray].playernames] == p[i].first && i >= 5) 
		{
			Sleep(600);
			found = true;
			if (bonus[namearray[indexofarray].playernames] == true)
			{
				bonus[namearray[indexofarray].playernames] = false;
				continue;
			}
			else
			{
				scoreinfo[namearray[indexofarray].playernames] = p[i].second;
			}
		}
		if (scoreinfo[namearray[indexofarray].playernames] == p[i].first && i < 5) 
		{
			Sleep(600);
			isfound = true;
			scoreinfo[namearray[indexofarray].playernames] = p[i].second;
		}
	}
	indexofarray++; 
}
void grid(int gridsize, int ceilsize) {
	system("cls");
	int row = 0, column = 0;
	int total = gridsize * ceilsize;
	string c;
	for (int i = 0; i <= total; ++i) {
		for (int j = 0; j <= total; ++j) {
			if (i%ceilsize == 0 || j % ceilsize == 0)
			{ 
				c = '*';
			}
			else if (j % 2 == 0 && i % 2 == 0) 
			{   
				if (column % 10 == 0 && column != 0) 
				{ 
					row++;
					column = 0;
				}
				c = ::to_string(arr[row][column]);  
				if (arr[row][column] == 7 || arr[row][column] == 45)
				{
					c = "L1";
				}if (arr[row][column] == 14 || arr[row][column] == 55)
				{
					c = "L2";
				}if (arr[row][column] == 12 || arr[row][column] == 50)
				{
					c = "L3";
				}if (arr[row][column] == 54 || arr[row][column] == 91)
				{
					c = "L4";
				}if (arr[row][column] == 41 || arr[row][column] == 79)
				{
					c = "L5";
				}
				if (arr[row][column] == 37 || arr[row][column] == 3)
				{
					c = "S1";
				}if (arr[row][column] == 47 || arr[row][column] == 16)
				{
					c = "S2";
				}if (arr[row][column] == 28 || arr[row][column] == 10)
				{
					c = "S3";
				}if (arr[row][column] == 75 || arr[row][column] == 32)
				{
					c = "S4";
				}if (arr[row][column] == 94 || arr[row][column] == 71)
				{
					c = "S5";
				}
				for (int i = 0; i < numofplayers; ++i) 
				{
					if (arr[row][column] == playerpostion[i])
					{
						c = playernumber[i];
					}
				}
				column++;                             
			}
			else {
				c = ' ';              
			}
			if (i == 2 && j == 3)
			{    
				cout << c;
			}
			else if (j != 0 && c.length() == 1)
			{   
				cout << c << " ";
			}
			else if (j != 0 && c.length() > 1) 
			{   
				cout << c;
			}
			else
			{
				cout << c;    
			}
		}
		cout << endl;

	}
}
void displayladders()
{
	COORD cord;
	cord.X = 150;
	cord.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "Ladders: " << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << 7 << '-' << 45 << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << 14 << '-' << 55 << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << 12 << '-' << 50 << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << 54 << '-' << 91 << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << 41 << '-' << 79 << endl;
	indexofpair = 0;
	p[indexofpair] = make_pair(7, 45);
	indexofpair++;
	p[indexofpair] = make_pair(14, 55);
	indexofpair++;
	p[indexofpair] = make_pair(12, 50);
	indexofpair++;
	p[indexofpair] = make_pair(54, 91);
	indexofpair++;
	p[indexofpair] = make_pair(41, 79);
	indexofpair++;
}
void displaysnakes()
{
	COORD cord;
	cord.X = 150;
	cord.Y = 12;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "snakes: " << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "37 -  3" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "47 -  16" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "28 -  10" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "75 -  32" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "94 -  71" << endl;
	indexofpair = 5;
	p[indexofpair] = make_pair(37, 3);
	indexofpair++;
	p[indexofpair] = make_pair(47, 16);
	indexofpair++;
	p[indexofpair] = make_pair(28, 10);
	indexofpair++;
	p[indexofpair] = make_pair(75, 32);
	indexofpair++;
	p[indexofpair] = make_pair(94, 71);

}
void displaybonus()
{
	COORD cord;
	cord.X = 150;
	cord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "Bonus: " << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "B1 " << "11" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "B2 " << "29" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "B3 " << "48" << endl;
	cord.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << "B4 " << "85" << endl;
}
void reposition()
{
	COORD cord, re;
	re.X = 0;
	re.Y = 41;
	cord.X = 150;
	cord.Y = 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), re);
}
void scoreboard()
{
	if (numofrounds > 0)
	{ 	grid(10, 4); 
		displayladders();
		displaysnakes();
		displaybonus();
		reposition();
	}
	vector <pair <long long, string>> order;
	for (map <string, long long>::iterator it = scoreinfo.begin(); it != scoreinfo.end(); it++)
	{
		string first = it->first;
		long long second = it->second;
		order.emplace_back(second, first);   
	}
	sort(order.begin(), order.end());    
	last = order[order.size() - 1].first;    
	winner = order[order.size() - 1].second;
	cout << "******** Scoreboard ******** " << endl;
	for (int i = order.size() - 1; i >= 0; i--)
	{
		if (isfound == true)
		{
			cout << namearray[indexofarray - 1].playernames << " " << "hahaha!! you got a ladder ;)" << endl;
			isfound = false;
		}
		else if (found == true)
		{
			cout << namearray[indexofarray - 1].playernames << " " << "opss!! you got a snake :(" << endl;
			found = false;
		}
		cout << order[i].second << ':' << " " << order[i].first << endl; 
	}
	cout << "***************************" << endl;
	Sleep(700);
	numofrounds++;
}
int main()
{
	int k, q, w;   
	k = 100;
	q = 100;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i % 2 == 0)
			{
				arr[i][j] = k;
				k--;    
			}
			else {
				arr[i][j] = k;
				k++;    
			}
		}
		if (i % 2 == 0) {
			w = (k - 9);
			k = w;
		}
		else {
			w = (k - 11);
			k = w;
		}
	}




	int button;
	bool done = true;
	system("COLOR 2");
	Sleep(500);
	intro();
	cout << "Loading"; Sleep(1000); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << "." << endl;
	string a = "(1) New Game", b = "(2) Instructions", c = "(3) About";
	cout << setw(110);
	cout << a << endl << endl << setw(110) << b << endl << endl << setw(110) << c << endl << endl;
	Sleep(700);
	cout << "-------------------------------------------" << endl;
	cout << "For New Game Press 1" << endl << "For Instructions Press 2" << endl << "For About Press 3" << endl;
	cin >> button;
	if (button != 1 && button != 2 && button != 3)
	{
		cout << "ERROR" << endl;
		cout << "Please enter a valid number" << endl;
		cout << "Please restart the game" << endl;
	}
	else
	{
		if (button == 1)
		{
			system("cls");
			playersinfo();
			for (int i = 0; i < numofplayers; i++)
			{
				playernumber[i] = alphabet;
				alphabet++;
			}


			Sleep(500);
			cout << "Let's Play !!!" << endl;
			cout << "Loading"; Sleep(1000); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << "."; Sleep(700); cout << "." << endl;
			system("cls");
			grid(10, 4);//adeto size el gride kolooo kam 3mod y3ny we 4 de 7gm elceil elw7da mkna mn 4 ngom  
			Sleep(600);
			displayladders();
			Sleep(600);
			displaysnakes();
			Sleep(600);
			displaybonus();
			Sleep(600);
			reposition();
			Sleep(600);
			game(namearray);
			Sleep(600);
			scoreboard();
			Sleep(700);
			auto s = chrono::system_clock::now();
			while (last < 100)
			{
				if (done == true)
				{
					system("cls");
					done = false;
				}
				game(namearray);
				scoreboard();
			}
			auto e = chrono::system_clock::now();
			double t = double(chrono::duration_cast<chrono::nanoseconds>(e - s).count());
			Sleep(700);
			cout << winner << "  You Win ! " << endl;
			Sleep(700);
			cout << "time elapsed in the game per minutes " << (t / 1e9) / 60 << endl;
			Sleep(700);
		}
		else if (button == 2)
		{
			system("cls");
			cout << "Snakes and Ladders is a board game played between two or more players on a gameboard having numbered, gridded squares." << endl << " A number of ladders and snakes are on the board, each connecting two specific board squares." << endl << "The object of the game is to navigate one's game piece, according to die rolls, " << endl << "from the start (bottom square) to the finish (top square), helped or hindered by ladders and snakes respectively. " << endl;
			
		}
		else if (button == 3)
		{
			system("cls");
			cout << "This Game is implemented by FCIS-ASU Students"<<endl;

			cout << "The Students are :" << endl<<endl;
			cout << "Maria Emad" << endl;
			cout << "Mohamed Badawy" << endl;
			cout << "Mohamed Medhat" << endl;
			cout << "Mohamed Mostafa" << endl;
			cout << "Nada Elsayed" << endl;
			cout << "Nada Youssef" << endl;
			cout << endl;
			cout << "Under the Supervision of :" << endl;
			cout << "Dr.Yasmine Afify and SP(Structured Programming) Staff" << endl;
			cout << endl;
			cout << "Why Snakophobia ? !" << endl;
			cout << "..For our First Project is the Snake and Ladder Game ..And there is always Phobia accompanied by First Projects" << endl;
			cout << "..Here came the Name ..And launching that Snake and Ladder Project means that we overcame this Phobia!" << endl;
			cout << endl;
			cout<<"Hope you Enjoy it!" << endl;
		}
	}
	system("pause");
}