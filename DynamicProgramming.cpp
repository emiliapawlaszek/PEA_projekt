#include "DynamicProgramming.h"

DynamicProgramming::~DynamicProgramming() {
	graph.erase(graph.begin());
	dp.erase(dp.begin());
}
void DynamicProgramming::load(string name)
{
	fstream file;
	file.open("rsrc\\" + name, ios::in);
	if (file.good())
	{
		file >> instance;
		file >> size;
		graph.resize(size);

		dp.resize(pow(2, size));//rozmiar dp[2 do N][N]
		for (int i = 0; i < pow(2, size); i++) {
			dp[i].resize(size);
		}

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


int DynamicProgramming::algorithm(int mask, int pos) { //maska jakie ju¿ odwiedzone, pos np dla 1 miasta: 0001

	//jesli wszystkie miasta sa odwiedzone
	int visitedAll = (1 << size) - 1;
	if (mask == visitedAll) {
		return graph[pos][0]; //waga ostatniego polaczenia
	}

	//jezeli wywolalismy juz algorytm z tymi parametrami to wynik bedzie zapisany na tej pozycji w tablicy dp 
	if (dp[mask][pos] != -1) {
		return dp[mask][pos];
	}

	int ans = INT_MAX;
	//niech sprobuje pojsc do nieodwiedzonego miasta
	for (int i = 0; i < size; i++) {

		if ((mask & (1 << i)) == 0){ //jesli nie jest odwiedzone

			int newAns = graph[pos][i] + algorithm(mask | (1 << i), i); //obecna waga + wywolanie rekurencyjne z powiekszona maska i kolejna pozycja
			ans = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
}

void DynamicProgramming::showSolution() {
	//w celu zapamietywania naszych masek
	for (int i = 0; i < (1 << size); i++) {
		for (int j = 0; j < size; j++) {
			dp[i][j] = -1;
		}
	}
	cout << "Minimalny koszt drogi wedlug algorytmu Dynamic Programming:  " << algorithm(1, 0) << endl;
}