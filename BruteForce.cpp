#include "BruteForce.h"

void BruteForce::load(string name) {

	fstream file;
	file.open("C:\\Users\\Student241279\\OneDrive\\programs\\PEA_proj\\rsrc\\" + name, ios::in);
	if (file.good())
	{
		file >> instance;
		file >> size;
		graph.resize(size);
		for (int i = 0; i < size; i++) {
			graph[i].resize(size);
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				file >> graph[i][j];
			}
		}
	}
	else {
		cout << "Wrong path to the file" << endl;
	}
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