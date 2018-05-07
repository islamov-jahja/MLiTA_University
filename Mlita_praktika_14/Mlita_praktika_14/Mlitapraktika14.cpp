// Mlitapraktika14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Rsq(int start, int end, vector<int> fenvik);
void Update(int k, int d, vector<int>& fenvik);
int main()
{
	ifstream inFile("input.txt");
	size_t countOfSymbols = 0;
	inFile >> countOfSymbols;
	vector<int> arrayS(countOfSymbols);

	for (size_t i = 0; i < countOfSymbols; i++)
		inFile >> arrayS[i];

	vector<int> fenvik(countOfSymbols);

	for (size_t i = 0; i < countOfSymbols; i++)
		for (int j = i & (i + 1); j <= i; j++)
			fenvik[i] += arrayS[j];

	string action;

	int start, end;
	int k, d;
	while (action != "3")
	{
		cout << "choose action: " << endl;
		cout << "1: Rsq(start, end)" << endl;
		cout << "2: Update(index, value)" << endl;
		cout << "3: exit" << endl;

		cin >> action;
		if (action == "3")
			return 0;
		else if (action == "1")
		{
			cout << "enter values of start and end from space" << endl;
			cin >> start >> end;
			Rsq(start, end, fenvik);
		}
		else if (action == "2")
		{
			cout << "enter values k , d from space" << endl;
			cin >> k >> d;
			Update(k, d, fenvik);
		}
	}

    return 0;
}

void Rsq(int start, int end, vector<int> fenvik)
{
	int result1 = 0, result2 = 0;
	start--;

	while (end >= 0)
	{
		result1 += fenvik[end];
		end = (end & (end + 1)) - 1;
	}

	while (start >= 0)
	{
		result2 += fenvik[start];
	    start = (start & (start + 1)) - 1;
	}

	cout << result1 - result2 << endl;
}

void Update(int k, int d, vector<int>& fenvik)
{
	while (k < fenvik.size())
	{
		fenvik[k] += d;
		k = k | (k + 1);
	}
}