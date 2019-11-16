#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class DynamicProgramming
{
public:
	string instance;
	long int size; //rozmiar - liczba miast

	vector<vector<int>> graph; //macierz kosztow
	vector<vector<int>> dp; //do zapamietywania masek i pozycji

	void load(string name);
	int algorithm(int mask, int pos);
	void showSolution();

};

