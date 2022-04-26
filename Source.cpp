#include <iostream> 
#include <fstream>
#include <string>
#include <conio.h>
#include "windows.h"
using namespace std;

const int rows = 5;
const int columns = 5;
char field[rows][columns] = {
	{ ' ', '|', ' ', '|', ' '},
	{ '-', '-', '-', '-', '-'},
	{ ' ', '|', ' ', '|', ' '},
	{ '-', '-', '-', '-', '-'},
	{ ' ', '|', ' ', '|', ' '}
};


void save();
void load();
void player1(char field[5][5], int rows, int columns);
void player2(char field[5][5], int rows, int columns);
bool file_esists(string path); // true

int checkVictory(char field[5][5], int rows, int columns) {
	for (int i = 0; i < columns; i++)
		if (field[i] == "XXX")
			return 1;
		else if (field[i] == "000")
			return 2;

	int counterd1X = 0, counterd10 = 0;
	int counterd2X = 0, counterd20 = 0;

	bool _space = true;

	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				if (field[i][j] == 'X')
					counterd1X++;
				else
					if (field[i][j] == 'O')
						counterd10++;
			}
			else
				if (i + j == rows - 1) {
					if (field[i][j] == 'X')
						counterd2X++;
					else if (field[i][j] == 'O')
						counterd20++;
				}
			if (field[i][j] == ' ')
				_space = true;


		}
	
}

int main() {

	setlocale(LC_ALL, "Russian");

	/*SYSTEMTIME date;
	GetSystemTime(&date);
	cout << (date.wHour + 5) << ":" << date.wMinute << endl;

	ifstream in;
	in.exceptions(ios::badbit | ios::eofbit | ios::failbit);
	in.open("file.save");
	string str;
	getline(in, str);
	if (str[0] != '#')
	*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			cout << field[i][j];
		cout << endl;
	}
	

	for (int i = 0; i < 9; i++) {
		
		if (i % 2 == 0) {
			player1(field, rows, columns);
			system("pause");
		}
		else
		{
			player2(field, rows, columns);
			system("pause");
		}
		//system("pause");
	}
	



	switch (checkVictory(field, rows, columns)) {
	case 1: cout << "Победа 1 игрока"; return 0;
	case 2: cout << "Победа 2 игрока"; return 0;
	case 0: cout << "Ничья"; return 0;
	}

	return 0;
}

void player1(char field[5][5], int rows, int columns) {

	system("cls");
	int posX = 0, posY = 0;

	char move;
	int moves = 0;

	field[posX][posY] = 'X';

	bool levelComplete = false;
	while (!levelComplete) {

		cout << "Плейер 1 ходит:" << "\n";
		cout << "Введите координаты по X ( Q W E ):" << "\n";
		cout << "Введите координаты по X ( A S D ):" << "\n";
		cout << "Введите координаты по X ( Z X C ):" << "\n";
		//cin >> posY;
		move = _getch();

		system("cls");

		switch (move) {
		case 'q': case 'Q':
			posX = 0;
			posY = 0;

			moves++;
			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}

			else
				cout << "Поле занято" << endl;
			break;
		case 'w': case 'W':

			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 0;
			posY = 2;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 'e': case 'E':
			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 0;
			posY = 4;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}

			else
				cout << "Поле занято" << endl;
			break;
		case 'a': case 'A':
			posX = 2;
			posY = 0;
			moves++;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 's': case 'S':

			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 2;
			posY = 2;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 'd': case 'D':
			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 2;
			posY = 4;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 'z': case 'Z':
			posX = 4;
			posY = 0;
			moves++;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 'x': case 'X':

			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 4;
			posY = 2;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;
		case 'c': case 'C':
			if (posX == 0 && posY == 0 && moves == 0)
				field[posX][posY] = ' ';
			moves++;
			posX = 4;
			posY = 4;
			if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
				field[posX][posY] = 'X';
				levelComplete = true;

			}
			else
				cout << "Поле занято" << endl;
			break;

		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				cout << field[i][j];
			cout << endl;
		}




	}
}

void player2(char field[5][5], int rows, int columns) {
		system("cls");
		int posX = 0, posY = 0;

		char move;
		int moves = 0;

		field[posX][posY] = 'O';

		bool levelComplete = false;
		while (!levelComplete) {

			cout << "Плейер 2 ходит:" << "\n";
			cout << "Введите координаты по X ( Q W E ):" << "\n";
			cout << "Введите координаты по X ( A S D ):" << "\n";
			cout << "Введите координаты по X ( Z X C ):" << "\n";
			//cin >> posY;
			move = _getch();

			system("cls");

			switch (move) {
			case 'q': case 'Q':

				posX = 0;
				posY = 0;
				moves++;
				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'w': case 'W':

				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 0;
				posY = 2;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'e': case 'E':
				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 0;
				posY = 4;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'a': case 'A':
				posX = 2;
				posY = 0;
				moves++;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 's': case 'S':

				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 2;
				posY = 2;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'd': case 'D':
				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 2;
				posY = 4;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'z': case 'Z':
				posX = 4;
				posY = 0;
				moves++;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'x': case 'X':

				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 4;
				posY = 2;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;
			case 'c': case 'C':
				if (posX == 0 && posY == 0 && moves == 0)
					field[posX][posY] = ' ';
				moves++;
				posX = 4;
				posY = 4;
				if (field[posX][posY] != 'X' || field[posX][posY] != 'O') {
					field[posX][posY] = 'O';
					levelComplete = true;

				}
				else
					cout << "Поле занято" << endl;
				break;

			}
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++)
					cout << field[i][j];
				cout << endl;
			}



		}


	}

	
