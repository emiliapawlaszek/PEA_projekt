#pragma once
#include "Matrix.h"
#include <chrono>
#include <list>
class TabuSearch:
	public Matrix
{
public:
	int bestRouteCost = INT_MAX;
	vector<int> bestRoute;

	TabuSearch();
	~TabuSearch();
	void greedyAlgorithm();
	vector<int> simpleAlgorithm();
	int cost(vector<int> route);
	vector<int> swapElements(vector<int> route, int i, int j);
	void solve(int repetitions = 500, int repetitionsTabu = 10, int aspirationValue = -30, int maxAspirationCount = 30);
};

