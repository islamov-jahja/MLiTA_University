//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Rmq(int start, int end, vector<int> fenvik);
void Add1(int k, int d, vector<int>& fenvik);
void otrezokBuild(vector<int> arrayS, int v, int tl, int tr, vector<int> &otrezok);
int main()
{
	ifstream inFile("input.txt");
	size_t countOfSymbols = 0;
	inFile >> countOfSymbols;
	vector<int> arrayS(countOfSymbols);

	for (size_t i = 0; i < countOfSymbols; i++)
		inFile >> arrayS[i];

	vector<int> otrezok(4*countOfSymbols);

	string action;

	otrezokBuild(arrayS, 1, 0, countOfSymbols - 1, otrezok);

	int start, end;
	int k, d;
	while (action != "3")
	{
		cout << "choose action: " << endl;
		cout << "1: Rmq(i, j)" << endl;
		cout << "2: (i, value)" << endl;
		cout << "3: exit" << endl;

		cin >> action;
		if (action == "3")
			return 0;
		else if (action == "1")
		{
			cout << "enter values of i and j from space" << endl;
			cin >> start >> end;
			Rmq(start, end, otrezok);
		}
		else if (action == "2")
		{
			cout << "enter values k , d from space" << endl;
			cin >> k >> d;
			Add1(k, d, otrezok);
		}
	}

	return 0;
}

void Rmq(int start, int end, vector<int> otrezok)
{
	int ans = INT_MAX;
	int n = otrezok.size() / 2;
	start += n - 1, end += n - 1;
	while (start <= end)
	{
		// если l - правый сын своего родителя, 
		// учитываем его фундаментальный отрезок
		if (start & 1)
			ans = max(ans, otrezok[start]);
		// если r - левый сын своего родителя, 
		// учитываем его фундаментальный отрезок
		if (!(end & 1))
			ans = max(ans, otrezok[end]);
		// сдвигаем указатели на уровень выше
		start = (start + 1) / 2, end = (end - 1) / 2;
	}
	cout << ans << endl;
}

void Add1(int k, int d, vector<int>& fenvik)
{

}

void otrezokBuild(vector<int> arrayS, int v, int tl, int tr, vector<int> &otrezok) {
	if (tl == tr)
		otrezok[v] = arrayS[tl];
	else {
		int tm = (tl + tr) / 2;
		otrezokBuild(arrayS, v * 2, tl, tm, otrezok);
		otrezokBuild(arrayS, v * 2 + 1, tm + 1, tr, otrezok);
		otrezok[v] = otrezok[v * 2] + otrezok[v * 2 + 1];
	}
}