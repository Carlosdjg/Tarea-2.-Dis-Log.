// pruebalineas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h> 




using namespace std;

//Funcion que asigna las coordenadas para imprimir en la posicion deseada de la consola
void gotoxy(int x, int y)
{
	HANDLE hStdout;
	COORD pos;
	pos.X = x ;
	pos.Y = y ;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return;

	SetConsoleCursorPosition(hStdout, pos);
}
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

int main()
{
	SetColor(4); 
	gotoxy(1, 1); cout << "_____";
	gotoxy(6, 5); cout << "_____";
	SetColor(2);
	gotoxy(2, 3); cout << "___________________________________________________________________________ TIME"; 
	gotoxy(1, 0); cout << "| AMPLITUDE";
	gotoxy(1, 1); cout << "|";
	gotoxy(1, 2); cout << "|"; 
	gotoxy(1, 3); cout << "|";
	gotoxy(1, 4); cout << "|";
	gotoxy(1, 5); cout << "|";
	gotoxy(1, 6); cout << "|";
	gotoxy(1, 7); cout << "|";


	SetColor(4); 
	gotoxy(12, 5); cout << "_____";
	gotoxy(18, 5); cout << "_____";
	gotoxy(24, 1); cout << "_____";
	gotoxy(30, 1); cout << "_____";
	gotoxy(36, 1); cout << "_____";
	gotoxy(36+6, 1); cout << "_____";
	gotoxy(36+6+6, 5); cout << "_____";
	gotoxy(36+6+6+6, 1); cout << "_____";
	gotoxy(36+6+6+6+6, 5); cout << "_____";
	gotoxy(36+6+6+6+6+6, 1); cout << "_____";
	
	
	cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";

	system("pause");
}


