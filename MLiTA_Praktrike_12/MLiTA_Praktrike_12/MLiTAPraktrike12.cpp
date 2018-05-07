// MLiTAPraktrike12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int SIZE = 100000;

int main()
{
	ifstream inFile("input.txt");
	int countPos;
	int coordX, coordY;
	inFile >> countPos;
	int winPosX = 1;
	int winPosY = 1;

	for (size_t i = 0; i < countPos; i++)
	{
		inFile >> coordX >> coordY;
		coordX -= winPosX;
		coordY -= winPosY;

		if ((coordX % 2 == 0) && (coordY % 2 == 0))
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}

	system("pause");
    return 0;
}

