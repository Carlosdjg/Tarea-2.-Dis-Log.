#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <wchar.h>
#include <locale.h>
#include <bits/stdc++.h>
#include "miniwin.h"

using namespace std;
using namespace miniwin;

int nrzi(char hex[12]){

    vredimensiona(830, 500);
    linea(100,200,750,200);
    linea(100,350,100,50);
    linea(90,55,100,50);
    linea(110,55,100,50);
    linea(90,345,100,350);
    linea(100,350,110,345);
    linea(745,210,750,200);
    linea(745,190,750,200);

    color(MAGENTA);
    texto(760,193,"Tiempo");
    color(MAGENTA);
    texto(75,135,"Alto");
    color(MAGENTA);
    texto(70,245,"Bajo");

    int estado=1;
    int i=0;

    while(i<=11){

            switch(estado){

            case 1:

                switch(hex[i]){

                case '1':

                    color(MAGENTA);
                    texto((100+50*i+100+50*(i+1))/2,125,"1");
                    color(AZUL);
                    linea(100+i*50,150,100+i*50,250);
                    color(AZUL);
                    linea(100+i*50,250,100+(i+1)*50,250);

                    estado=0;

                    i++;
                    break;

                case '0':

                    color(MAGENTA);
                    texto((100+50*i+100+50*(i+1))/2,125,"0");
                    color(AZUL);
                    linea(100+i*50,150,100+(i+1)*50,150);

                    estado=1;

                    i++;
                    break;

                }

                break;

            case 0:

                switch(hex[i]){

                case '1':

                    color(MAGENTA);
                    texto((100+50*i+100+50*(i+1))/2,125,"1");
                    color(AZUL);
                    linea(100+i*50,250,100+i*50,150);
                    color(AZUL);
                    linea(100+i*50,150,100+(i+1)*50,150);

                    estado=1;

                    i++;
                    break;


                case '0':

                    color(MAGENTA);
                    texto((100+50*i+100+50*(i+1))/2,125,"0");
                    color(AZUL);
                    linea(100+i*50,250,100+(i+1)*50,250);

                    estado=0;

                    i++;
                    break;

                }

                break;


            }

    }

    refresca();

    return 0;

}

