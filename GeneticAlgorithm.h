#pragma once
#include "Matrix.h"
#include <iostream>

struct Population
{
	vector<int> population;
	int populationCost;
};

class GeneticAlgorithm: public Matrix
{
public:
	int stopTime;
	int populationCount;
	double mutationCoefficient;
	double crossCoefficient;

	vector<int> bestPath;
	int bestCost;


	GeneticAlgorithm();
	~GeneticAlgorithm();
	int calculateCost(vector<int> vector);
	vector<Population> createPopulation(int number);
	Population mutateSwap(Population individual);
	Population mutateScramble(Population individual);
	Population crossover(Population parent1, Population parent2);
	void algorithm();
	void displayPopulation();
};

