// ArifmProgr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ifstream inFile("in5.txt");
	ofstream outFile("output.txt");
	

	int testBlocks;
	int count;
	
	inFile >> testBlocks;

	bool isGood = true;;
	for (size_t i = 0; i < testBlocks; i++)
	{
		inFile >> count;

		if (count == 1)
		{
			outFile << "Yes" << endl;
			continue;
		}

		vector<int> progr(count);

		for (size_t i = 0; i < count; i++)
			inFile >> progr[i];

		sort(progr.begin(), progr.end());

		int d = progr[1] - progr[0];

		for (size_t i = 1; i < count; i++)
			if ((progr[i] - progr[i - 1]) != d)
			{
				outFile << "No" << endl;
				isGood = false;
				break;
			}

		if (isGood)
			outFile << "Yes" << endl;
		else
			isGood = true;
	}


    return 0;
}

