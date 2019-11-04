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
	long int number;
	int** graph;
	int sumOfEdgesFromRandomPath;

	vector<int> randomPath;
	vector<bool> visited;

	//Data();
	//~Data();

	void load(string name);
	void display();
	void resizeMyVectors();
	void findRandomPath();
	void countRandomPath();
};