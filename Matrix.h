#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Matrix
{
public:
	string instance;
	long int size; //rozmiar - liczba miast
	vector<vector<int>> graph; //macierz kosztow

	std::vector<int> finalRoute;
	std::vector<int> tempRoute;
	std::vector<int> bestRoute;

	Matrix();
	~Matrix();
	void load(string name);
	int GetPathLength(vector<int> route);
};

