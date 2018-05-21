// perestanovki.cpp: определяет точку входа для консольного приложения.
//8.2 Простые примеры на перестановки (6)
//Исламов Яхья ПС-21

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


void InverseAndRestore();
void ConstructVecOfInv();
void RestoreThePermutation();
void PermutationEquation();
vector<int> GetProductOfPermutations(vector<int> firstPermutation, vector<int> secondPermutaion);
vector<int> GetReversePermutation(vector<int> permutation);
void PrintPermutationWithNEl();
void Print(vector<int> const permutation);
int SearchI(vector<int> permutation);
int SearchJ(vector<int> permutation, int i);
void GeneratePermutation(int now, int n, vector<int> arr, bool toLeft);
void PrintSetOfPermutation(vector<int>& arr, bool toLeft, int n);
void specOperationWithPermutation(vector<int>& m_arr, vector<int>& arr, bool toLeft, int k);

int main()
{
	string action = "";

	while (action != "...")
	{
		cout << "choose action" << endl;
		cout << "1. solve the equation on permutations of the form A*X = B" << endl;
		cout << "2. for a given permutation of N elements, to give K the following permutations in lexicographical order" << endl;
		cout << "3. for a given permutation, construct a vector of inversions, and with respect to the inversion vector restore the permutation" << endl;
		cout << "4. list the permutations of N elements by transposing adjacent elements with recursion and without it." << endl;
		cout << "5. exit" << endl;
		cin >> action;

		if (action == "...")
			break;
		else if (action == "3")
			InverseAndRestore();
		else if (action == "1")
			PermutationEquation();
		else if (action == "2")
			PrintPermutationWithNEl();
		else if (action == "4")
		{
			cout << "enter the order number of the permutation" << endl;
			int n;
			cin >> n;
			vector<int> arr(n);
			for (size_t i = 0; i < n; i++)
				arr[i] = i + 1;
			if (n != 1)
				GeneratePermutation(2, n, arr, true);
			else cout << 1;
		}
		else if (action == "5")
			break;
	}

    return 0;
}

void GeneratePermutation(int now, int n, vector<int> arr, bool toLeft)
{
	if (now == n)
	{
		PrintSetOfPermutation(arr, toLeft, n);
	}
	else if (now != n)
	{
		vector<int> m_arr;

		if (!toLeft)
		{
			if (now % 2 == 0)
			{
				for (int i = 0; i < now; i++)
				{
					if ((i % 2) == 0)
					{
						specOperationWithPermutation(m_arr, arr, false, now);
						GeneratePermutation(now + 1, n, m_arr, false);
					}
					else
					{
						specOperationWithPermutation(m_arr, arr, true, now);
						GeneratePermutation(now + 1, n, m_arr, true);
					}

					if (i != now - 1)
						swap(arr[i], arr[i + 1]);
				}
			}
			else
			{
				for (int i = 0; i < now; i++)
				{
					if ((i % 2) != 0)
					{
						specOperationWithPermutation(m_arr, arr, false, now);
						GeneratePermutation(now + 1, n, m_arr, false);
					}
					else
					{
						specOperationWithPermutation(m_arr, arr, true, now);
						GeneratePermutation(now + 1, n, m_arr, true);
					}

					if (i != now - 1)
						swap(arr[i], arr[i + 1]);
				}
			}
		}
		else
		{
			if (now % 2 == 0)
			{
				for (int i = now - 1; i >= 0; i--)
				{
					if ((i % 2) == 0)
					{
						specOperationWithPermutation(m_arr, arr, false, now);
						GeneratePermutation(now + 1, n, m_arr, false);
					}
					else
					{
						specOperationWithPermutation(m_arr, arr, true, now);
						GeneratePermutation(now + 1, n, m_arr, true);
					}

					if (i != 0)
						swap(arr[i - 1], arr[i]);
				}
			}
			else
			{
				for (int i = now - 1; i >= 0; i--)
				{
					if ((i % 2) != 0)
					{
						specOperationWithPermutation(m_arr, arr, false, now);
						GeneratePermutation(now + 1, n, m_arr, false);
					}
					else
					{
						specOperationWithPermutation(m_arr, arr, true, now);
						GeneratePermutation(now + 1, n, m_arr, true);
					}

					if (i != 0)
						swap(arr[i - 1], arr[i]);
				}
			}
		}
	}
}

void specOperationWithPermutation(vector<int>& m_arr, vector<int>& arr, bool toLeft, int k)
{
	m_arr.clear();

	if (toLeft)
	{
		for (size_t i = 0; i < k; i++)
			m_arr.push_back(arr[i]);

		m_arr.push_back(k + 1);
	}
	else if (!toLeft)
	{
		m_arr.push_back(k + 1);

		for (size_t i = 0; i < k; i++)
			m_arr.push_back(arr[i]);
	}
}

