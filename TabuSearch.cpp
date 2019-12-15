#include "TabuSearch.h"
#include <chrono>
#include <thread>

TabuSearch::TabuSearch() {
}

TabuSearch::~TabuSearch() {

	if (bestRoute.size() != 0) {
		bestRoute.erase(bestRoute.begin(), bestRoute.end());
	}
	//if (graph.size() != 0) {
	//	graph.erase(graph.begin(), graph.end());
	//}
}

//wybor poczatkowego algorytmu: algorytm zachlanny. wybiera wierzcholek niezajety i o najmniejszej wadze.
void TabuSearch::greedyAlgorithm() {
	if (bestRoute.size() != 0) {
		bestRoute.erase(bestRoute.begin(), bestRoute.end());
	}

	int min = INT_MAX;
	int vertex;
	int first = 0;
	vector<bool> visited(graph.size());
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	bestRoute.push_back(0);
	for (int i = 1; i < graph.size(); i++) {
		for (int j = 1; j < graph.size(); j++) {
			if ((graph[first][j] < min) && (first != j) && (visited[j] != true)) {
				
				min = graph[first][j];
				vertex = j;
			}
		}
		visited[vertex] = true;
		bestRoute.push_back(vertex);
		min = INT_MAX;
		first = vertex;
	}
	bestRoute.push_back(0);

	bestRouteCost = cost(bestRoute);
	cout << "Koszt algorytmem zachlannym: " << bestRouteCost << endl;
}

vector<int> TabuSearch::simpleAlgorithm() {

	bestRoute.resize(graph.size() + 1);
	for (int i = 0; i < graph.size(); i++) {
		bestRoute[i] = i;
	}
	bestRoute[graph.size()] = bestRoute[0];


	//cout << "Best route Cost by simpleAlgorithm: " << cost(bestRoute) << endl;
	//for (int i = 0; i < graph.size(); i++) {
	//	cout << bestRoute[i] << " -> ";
	//}
	//cout << bestRoute[0] << endl;

	return bestRoute;
}

//liczenie kosztu drogi
int TabuSearch::cost(vector<int> route) {
	int cost = 0;
	for (int i = 0; i < graph.size() ; i++){
		cost += graph[route[i]][route[i + 1]];
	}
	//droga += graph[solution[graph.size()]][solution[0]];
	return cost;
}

vector<int> TabuSearch::swapElements(vector<int> route, int i, int j)
{
	int temp = route[i];
	route[i] = route[j];
	route[j] = temp;
	return route;
}

void TabuSearch::solve(int repetitions, int repetitionsTabu, int aspirationValue, int maxAspirationCount) {
	//greedyAlgorithm(); //teraz w bestRoute i bestRouteCost mamy wyniki

	bestRoute = simpleAlgorithm();
	bestRouteCost = cost(bestRoute);

	int aspirationPlus = false;
	int aspirationCounter = 0;

	vector<vector<int>>tabuList(graph.size()); //inicjalizacja tabu list
	for (int i = 0; i < graph.size(); i++) {
		tabuList.at(i).resize(graph.size());
		for (int j = 0; j < graph.size(); j++) {
			tabuList[i][j] = 0;
		}
	}
	vector<int> currentRoute(graph.size());
	currentRoute.assign(bestRoute.begin(), bestRoute.end());

	vector<int> tempRoute(graph.size());
	int tempRouteCost = bestRouteCost;

	int bestSwapFrom, bestSwapTo;
	int bestSwapValue;

	for(int k = 0; k < repetitions; k++) {
		bestSwapValue = INT_MAX; 
		for (int i = 1; i < graph.size() - 1; i++) {
			for (int j = i + 1; j < graph.size(); j++) { //z ruszaniem czy bez ruszania ostatniego i pierwszego???

				//kopiujemy do tempRoute currentRoute i swapujemy elementy
				tempRoute.assign(currentRoute.begin(), currentRoute.end());
				tempRoute = swapElements(tempRoute, i, j);

				//jeœli po swapie jest fajniej, difference im mniejszy
				//od wersji ze swapem odejmujemy wersje bez swapu
				int difference = cost(tempRoute) - cost(currentRoute);
				//..lub kryterium aspiracji spe³nione
				if (((difference < bestSwapValue) && (tabuList[i][j] == 0)) || (difference < aspirationValue)) {
					bestSwapValue = difference;
					bestSwapFrom = i;
					bestSwapTo = j;
					if (difference < aspirationValue) {
						aspirationPlus = true; //kryterium aspiracji spelnione
						aspirationCounter = 0;
					}
				}
				aspirationCounter++;
				//dywersyfikacja - restart
				if (aspirationCounter == maxAspirationCount && aspirationPlus == true) {
					goto out;
				}
			}
			//cout << bestRouteCost << endl;
		}

		out:
		// decrement tabuList
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph.size(); j++) {
				if (tabuList[i][j] > 0) {
					tabuList[i][j]--;
				}
			}
		}
		//ustaw najlepsze sasiedztwo jako currentRoute i ustaw tabu
		currentRoute = swapElements(currentRoute, bestSwapFrom, bestSwapTo);
		tabuList[bestSwapFrom][bestSwapTo] = repetitionsTabu;
		tabuList[bestSwapTo][bestSwapFrom] = repetitionsTabu;

		//ustaw nowa wartosc jesli znaleziona
		if (cost(currentRoute) < bestRouteCost) {
			bestRoute = swapElements(bestRoute, bestSwapFrom, bestSwapTo);
			bestRouteCost = cost(bestRoute);
		}
	}
	// cleanup
	for (int i = 0; i < graph.size(); i++) {
		tabuList.at(i).erase(tabuList.at(i).begin(), tabuList.at(i).end());
	}
	tabuList.erase(tabuList.begin(), tabuList.end());

	currentRoute.erase(currentRoute.begin(), currentRoute.end());
	tempRoute.erase(tempRoute.begin(), tempRoute.end());


	//cout << "Best route Cost: " << bestRouteCost << endl;
	//for (int i = 0; i < graph.size(); i++) {
	//	cout << bestRoute[i] << " -> ";
	//}
	//cout << bestRoute[0] << endl;
}