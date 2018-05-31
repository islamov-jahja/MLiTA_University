// trolleybus.cpp: определяет точку входа для консольного приложения.
/*19.9. Троллейбусы (4)
Троллейбусы одного маршрута проходят через остановку каждые K минут. Известны времена
прихода N жителей на остановку. Если человек приходит на остановку в момент прихода
троллейбуса, то он успевает войти в этот троллейбус. Определить в пределах часа время прибытия
первого троллейбуса на остановку T такого, чтобы суммарное время ожидания троллейбуса для
всех граждан было минимальным. Если этот минимум достигается в разные моменты прибытия,
вывести наиболее раннее время.*/
//Исламов Яхья ПС-21

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	int k, n;
	inFile >> k;
	inFile >> n;

	vector<int> arrOfMan(n);

	for (size_t i = 0; i < n; i++)
		inFile >> arrOfMan[i];

	int minT = 0, minSumm = 200000000;
	int summ = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			summ += ((i - arrOfMan[j]) % k + k) % k;
		
		if (summ < minSumm)
		{
			minT = i;
			minSumm = summ;
		}

		summ = 0;
	}
	
	outFile << minT;
    return 0;
}