int verifica(char cadena[100]) {

	int i = 0;
	int ver = 0;

	while (i<=(strlen(cadena)-1)) {

		if (cadena[i]=='0' or cadena[i] == '1' or cadena[i] == '2' or cadena[i] == '3' or cadena[i] == '4' or cadena[i] == '5' or cadena[i] == '6' or cadena[i] == '7' or cadena[i] == '8' or cadena[i] == '9' or cadena[i] == 'A' or cadena[i] == 'B' or cadena[i] == 'C' or cadena[i] == 'D' or cadena[i] == 'E' or cadena[i] == 'F') {
			ver = 0;
			i++;
		}

		else {
			ver = 1;
			break;
		}

	}

	return ver;

}
char entrada[4];
//string ListaBinario2[100];
void Hamming(int posicion, string Lista[], int length, string Lista0[], string Lista1[], string Lista3[], string Lista7[], string Lista15[], bool paridad) {


	int suma = 0;
	if (posicion == 0) { //revisa 1 salta 1
		while (posicion < length) {
			Lista0[posicion] = Lista[posicion];
			int m = stoi(Lista[posicion]);
			suma = suma + m; //Cantidad de 1s
			posicion = posicion + 2;
		}
		if (paridad) {


			if (suma % 2 == 0) {
				Lista0[0] = Lista[0] = "1"; //Paridad
			}
			else {
				Lista0[0] = Lista[0] = "0";
			}
		}
		if (paridad == 0) {
			if (suma % 2 == 0) {
				Lista0[0] = Lista[0] = "0"; //Paridad
			}
			else {
				Lista0[0] = Lista[0] = "1";
			}
		}
	}
	if (posicion == 1) {
		while (posicion < length) { //revisa 2 salta 2
			int j = 0;
			while (j < 2 && posicion < length) {
				Lista1[posicion] = Lista[posicion];
				int m = stoi(Lista[posicion]);
				suma = suma + m;
				j++;
				posicion++;
			}
			posicion = posicion + 2;
		}
		if (paridad) {


			if (suma % 2 == 0) {
				Lista1[1] = Lista[1] = "1"; //Paridad
			}
			else {
				Lista1[1] = Lista[1] = "0";
			}
		}
		if (paridad == 0) {
			if (suma % 2 == 0) {
				Lista1[1] = Lista[1] = "0"; //Paridad
			}
			else {
				Lista1[1] = Lista[1] = "1";
			}
		}
	}
	if (posicion == 3) {
		while (posicion < length) { //revisa 4 salta 4
			int j = 0;
			while (j < 4 && posicion < length) {
				Lista3[posicion] = Lista[posicion];
				int m = stoi(Lista[posicion]);
				suma = suma + m;
				j++;
				posicion++;
			}
			posicion = posicion + 4;
		}
		if (paridad) {


			if (suma % 2 == 0) {
				Lista3[3] = Lista[3] = "1"; //Paridad
			}
			else {
				Lista3[3] = Lista[3] = "0";
			}
		}
		if (paridad == 0) {
			if (suma % 2 == 0) {
				Lista3[3] = Lista[3] = "0"; //Paridad
			}
			else {
				Lista3[3] = Lista[3] = "1";
			}
		}
	}
	if (posicion == 7) { //revisa 8 salta 8
		while (posicion < length) {
			int j = 0;
			while (j < 8 && posicion < length) {
				Lista7[posicion] = Lista[posicion];
				int m = stoi(Lista[posicion]);
				suma = suma + m;
				j++;
				posicion++;
			}
			posicion = posicion + 8;
		}
		if (paridad) {


			if (suma % 2 == 0) {
				Lista7[7] = Lista[7] = "1"; //Paridad
			}
			else {
				Lista7[7] = Lista[7] = "0";
			}
		}
		if (paridad == 0) {
			if (suma % 2 == 0) {
				Lista7[7] = Lista[7] = "0"; //Paridad
			}
			else {
				Lista7[7] = Lista[7] = "1";
			}
		}
	}
	if (posicion == 15) { //revisa 16 salta 16
		while (posicion < length) {
			int j = 0;
			while (j < 16 && posicion < length) {
				Lista15[posicion] = Lista[posicion];
				int m = stoi(Lista[posicion]);
				suma = suma + m;
				j++;
				posicion++;
			}
			posicion = posicion + 16;
		}
		if (paridad) {
			if (suma == 1) {
				Lista15[15] = Lista[15] = "0";;
			}
			else {
				Lista15[15] = Lista[15] = "1";
			}
		}
		if (paridad == 0) {
			if (suma == 1) {
				Lista15[15] = Lista[15] = "1";;
			}
			else {
				Lista15[15] = Lista[15] = "0";
			}

		}
	}
}

void printLista(string Lista[], int size) {
	int i = 0;
	while (i < size) {
		cout << Lista[i] << "   ";
		i++;
	}
	cout << endl;
}
void printLista2(string Lista[], int size) {
	int i = 0;
	while (i < size) {
		cout << Lista[i] << "  ";
		i++;
	}
	cout << endl;
}


int HexBinarioDec(int input, int posc)
{
	int a;
	int c = 0;
	int b = pow(16, posc);
	if (input == 48) {
		cout << "0000 ";
		a = 0 * b;
	}
	if (input == 49) {
		cout << "0001 ";
		a = 1 * b;
	}
	if (input == 50) {
		cout << "0010 ";
		a = 2 * b;
	}
	if (input == 51) {
		cout << "0011 ";
		a = 3 * b;
	}
	if (input == 52) {
		cout << "0100 ";
		a = 4 * b;
	}
	if (input == 53) {
		cout << "0101 ";
		a = 5 * b;
	}
	if (input == 54) {
		cout << "0110 ";
		a = 6 * b;
	}
	if (input == 55) {
		cout << "0111 ";
		a = 7 * b;
	}
	if (input == 56) {
		cout << "1000 ";
		a = 8 * b;
	}
	if (input == 57) {
		cout << "1001 ";
		a = 9 * b;
	}
	if (input == 65) {
		cout << "1010 ";
		a = 10 * b;
	}
	if (input == 66) {
		cout << "1011 ";
		a = 11 * b;
	}
	if (input == 67) {
		cout << "1100 ";
		a = 12 * b;
	}
	if (input == 68) {
		cout << "1101 ";
		a = 13 * b;
	}
	if (input == 69) {
		cout << "1110 ";
		a = 14 * b;
	}
	if (input == 70) {
		cout << "1111 ";
		a = 15 * b;
	}
	return a;
}

