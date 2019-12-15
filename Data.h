#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

class Data
{
public:
	string instance;
	int number;
	int** graph;
	int sumOfEdgesFromRandomPath; 

	vector<int> randomPath;
	vector<bool> visited;

	void load(string name);
	void display();
	void resizeMyVectors();
	void findRandomPath();
	void countRandomPath();
};