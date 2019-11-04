#include "BruteForce.h"
#include "Data.h"

BruteForce::BruteForce() {}

BruteForce::~BruteForce() {

}

void BruteForce::load(string name) {

	fstream file;
	file.open("C:\\Users\\Student241279\\OneDrive\\programs\\PEA_projekt\\rsrc\\" + name, ios::in);

	if (file.good() == false) {
		cout << "Wrong path to the file" << endl;
		exit(0);
	}
	if (file.good() == true) {

		file >> instance;
		file >> number;
		graph = new int* [number];
		visited = new bool[number];
		weightOfpresentPath = new int[number];
		weightOfAllPossiblePaths = new int[number];


		for (int i = 0; i < number; i++) {
			graph[i] = new int[number];
		}

		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				file >> graph[i][j];
			}
		}
	}
	file.close();
}

int BruteForce::findPath() {

	int startVertex = 0; //wirzcho³ek pocz¹tkowy
	vector<int> vertex;

	for (int i = 0; i < number; i++) {
		if (i != startVertex) {
			vertex.push_back(i);
		}
	}

	int minPath = INT_MAX;
	do {
		int currentPathWeigh = 0;
		int k = startVertex;

		for (int i = 0; i < vertex.size(); i++) {
			currentPathWeigh += graph[k][vertex[i]];
			k = vertex[i];
		}
		currentPathWeigh += graph[k][startVertex]; //dodajemy wagê ostatniej krawêdzi

		minPath = min(minPath, currentPathWeigh);  //ruchy typu zamieñ
	} while (next_permutation(vertex.begin(), vertex.end())); //zwraca true jeœli mo¿e zmieniæ obiekt w wiêksz¹ permutacjê


	cout << minPath;
	return minPath;
}