int Decimal(int ListDec[100], char Cadena[100]) {
	int a = 0;
	int b = 0;
	int c = 0;
	while (c < strlen(Cadena)) {
		b = ListDec[c];
		a = a + b;
		c++;
	}
	return a;
}

string Binario(int input)
{
	string valor;
	if (input == 48) {
		valor = "0000";
	}
	if (input == 49) {
		valor = "0001";
	}
	if (input == 50) {
		valor = "0010";
	}
	if (input == 51) {
		valor = "0011";
	}
	if (input == 52) {
		valor = "0100";
	}
	if (input == 53) {
		valor = "0101";
	}
	if (input == 54) {
		valor = "0110";
	}
	if (input == 55) {
		valor = "0111";
	}
	if (input == 56) {
		valor = "1000";
	}
	if (input == 57) {
		valor = "1001";
	}
	if (input == 65) {
		valor = "1010";
	}
	if (input == 66) {
		valor = "1011";
	}
	if (input == 67) {
		valor = "1100";
	}
	if (input == 68) {
		valor = "1101";
	}
	if (input == 69) {
		valor = "1110";
	}
	if (input == 70) {
		valor = "1111";
	}
	return valor;
}

void BinarioHex(string Lista[]) {
	int i = 0;
	int valor_dec=0;
	int numero = 0;
	while (i <= 12) { //binario a decimal
		if (Lista[i] == "1") {
			numero = 1;
		}
		else {
			numero = 0;
		}
		valor_dec = numero*pow(2, 11-i) + valor_dec;
		i++;
	}
	//cout << valor_dec << "\n";
	bool estado = false;
	int hex[100];
	i = 0;
	while (!estado) { //deciaml a hexadecimal
		hex[i] = valor_dec % 16;
		valor_dec = valor_dec / 16;
		//cout << "Residuo: " << hex[i] << "Cociente: " << valor_dec <<"\n";
		if (valor_dec < 16) {
			estado = true;
			hex[i+1] = valor_dec;
		}
		i++;
	}

	char buffer[1];
	buffer[0] = hex[0];
	buffer[1] = hex[2];
	hex[0] = buffer[1];
	hex[2] = buffer[0];
	i = 0;
	while (i<3)
	{ //convierte a char el hexadecimal
		//cout << hex[i] << "\n";
			switch (hex[i])
			{
				case 0:
					entrada[i] = '0';
					break;
				case 1:
					entrada[i] = '1';
					break;
				case 2:
					entrada[i] = '2';
					break;
				case 3:
					entrada[i] = '3';
					break;
				case 4:
					entrada[i] = '4';
					break;
				case 5:
					entrada[i] = '5';
					break;
				case 6:
					entrada[i] = '6';
					break;
				case 7:
					entrada[i] = '7';
					break;
				case 8:
					entrada[i] = '8';
					break;
				case 9:
					entrada[i] = '9';
					break;
				case 10:
					entrada[i] = 'A';
					break;
				case 11:
					entrada[i] = 'B';
					break;
				case 12:
					entrada[i] = 'C';
					break;
				case 13:
					entrada[i] = 'D';
					break;
				case 14:
					entrada[i] = 'E';
					break;
				case 15:
					entrada[i] = 'F';
					break;

			}
			i++;
	}


}



