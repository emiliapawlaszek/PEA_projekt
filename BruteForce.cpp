#include "BruteForce.h"

BruteForce::BruteForce() {

}
BruteForce::~BruteForce() {
	graph.erase(graph.begin());
}

int BruteForce::findPath() {

	int startVertex = 0; //wirzcholek poczatkowy
	vector<int> vertex;

	for (int i = 0; i < size; i++) {//bez zerowego
		if (i != startVertex) {
			vertex.push_back(i);
		}
	}

	int minPath = INT_MAX;
	do {
		int currentPathWeigh = 0;
		int k = startVertex;

		for (int i = 0; i < vertex.size(); i++) {
			currentPathWeigh += graph[k][vertex[i]]; //bez zerowego
			k = vertex[i];
		}
		currentPathWeigh += graph[k][startVertex]; //dodajemy wage ostatniej krawadzi

		minPath = min(minPath, currentPathWeigh);  //zamien
	} while (next_permutation(vertex.begin(), vertex.end())); //zwraca true jesli moze zmienic obiekt w wieksza permutacje


	cout << "Minimalny koszt drogi:  " << minPath << endl;
	return minPath;
}