void PrintSetOfPermutation(vector<int>& arr, bool toLeft, int n)
{
	if (toLeft)
		for (int i = n - 1; i > 0; i--)
		{
			Print(arr);
			swap(arr[i], arr[i - 1]);
			if (i == 1)
				Print(arr);
		}
	else if (!toLeft)
		for (size_t i = 0; i < n - 1; i++)
		{
			Print(arr);
			swap(arr[i], arr[i + 1]);
			if (i == n - 2)
				Print(arr);
		}
}

void PrintPermutationWithNEl()
{
	cout << "enter count of elements in permutation" << endl;
	int count;
	cin >> count;
    cout << "enter permutation" << endl;
	vector<int> permutation(count);

	for (size_t i = 0; i < count; i++)
		cin >> permutation[i];

	int countOfPermutation;
	cout << "enter count of permutation" << endl;
	cin >> countOfPermutation;
	Print(permutation);

	int i, j, m_count = 0;

	while (true)
	{
		m_count++;
		i = SearchI(permutation);

		if (i == -1 || m_count == countOfPermutation)
			break;

		j = SearchJ(permutation, i);
		swap(permutation[i], permutation[j]);
		sort(permutation.begin() + i + 1, permutation.end());
		Print(permutation);
	}
}

int SearchJ(vector<int> permutation, int i)
{
	list<int> listOfEl;
	for (size_t j = i + 1; j < permutation.size(); j++)
		if (permutation[j] > permutation[i])
			listOfEl.push_back(permutation[j]);

	int count = 9999999;
	for (auto x : listOfEl)
		if (count > x)
			count = x;

	for (size_t j = i + 1; j < permutation.size(); j++)
		if (permutation[j] == count)
			return j;

	return -1;
}

int SearchI(vector<int> permutation)
{
	for (int i = permutation.size() - 2; i >= 0; i--)
		if (permutation[i] < permutation[i + 1])
			return i;

	return -1;
}

void Print(vector<int> const permutation)
{
	for (size_t i = 0; i < permutation.size(); i++)
		cout << permutation[i] << ' ';
	cout << endl;
}


void PermutationEquation()
{
	int count;
	cout << "enter the number of elements in permutations" << endl;
	cin >> count;

	cout << "Enter the permutation A" << endl;
	vector<int> permutationA(count);

	for (size_t i = 0; i < count; i++)
		cin >> permutationA[i];

	cout << "Enter the permutation B" << endl;

	vector<int> permutationB(count);

	for (size_t i = 0; i < count; i++)
		cin >> permutationB[i];

	vector<int> reversePermutation = GetReversePermutation(permutationA);
	vector<int> productOfPermutation = GetProductOfPermutations(reversePermutation, permutationB);
	Print(productOfPermutation);
}

vector<int> GetProductOfPermutations(vector<int> firstPermutation, vector<int> secondPermutaion)
{
	vector<int> productOfPermutations(firstPermutation.size());

	for (size_t i = 0; i < firstPermutation.size(); i++)
		productOfPermutations[i] = secondPermutaion[firstPermutation[i] - 1];

	return productOfPermutations;
}

vector<int> GetReversePermutation(vector<int> permutation)
{
	vector<int> reversePermutation(permutation.size());

	for (size_t i = 0; i < permutation.size(); i++)
		reversePermutation[permutation[i] - 1] = i+1;

	return reversePermutation;
}

void InverseAndRestore()
{
	string action;

	cout << "choose action" << endl;
	cout << "1. construct vector of inversion" << endl;
	cout << "2. restore the permutation" << endl;

	cin >> action;
	if (action == "1")
		ConstructVecOfInv();
	else if (action == "2")
		RestoreThePermutation();

}

void ConstructVecOfInv()
{
	vector<int> perestanovka;
	int count = 0;

	cout << "enter count of elements" << endl;;
	cin >> count;
	cout << "enter the permutation" << endl;

	for (size_t i = 0; i < count; i++)
	{
		int element;
		cin >> element;
		perestanovka.push_back(element);
	}
		
	vector<int> inversionVec(perestanovka.size());

	for (int i = (inversionVec.size() - 1); i >= 0; i--)
	{
		int countOfEl = 0;
		if (i != 0)
			for (int j = (i - 1); j >= 0; j--)
				if (perestanovka[i] < perestanovka[j])
					countOfEl++;

		inversionVec[i] = countOfEl;
	}

	Print(inversionVec);
}

void RestoreThePermutation()
{
	vector<int> vecOfInvers;
	int count = 0;
	list<int> elements;

	cout << "enter count of elements" << endl;;
	cin >> count;
	cout << "enter the inversion" << endl;

	for (size_t i = 0; i < count; i++)
	{
		int element;
		cin >> element;
		vecOfInvers.push_back(element);
	}

	for (size_t i = 1; i <= count; i++)
		elements.push_back(i);

	vector<int> permutation(vecOfInvers.size());

	count = 0;
	for (int i = (permutation.size() - 1); i >= 0; i--)
	{
		for (auto x : elements)
		{
			count++;
			if (count == elements.size() - vecOfInvers[i])
			{
				permutation[i] = x;
				list<int>::iterator it = find(elements.begin(), elements.end(), x);
				elements.erase(it);
				count = 0;
				break;
			}
		}
	}

	Print(permutation);
}