int hxtobin(char cadena[100]){

    char hex[12];

    switch(cadena[0]){
    case '0':
        hex[0]='0';
        hex[1]='0';
        hex[2]='0';
        hex[3]='0';
        break;

    case '1':
        hex[0]='0';
        hex[1]='0';
        hex[2]='0';
        hex[3]='1';
        break;

    case '2':
        hex[0]='0';
        hex[1]='0';
        hex[2]='1';
        hex[3]='0';
        break;

    case '3':
        hex[0]='0';
        hex[1]='0';
        hex[2]='1';
        hex[3]='1';
        break;

    case '4':
        hex[0]='0';
        hex[1]='1';
        hex[2]='0';
        hex[3]='0';
        break;
    case '5':
        hex[0]='0';
        hex[1]='1';
        hex[2]='0';
        hex[3]='1';
        break;
    case '6':
        hex[0]='0';
        hex[1]='1';
        hex[2]='0';
        hex[3]='1';
        break;
    case '7':
        hex[0]='0';
        hex[1]='1';
        hex[2]='1';
        hex[3]='1';
        break;
    case '8':
        hex[0]='1';
        hex[1]='0';
        hex[2]='0';
        hex[3]='0';
        break;
    case '9':
        hex[0]='1';
        hex[1]='0';
        hex[2]='0';
        hex[3]='1';
        break;
    case 'A':
        hex[0]='1';
        hex[1]='0';
        hex[2]='1';
        hex[3]='0';
        break;
    case 'B':
        hex[0]='1';
        hex[1]='0';
        hex[2]='1';
        hex[3]='1';
        break;
    case 'C':
        hex[0]='1';
        hex[1]='1';
        hex[2]='0';
        hex[3]='0';
        break;
    case 'D':
        hex[0]='1';
        hex[1]='1';
        hex[2]='0';
        hex[3]='1';
        break;
    case 'E':
        hex[0]='1';
        hex[1]='1';
        hex[2]='1';
        hex[3]='0';
        break;
    case 'F':
        hex[0]='1';
        hex[1]='1';
        hex[2]='1';
        hex[3]='1';
        break;
    }

    switch(cadena[1]){
    case '0':
        hex[4]='0';
        hex[5]='0';
        hex[6]='0';
        hex[7]='0';
        break;

    case '1':
        hex[4]='0';
        hex[5]='0';
        hex[6]='0';
        hex[7]='1';
        break;

    case '2':
        hex[4]='0';
        hex[5]='0';
        hex[6]='1';
        hex[7]='0';
        break;

    case '3':
        hex[4]='0';
        hex[5]='0';
        hex[6]='1';
        hex[7]='1';
        break;

    case '4':
        hex[4]='0';
        hex[5]='1';
        hex[6]='0';
        hex[7]='0';
        break;
    case '5':
        hex[4]='0';
        hex[5]='1';
        hex[6]='0';
        hex[7]='1';
        break;
    case '6':
        hex[4]='0';
        hex[5]='1';
        hex[6]='0';
        hex[7]='1';
        break;
    case '7':
        hex[4]='0';
        hex[5]='1';
        hex[6]='1';
        hex[7]='1';
        break;
    case '8':
        hex[4]='1';
        hex[5]='0';
        hex[6]='0';
        hex[7]='0';
        break;
    case '9':
        hex[4]='1';
        hex[5]='0';
        hex[6]='0';
        hex[7]='1';
        break;
    case 'A':
        hex[4]='1';
        hex[5]='0';
        hex[6]='1';
        hex[7]='0';
        break;
    case 'B':
        hex[4]='1';
        hex[5]='0';
        hex[6]='1';
        hex[7]='1';
        break;
    case 'C':
        hex[4]='1';
        hex[5]='1';
        hex[6]='0';
        hex[7]='0';
        break;
    case 'D':
        hex[4]='1';
        hex[5]='1';
        hex[6]='0';
        hex[7]='1';
        break;
    case 'E':
        hex[4]='1';
        hex[5]='1';
        hex[6]='1';
        hex[7]='0';
        break;
    case 'F':
        hex[4]='1';
        hex[5]='1';
        hex[6]='1';
        hex[7]='1';
        break;
    }

    switch(cadena[2]){
    case '0':
        hex[8]='0';
        hex[9]='0';
        hex[10]='0';
        hex[11]='0';
        break;

    case '1':
        hex[8]='0';
        hex[9]='0';
        hex[10]='0';
        hex[11]='1';
        break;

    case '2':
        hex[8]='0';
        hex[9]='0';
        hex[10]='1';
        hex[11]='0';
        break;

    case '3':
        hex[8]='0';
        hex[9]='0';
        hex[10]='1';
        hex[11]='1';
        break;

    case '4':
        hex[8]='0';
        hex[9]='1';
        hex[10]='0';
        hex[11]='0';
        break;
    case '5':
        hex[8]='0';
        hex[9]='1';
        hex[10]='0';
        hex[11]='1';
        break;
    case '6':
        hex[8]='0';
        hex[9]='1';
        hex[10]='0';
        hex[11]='1';
        break;
    case '7':
        hex[8]='0';
        hex[9]='1';
        hex[10]='1';
        hex[11]='1';
        break;
    case '8':
        hex[8]='1';
        hex[9]='0';
        hex[10]='0';
        hex[11]='0';
        break;
    case '9':
        hex[8]='1';
        hex[9]='0';
        hex[10]='0';
        hex[11]='1';
        break;
    case 'A':
        hex[8]='1';
        hex[9]='0';
        hex[10]='1';
        hex[11]='0';
        break;
    case 'B':
        hex[8]='1';
        hex[9]='0';
        hex[10]='1';
        hex[11]='1';
        break;
    case 'C':
        hex[8]='1';
        hex[9]='1';
        hex[10]='0';
        hex[11]='0';
        break;
    case 'D':
        hex[8]='1';
        hex[9]='1';
        hex[10]='0';
        hex[11]='1';
        break;
    case 'E':
        hex[8]='1';
        hex[9]='1';
        hex[10]='1';
        hex[11]='0';
        break;
    case 'F':
        hex[8]='1';
        hex[9]='1';
        hex[10]='1';
        hex[11]='1';
        break;
    }

    nrzi(hex);

    return 0;

}

