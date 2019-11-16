#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip> 
#include "Data.h"
#include "BruteForce.h"
#include "DynamicProgramming.h"
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
	Data data;
	BruteForce bruteForce;
	DynamicProgramming dynamic;

	string name;
	int counter = 1;
	int choice;

	cout << endl << "0.Wyjscie." << endl;
	cout << "1.Wczytanie danych z pliku." << endl;
	cout << "2.Wyswietlenie wczytanych danych." << endl;
	cout << "3.Znalezenie przypadkowej trasy w grafie i policzenie wagi odpowiadajacej jej drogi." << endl;
	cout << "Algorytmy dokladne: " << endl;
	cout << "4. Brute Force" << endl;
	cout << "5. Dynamic Programming" << endl;
	
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
			data.load(name);
			bruteForce.load(name);
			dynamic.load(name);
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
	}
	return 0;
}