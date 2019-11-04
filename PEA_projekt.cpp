#include <iostream>
#include <fstream>
#include "Data.h"
#include "BruteForce.h"

using namespace std;

int main()
{
	Data data;
	BruteForce bruteForce;

	string name;

	int counter = 1;
	int choice;

	cout << "0.Wyjscie.\n";
	cout << "1.Wczytanie danych z pliku.\n";
	cout << "2.Wyswietlenie wczytanych danych.\n";
	cout << "3.Liczenie funkcji celu (dlugosci sciezki komiwojazera) dla wybranej wczesniej instancji. \n";
	cout << endl;
	cout << "4. Brute Force" << endl;
	srand(time(NULL));
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
		}
		if (choice == 2) {
			cout << "Wyswietlanie danych\n";
			data.display();
		}
		if (choice == 3) {
			data.findRandomPath();
			data.countRandomPath();
		}
		if (choice == 4) {
			cout << "Minimalna waga sciezki: ";
			bruteForce.load(name);
			bruteForce.findPath();
		}

	}

	return 0;
}