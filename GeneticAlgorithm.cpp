#include "GeneticAlgorithm.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <random>
#include <functional>
#include <ctime>

GeneticAlgorithm::GeneticAlgorithm()
{
	stopTime = 10; //czas wykonywania
	populationCount = 100;	//wielkoœæ populacji
	mutationCoefficient = 0.01; //wspolczynnik mutacji
	crossCoefficient = 0.6; //wspolczynnik krzyzowania

	bestPath.resize(graph.size());
	bestCost = 0;
}


GeneticAlgorithm::~GeneticAlgorithm()
{
	bestPath.clear();
}

int GeneticAlgorithm::calculateCost(vector<int> vector)
{
	int cost = 0;

	for (int k = 0; k < vector.size() - 1; k++)
	{
		cost += graph[vector.at(k)][vector.at(k + 1)];
	}
	cost += graph[vector.at(vector.size() - 1)][vector.at(0)];
	return cost;
}

bool CostCompare(const Population& x, const Population& y)
{
	return x.populationCost < y.populationCost;
}

vector<Population> GeneticAlgorithm::createPopulation(int popCount)
{
	Population pop;
	vector<Population> population;
	vector<int> path;
	int pathCost = 0;

	for (int i = 0; i < popCount; i++)
	{
		//stworzenie populacji
		for (int j = 0; j < graph.size(); j++)
		{
			path.push_back(j);
		}
		//Randomly rearrange elements in range
		random_shuffle(path.begin(), path.end());

		//liczenie kosztu
		for (int k = 0; k < path.size() - 1; k++)
		{
			pathCost += graph[path.at(k)][path.at(k + 1) % graph.size()];
		}
		pathCost += graph[path.at(path.size() - 1)][path.at(0)];

		//umieszczenie w wektorze struktur
		pop.population = path;
		pop.populationCost = pathCost;
		population.push_back(pop);

		path.clear();
		pathCost = 0;
	}

	return population;
}

Population GeneticAlgorithm::mutateSwap(Population pop)
{
	//losowanie dwoch roznych miast
	int x, y;
	do
	{
		x = rand() % graph.size();
		y = rand() % graph.size();

	} while (x == y);

	//zamiana miast miejscami
	swap(pop.population.at(x), pop.population.at(y));

	//policzenie kosztu
	pop.populationCost = calculateCost(pop.population);
	return pop;
}

Population GeneticAlgorithm::crossover(Population parent1, Population parent2)
{
	Population child;
	vector<bool> visited;

	visited.resize(graph.size());
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < graph.size() / 2; i++)
	{
		child.population.push_back(parent1.population[i]); //dodawanie kolejnych miast rodzica1 do dziecka
		visited[parent1.population[i]] = true;
	}
	for (int i = graph.size() / 2; i < graph.size(); i++) //uzupelnienie wolnymi miastami z rodzica2
	{
		if (!visited[parent2.population[i]])
		{
			child.population.push_back(parent2.population[i]);
			visited[parent2.population[i]] = true;
		}
	}
	//wypelnienie niewykorzystanymi miastami
	for (int i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			child.population.push_back(i);
		}
	}

	visited.clear();

	child.populationCost = calculateCost(child.population);

	return child;
}

void GeneticAlgorithm::algorithm()
{
	clock_t start, end;
	Population pop;
	vector<Population> p = createPopulation(populationCount);
	vector<int> vector;

	random_device rd;
	mt19937 gen(rd()); // random generator
	//Produces random floating-point values
	uniform_real_distribution<> dis(0.0, 1.0);

	start = clock();
	do
	{
		for (int i = 0; i < p.size(); i++)
		{
			//get random number
			if (dis(gen) < crossCoefficient)
			{
				int parentIndex1;
				int parentIndex2;

				//losujemy roznych rodzicow
				do
				{
					parentIndex1 = rand() % p.size();
					parentIndex2 = rand() % p.size();

				} while (parentIndex1 == parentIndex2);

				//krzyzujemy losowo wybranych rodzicow
				p.push_back(crossover(p[parentIndex1], p[parentIndex2]));
			}
		}

		int index;
		for (int i = 0; i < p.size(); i++)
		{
			if (dis(gen) < mutationCoefficient)
			{
				index = rand() % p.size();
				//wybranie populacji z wektora populacji
				p[index] = mutateSwap(p[index]); //zamiana miejscami miast i liczenie kosztu drogi
				break;
			}
		}
		//zakresy oraz porównywanie
		//Predykat ma zwracaæ wartoœæ false, je¿eli pierwszy argument powinien znajdowaæ siê za drugim, natomiast true w przeciwnym wypadku.
		sort(p.begin(), p.end(), CostCompare); //sortowanie populacji po najlepszych sciezkach

		while (p.size() > populationCount)
		{
			p.pop_back();
		}

		end = clock();

	} while ((double(end - start) / CLOCKS_PER_SEC) <= stopTime); 

	//wybieramy najlepsza populacje
	pop = p.front();

	bestPath = pop.population;
	bestCost = pop.populationCost;
}

void GeneticAlgorithm::displayPopulation()
{
	cout << endl;
	cout << "Sciezka: " << endl;

	for (int i = 0; i < bestPath.size(); i++)
	{
		if (i == bestPath.size() - 1)
		{
			cout << bestPath[i];
		}
		else
			cout << bestPath[i] << "->";
	}

	cout << endl;
	cout << "Koszt: " << bestCost << endl;
}