// Mlitapraktike13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct VirusCoord
{
	int x, y;
};


int main()
{
	size_t sizeofMatrix;
	size_t countOfVirus;
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	inFile >> sizeofMatrix;
	inFile >> countOfVirus;
	vector<vector<char>> field(sizeofMatrix, vector<char>(sizeofMatrix, '0'));
	vector<VirusCoord> arrayOfVirus(countOfVirus);

	int x, y;
	for (size_t i = 0; i < countOfVirus; i++)
	{
		inFile >> x >> y;
		arrayOfVirus[i].x = x - 1;
		arrayOfVirus[i].y = y - 1;
	}

	queue<VirusCoord> viruses;

	for (size_t i = 0; i < countOfVirus; i++)
		viruses.push(arrayOfVirus[i]);
	int count = 0;
	bool end = false;
	int sizeOfVirus;
	VirusCoord top;
	VirusCoord pushCoord;



	while (!end)
	{
		sizeOfVirus = viruses.size();
		count++;
		for (size_t i = 0; i < sizeOfVirus; i++)
		{
			top = viruses.front();
			field[top.x][top.y] = '#';
			if (top.x != 0)
			{
				if (field[top.x - 1][top.y] != '#')
				{
					field[top.x - 1][top.y] = '#';
					pushCoord.x = top.x - 1;
					pushCoord.y = top.y;
					viruses.push(pushCoord);
				}
			}

			if (top.x != sizeofMatrix-1)
			{
				if (field[top.x + 1][top.y] != '#')
				{
					field[top.x + 1][top.y] = '#';
					pushCoord.x = top.x + 1;
					pushCoord.y = top.y;
					viruses.push(pushCoord);
				}
			}

			if (top.y != 0)
			{
				if (field[top.x][top.y - 1] != '#')
				{
					field[top.x][top.y - 1] = '#';
					pushCoord.x = top.x;
					pushCoord.y = top.y - 1;
					viruses.push(pushCoord);
				}
			}

			if (top.y != sizeofMatrix - 1)
			{
				if (field[top.x][top.y + 1] != '#')
				{
					field[top.x][top.y + 1] = '#';
					pushCoord.x = top.x;
					pushCoord.y = top.y + 1;
					viruses.push(pushCoord);
				}
			}

			viruses.pop();
		}

		end = true;
		for (size_t i = 0; i < sizeofMatrix; i++)
			for (size_t j = 0; j < sizeofMatrix; j++)
				if (field[i][j] != '#')
					end = false;


	}

	cout << count << endl;
	system("pause");
    return 0;
}

