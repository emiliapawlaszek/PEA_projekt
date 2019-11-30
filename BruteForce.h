#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


class BruteForce
{
public:
	BruteForce();
	~BruteForce();
	string instance;
	long int size; //rozmiar - liczba miast
	vector<vector<int>> graph; //macierz kosztow

	void load(string name);
	int findPath();
};
