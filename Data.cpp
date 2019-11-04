#include "Data.h"
using namespace std;

//Data::Data() {}
//Data::~Data() {
//	randomPath.~vector<int>();
//	visited.~vector<bool>();
//}

void Data::load(string name) {

	fstream file;
	file.open("C:\\Users\\Student241279\\OneDrive\\programs\\PEA_proj\\rsrc\\" + name, ios::in);

	if (file.good() == false) {
		cout << "Wrong path to the file" << endl;
		exit(0);
	}
	if (file.good() == true) {
		file >> instance;
		file >> number;
		graph = new int* [number];

		for (int i = 0; i < number; i++) {
			graph[i] = new int[number];
		}

		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				file >> graph[i][j];
			}
		}
		resizeMyVectors();
	}
	file.close();
}

void Data::resizeMyVectors() {
	visited.resize(number);

	for (int i = 0; i < number; i++) {
		visited[i] = false;
	}
	randomPath.resize(number + 1);
}

void Data::display() {
	cout << "Wybrana instancja: ";
	cout << instance << endl << endl;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

//dwa kontenerki, jeden na boole, drugi na wierzcho³ki, zmienna na wagi
void Data::findRandomPath() {
	int j = 0;
	do {
		int vertex = abs((rand() % (number)) + 0);

		//sprawdzenie czy wylosowany wierzcho³ek jest nieodwiedzony
		if (visited[vertex] == false) {

			randomPath[j] = vertex;
			j++;
			visited[vertex] = true;
		}
	} while (j < number);
	randomPath[number] = randomPath[0];
	resizeMyVectors();

	cout << endl << "To wylosowana sciezka z poprzedniego grafu." << endl;
	for (int i = 0; i < randomPath.size() - 1; i++) {
		cout << randomPath[i] << " --> " << randomPath[i + 1] << " waga: " << "(" << graph[randomPath[i]][randomPath[i + 1]] << ")" << endl;
	}
	cout << endl << endl;
}

void Data::countRandomPath() {

	sumOfEdgesFromRandomPath = 0;
	for (int i = 0; i < number; i++) {
		sumOfEdgesFromRandomPath += graph[randomPath[i]][randomPath[i + 1]];
	}
	cout << "Waga przypadkowej sciezki: ";
	cout << sumOfEdgesFromRandomPath << endl;
}