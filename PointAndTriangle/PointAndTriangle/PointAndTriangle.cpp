// PointAndTriangle.cpp: определяет точку входа для консольного приложения.
//11.1. Треугольник и точка (5)
//В декартовой системе координат на плоскости заданы координаты вершин треугольника и еще
//одной точки.Определить, принадлежит ли эта точка треугольнику.
//Исламов Яхья ПС-21 Visual Studio 2017

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
	long long int x, y;
};

long long int GetLength(Point firstPoint, Point secondPoint, Point thirdPoint);
void InicializationOfCoord(ifstream& inFile, Point& triangle1, Point& triangle2, Point& triangle3, Point& pointIn);
long long int GetDistanceFromPointToVerticeOfATriangle(const Point& triangle1, const Point& triangle2, const Point& triangle3, const Point& pointIn);

int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	Point triangle1;
	Point triangle2;
	Point triangle3;
	Point pointIn;

	InicializationOfCoord(inFile ,triangle1, triangle2, triangle3, pointIn);

	if (GetLength(triangle1, triangle2, triangle3) >= GetDistanceFromPointToVerticeOfATriangle(triangle1, triangle2, triangle3, pointIn))
		outFile << "In" << endl;
	else
		outFile << "Out" << endl;

    return 0;
}

long long int GetLength(Point firstPoint, Point secondPoint, Point thirdPoint)
{
	long long int  first = (secondPoint.y - firstPoint.y) * (thirdPoint.x - firstPoint.x);
	long long int second = (secondPoint.x - firstPoint.x) * (thirdPoint.y - firstPoint.y);
	return abs(first - second);
}

void InicializationOfCoord(ifstream& inFile ,Point& triangle1, Point& triangle2, Point& triangle3, Point& pointIn)
{
	inFile >> triangle1.x >> triangle1.y;
	inFile >> triangle2.x >> triangle2.y;
	inFile >> triangle3.x >> triangle3.y;
	inFile >> pointIn.x >> pointIn.y;
}

long long int GetDistanceFromPointToVerticeOfATriangle(const Point& triangle1, const Point& triangle2, const Point& triangle3, const Point& pointIn)
{
	long long int distance = 0;
	distance += GetLength(triangle1, triangle2, pointIn);
	distance += GetLength(triangle1, triangle3, pointIn);
	distance += GetLength(triangle2, triangle3, pointIn);
	return distance;
}