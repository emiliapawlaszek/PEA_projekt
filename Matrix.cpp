#include "Matrix.h"

Matrix::Matrix() {
}

Matrix::~Matrix() {
	graph.erase(graph.begin(), graph.end());
}

void Matrix::load(string name) {
	fstream file;
	file.open("rsrc\\"+ name, ios::in);
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

int Matrix::GetPathLength(vector<int> route)
{
	int weightOfPath = 0;

	for (int i = 0; i < size - 1; i++)
	{
		weightOfPath += graph[route[i]][route[(i + 1) % size]];

	}
	weightOfPath += graph[route[size - 1]][route[0]];
	return weightOfPath;
}