int main()
{

	setlocale(LC_ALL, "");

	cout << "Ingrese el número de tres dígitos en base hexadecimal: ";
	char cadena[100];
	cin >> cadena;

	if (strlen(cadena)==3) {

		int ver=verifica(cadena);

		if (ver==0) {
			int Lista[100];
			int ListaDecimal[100];
			string ListaBinario[100];
			int j = 0;
			int i = 0;
			int k = 0;
			int m = strlen(cadena) - 1;
			while (i < strlen(cadena)) {
				Lista[i] = cadena[i];
				i++;
			}
			cout << "\nEl número " << cadena << " en base hexadecimal equivale a: " << endl;
			while (j < strlen(cadena)) {
				ListaDecimal[j] = HexBinarioDec(Lista[j], m - k);
				ListaBinario[j] = Binario(Lista[j]);
				j++;
				k = k + 1;
			}
			cout << "en base binaria.\n" << endl;

			int decimal = Decimal(ListaDecimal, cadena);
			cout << "\nEl número " << cadena << " en base hexadecimal equivale a " << decimal << " en base decimal.\n" << endl;
			hxtobin(cadena);

			string LISTADEC[100];

			int s = 0;
			int z = 0;
			string v;
			string x;
			int size = 0;
			while (s < strlen(cadena)) {
				int f = 0;
				v = ListaBinario[s];
				while (f < 4) {
					x = v[f];
					LISTADEC[z] = x;
					z++;
					f++;
					size++;
				}
				s++;
			}
			//Construccion de la Lista de Hamming
	string ListaHam[100];
	int b = 0;
	while (b < 17) {
		ListaHam[b] = "A";
		b++;
	}
	//Remplazar los valores potencia de 2 con 0s
	b = 0;
	while (b < 17) {
		int x = pow(2, b);
		if (x < 17) {
			ListaHam[(x - 1)] = "0";
			b++;
		}
		else {
			b++;
		}
	}
	//Remplazar los valores A con los datos binarios
	b = 0;
	k = 0;
	while (b < 17) {
		if (ListaHam[b] == "A") {
			ListaHam[b] = LISTADEC[k];
			k++;
			b++;
		}
		else {
			b++;
		}
	}
	cout << endl;
	//Creacion de Lista vacias
	string Lista0[100];
	string Lista1[100];
	string Lista3[100];
	string Lista7[100];
	string Lista15[100];
	string ListaBIN[100];

	bool paridad; //un 1 para par, un 0 para impar
	cout << "Digite 1 para paridad Par / 0 para paridad Impar: ";
	cin >> paridad;
	cout << "\n";

	i = 0;
	while (i < 17) {
		ListaBIN[i] = Lista1[i] = Lista3[i] = Lista7[i] = Lista15[i] = Lista0[i] = " ";
		i++;
	}
	b = 0;
	k = 0;
	while (b < 17) {
		if (b == 0 || b == 1 || b == 3 || b == 7 || b == 15) {
			b++;
		}
		else {
			ListaBIN[b] = LISTADEC[k];
			k++;
			b++;
		}
	}
	b = 0;
	while (b < 17) {
		Hamming(b, ListaHam, 17, Lista0, Lista1, Lista3, Lista7, Lista15, paridad);
		b++;
	}
	b = 0;
	//Generar Tabla 1 para numero binario original
	string Encabezado[100] = { "p1","p2","d1","p3","d2","d3","d4","p4","d5","d6","d7","d8  d9 d10 d11  p5 d12" };
	cout << endl;
	cout << "                               |";
	printLista2(Encabezado, 17);
	cout << "Palabra de datos (sin paridad) | ";
	printLista(ListaBIN, 17);
	cout << "             p1                | ";
	printLista(Lista0, 17);
	cout << "             p2                | ";
	printLista(Lista1, 17);
	cout << "             p3                | ";
	printLista(Lista3, 17);
	cout << "             p4                | ";
	printLista(Lista7, 17);
	cout << "             p5                | ";
	printLista(Lista15, 17);
	cout << "Palabra de datos (con paridad) | ";
	printLista(ListaHam, 17);
	cout << endl;


	int posCambiar = 0;
	cout << "Indique la posicion del bit que desea cambiar: ";
	cin >> posCambiar;
	cout << "Binario original: " << "\n";
	printLista(LISTADEC, 14);


	if (LISTADEC[posCambiar] == "0") {
		LISTADEC[posCambiar] = "1";
	}
	else {
		LISTADEC[posCambiar] = "0";;
	}
	cout << "Binario cambiado: " << "\n";
	printLista(LISTADEC, 14);
	string p1, p2, p3, p4, p5;
	p1 = Lista0[0];
	p2 = Lista1[1];
	p3 = Lista3[3];
	p4 = Lista7[7];
	p5 = Lista15[15];





	//------------------------------TABLA 2---------------------------------------------------------------------------------------------------------
	string LISTADEC_2[100];
	BinarioHex(LISTADEC); //actualiza char de entrada
	j = 0;
	i = 0;
	k = 0;
	z = 0;
	m = strlen(entrada) - 1;
	while (i < strlen(entrada)) {
		Lista[i] = entrada[i];
		i++;
	}
	cout << "\n" << "Binario con bit " << posCambiar << " cambiado" << "\n";
	while (j < strlen(entrada)) {
		ListaDecimal[j] = HexBinarioDec(Lista[j], m - k);
		ListaBinario[j] = Binario(Lista[j]);
		j++;
		k = k + 1;
		z = z + 4;
	}
	cout << "\n" << "Numero decimal producido a partir del bit cambiado" << "\n";
	int decimal2 = Decimal(ListaDecimal, entrada);
	cout << decimal2 << "\n";




	s = 0;
	z = 0;
	size = 0;
	while (s < strlen(entrada)) {
		int f = 0;
		v = ListaBinario[s];
		while (f < 4) {
			x = v[f];
			LISTADEC_2[z] = x;
			z++;
			f++;
			size++;
		}
		s++;
	}
	//Construccion de la Lista de Hamming
	ListaHam[100];
	b = 0;
	while (b < 17) {
		ListaHam[b] = "A";
		b++;
	}
	//Remplazar los valores potencia de 2 con 0s
	b = 0;
	while (b < 17) {
		int x = pow(2, b);
		if (x < 17) {
			ListaHam[(x - 1)] = "0";
			b++;
		}
		else {
			b++;
		}
	}
	//Remplazar los valores A con los datos binarios
	b = 0;
	k = 0;
	while (b < 17) {
		if (ListaHam[b] == "A") {
			ListaHam[b] = LISTADEC_2[k];
			k++;
			b++;
		}
		else {
			b++;
		}
	}
	cout << endl;
	//Creacion de Lista vacias
	Lista0[100];
	Lista1[100];
	Lista3[100];
	Lista7[100];
	Lista15[100];
	ListaBIN[100];


	i = 0;
	while (i < 21) {
		ListaBIN[i] = Lista1[i] = Lista3[i] = Lista7[i] = Lista15[i] = Lista0[i] = " ";
		i++;
	}
	b = 0;
	k = 0;
	while (b < 21) {
		if (b == 0 || b == 1 || b == 3 || b == 7 || b == 15) {
			b++;
		}
		else {
			ListaBIN[b] = LISTADEC_2[k];
			k++;
			b++;
		}
	}
	b = 0;
	while (b < 17) {
		Hamming(b, ListaHam, 17, Lista0, Lista1, Lista3, Lista7, Lista15, paridad);
		b++;
	}
	b = 0;
	//Columnas de calculo de paridad y paridad almacenada
	Lista0[18] = Lista0[0];
	Lista1[18] = Lista1[1];
	Lista3[18] = Lista3[3];
	Lista7[18] = Lista7[7];
	Lista15[18] = Lista15[15];

	if (p1 == Lista0[18]) {
		Lista0[18] = "Correcto   ";
		Lista0[20] = "0";
	}
	else {
		Lista0[18] = "Error      ";
		Lista0[20] = "1";
	}
	if (p2 == Lista1[18]) {
		Lista1[18] = "Correcto   ";
		Lista1[20] = "0";
	}
	else {
		Lista1[18] = "Error      ";
		Lista1[20] = "1";
	}
	if (p3 == Lista3[18]) {
		Lista3[18] = "Correcto   ";
		Lista3[20] = "0";
	}
	else {
		Lista3[18] = "Error      ";
		Lista3[20] = "1";
	}
	if (p4 == Lista7[18]) {
		Lista7[18] = "Correcto   ";
		Lista7[20] = "0";
	}
	else {
		Lista7[18] = "Error      ";
		Lista7[20] = "1";
	}
	if (p5 == Lista15[18]) {
		Lista15[18] = "Correcto   ";
		Lista15[20] = "0";
	}
	else {
		Lista15[18] = "Error     ";
		Lista15[20] = "  1";
	}
	if (paridad == true) {
		ListaBIN[20] = "1    ";
	}
	else {
		ListaBIN[20] = "0    ";
	}

	//Generar Tabla 2
	string Encabezado2[100] = { "p1","p2","d1","p3","d2","d3","d4","p4","d5","d6","d7","d8  d9 d10 d11  p5 d12","Prueba paridad","Bit de paridad" };
	cout << endl;
	cout << "                               |";
	printLista2(Encabezado2, 20);

	cout << "Palabra de datos recibida      | ";
	printLista(ListaBIN, 21);

	cout << "             p1                | ";
	printLista(Lista0, 21);

	cout << "             p2                | ";
	printLista(Lista1, 21);

	cout << "             p3                | ";
	printLista(Lista3, 21);

	cout << "             p4                | ";
	printLista(Lista7, 21);

	cout << "             p5                | ";
	printLista(Lista15, 21);

	cout << endl;
		}

		else{
			cout << "\nEl número no está en base hexadecimal.\n" << endl; cin.ignore(); main();
		}

	}

	else {
		cout << "\nEl número debe ser de tres dígitos.\n" << endl;
		cin.ignore(); main();
	}
	int elegir;
	cout << "Desea ingresar otro dato? 1 si /0 no : ";
	cin >> elegir;
	if (elegir == 1) { main();

	} else{
	    system("pause");
	}

	system("pause");
	return 0;
}
