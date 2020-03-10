#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip> 
#include <chrono>
#include "Data.h"
#include "BruteForce.h"
#include "DynamicProgramming.h"
#include "Test.h"
#include "Matrix.h"
#include "TabuSearch.h"
#include "GeneticAlgorithm.h"
using namespace std;

long long int read_QPC() //funkcja do pomiaru czasu
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

int main()
{
	srand(time(NULL));
	Matrix matrix;
	Data data;
	BruteForce bruteForce;
	DynamicProgramming dynamic;
	Test test;
	TabuSearch tabuSearch;
	GeneticAlgorithm genetic;

	string name;
	int time;
	int times;
	int counter = 1;
	int choice;

	int maxTime;
	int count;
	double mutation;
	double cross;

	cout << "Do wczytania danych uzyj opcji 1, a pozniej wybierz algorytm!!! " << endl;
	cout << endl << "0.Wyjscie." << endl;
	cout << "1.Wczytanie danych z pliku." << endl;
	cout << "2.Wyswietlenie wczytanych danych." << endl;
	cout << "3.Znalezenie przypadkowej trasy w grafie i policzenie wagi odpowiadajacej jej drogi." << endl;
	cout << "----------" << endl << "Algorytmy dokladne: " << endl;
	cout << "4. Brute Force" << endl;
	cout << "5. Dynamic Programming" << endl;
	cout << "6. Testy automatyczne" << endl;
	cout << "----------" << endl << " Algorytm lokalnego przeszukiwania. " << endl;
	cout << "7. Tabu Search" << endl;
	cout << "----------" << endl << " Algorytm populacyjny. " << endl;
	cout << "8. Algorytm genetyczny" << endl;
	
	while (counter > 0) {

		cout << endl << endl;
		cout << "Wybierz czynnosc\n";
		cin >> choice;

		if (choice == 0) {
			exit(0);
		}
		if (choice == 1) {
			cout << "Podaj nazwe pliku :";
			cin >> name;
			//name = "SMALL/data10.txt";
			data.load(name);
			//dynamic.load(name);
			//bruteForce.load(name);
			//tabuSearch.load(name);
			genetic.load(name);
			cout << "Poprawnie wczytano dane." << endl;
		}
		if (choice == 2) {
			data.display();
		}
		if (choice == 3) {
			data.findRandomPath();
			data.countRandomPath();
		}
		if (choice == 4) {

			long long int frequency, start, elapsed;
			QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
			start = read_QPC();

			bruteForce.findPath();

			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
			cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
			cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) / frequency << endl << endl;

		}
		if (choice == 5) {

			long long int frequency, start, elapsed;
			QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
			start = read_QPC();

			dynamic.showSolution();

			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
			cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
			cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) / frequency << endl << endl;
		}
		if (choice == 6) {
			test.runTests();
		}
		if (choice == 7) {
			tabuSearch.solve();
		}
		if (choice == 8) {
			genetic.algorithm();
			genetic.displayPopulation();
		}
	}
	//system("pause");
	return 0;
}