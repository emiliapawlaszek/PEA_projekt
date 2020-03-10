#include "Test.h"

void Test::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) std::cout << "QueryPerformanceFrequency failed!\n";
	PCFreq = double(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double Test::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void Test::runTests()
{
	BruteForce bruteForce;
	DynamicProgramming dynamic;
	TabuSearch tabuSearch;
	GeneticAlgorithm ga;

	string name;
	double endTime;
	double totalTime;
	double averageTime;

	fstream file;
	file.open("test.txt", ios::out | ios::app);
	if (file.good())
	{
		cout << "Test file opened, ready for input data." << endl;
	}
	else
	{
		cout << "Error opening test file." << endl;
		return;
	}

	////-----------------GA, SMALL---------------

	file << "GA, SMALL" << endl;
	cout << "GA, SMALL" << endl;
	for (int i = 10; i <= 18; i++)
	{
		name = "SMALL/data" + to_string(i) + ".txt";
		ga.load(name);
		ga.algorithm();
		file << ga.bestCost << endl;
	}

//-----------------GA, ATSP---------------

	file << "GA, ATSP" << endl;
	cout << "GA, ATSP" << endl;
	for (int i = 0; i <= 7; i++)
	{
		if (i == 0) name = "ATSP/ATSP/data17.txt";
		if (i == 1) name = "ATSP/ATSP/data36.txt";
		if (i == 2) name = "ATSP/ATSP/data43.txt";
		if (i == 3) name = "ATSP/ATSP/data48.txt";
		if (i == 4) name = "ATSP/ATSP/data56.txt";
		if (i == 5) name = "ATSP/ATSP/data70.txt";
		if (i == 6) name = "ATSP/ATSP/data100.txt";
		if (i == 7) name = "ATSP/ATSP/data323.txt";

		//if (i == 0) name = "ATSP/ATSP/data17.txt";
		//if (i == 1) name = "ATSP/ATSP/data34.txt";
		//if (i == 2) name = "ATSP/ATSP/data36.txt";
		//if (i == 3) name = "ATSP/ATSP/data39.txt";
		//if (i == 4) name = "ATSP/ATSP/data43.txt";
		//if (i == 5) name = "ATSP/ATSP/data45.txt";
		//if (i == 6) name = "ATSP/ATSP/data48.txt";
		//if (i == 7) name = "ATSP/ATSP/data53.txt";
		//if (i == 8) name = "ATSP/ATSP/data56.txt";
		//if (i == 9) name = "ATSP/ATSP/data65.txt";
		//if (i == 10) name = "ATSP/ATSP/data70.txt";
		//if (i == 11) name = "ATSP/ATSP/data71.txt";
		//if (i == 12) name = "ATSP/ATSP/data100.txt";
		//if (i == 13) name = "ATSP/ATSP/data171.txt";
		//if (i == 14) name = "ATSP/ATSP/data323.txt";
		//if (i == 15) name = "ATSP/ATSP/data358.txt";
		//if (i == 16) name = "ATSP/ATSP/data403.txt";
		//if (i == 17) name = "ATSP/ATSP/data443.txt";

		ga.load(name);
		ga.algorithm();
		file << ga.bestCost << endl;
	}

	//-----------------GA, TSP---------------

	file << "GA, TSP" << endl;
	cout << "GA, TSP" << endl;
	for (int i = 0; i <= 7; i++)
	{
		if (i == 0) name = "TSP/TSP/data17.txt";
		if (i == 1) name = "TSP/TSP/data21.txt";
		if (i == 2) name = "TSP/TSP/data24.txt";
		if (i == 3) name = "TSP/TSP/data26.txt";
		if (i == 4) name = "TSP/TSP/data29.txt";
		if (i == 5) name = "TSP/TSP/data42.txt";
		if (i == 6) name = "TSP/TSP/data58.txt";
		if (i == 7) name = "TSP/TSP/data120.txt";

		ga.load(name);
		ga.algorithm();
		file << ga.bestCost << endl;
	}

	file.close();

	//////-----------------TABU SEARCH, SMALL---------------

	////file << "TABU SEARCH, SMALL" << endl;
	////cout << "TABU SEARCH, SMALL" << endl;
	////for (int i = 10; i <= 18; i++)
	////{
	////	name = "SMALL/data" + to_string(i) + ".txt";
	////	tabuSearch.load(name);

	////	//int repetitions = 1000, int repetitionsTabu = 10, int aspirationValue = -30, int maxAspirationCount = 30
	////	tabuSearch.solve(6000, 10, -30, 10);
	////	file << tabuSearch.bestRouteCost << endl;
	////}
	////for (int i = 10; i <= 18; i++)
	////{
	////	name = "SMALL/data" + to_string(i) + ".txt";
	////	tabuSearch.load(name);

	////	StartCounter();
	////	tabuSearch.solve(6000, 10, -30, 10);
	////	endTime = GetCounter();

	////	file << endTime << endl;
	////}

	////-----------------TABU SEARCH, ATSP---------------

	//file << "TABU SEARCH, ATSP" << endl;
	//cout << "TABU SEARCH, ATSP" << endl;
	//for (int i = 0; i <= 7; i++)
	//{
	//	if (i == 0) name = "ATSP/ATSP/data17.txt";
	//	if (i == 1) name = "ATSP/ATSP/data36.txt";
	//	if (i == 2) name = "ATSP/ATSP/data43.txt";
	//	if (i == 3) name = "ATSP/ATSP/data48.txt";
	//	if (i == 4) name = "ATSP/ATSP/data56.txt";
	//	if (i == 5) name = "ATSP/ATSP/data70.txt";
	//	if (i == 6) name = "ATSP/ATSP/data100.txt";
	//	if (i == 7) name = "ATSP/ATSP/data323.txt";

	//	//if (i == 0) name = "ATSP/ATSP/data17.txt";
	//	//if (i == 1) name = "ATSP/ATSP/data34.txt";
	//	//if (i == 2) name = "ATSP/ATSP/data36.txt";
	//	//if (i == 3) name = "ATSP/ATSP/data39.txt";
	//	//if (i == 4) name = "ATSP/ATSP/data43.txt";
	//	//if (i == 5) name = "ATSP/ATSP/data45.txt";
	//	//if (i == 6) name = "ATSP/ATSP/data48.txt";
	//	//if (i == 7) name = "ATSP/ATSP/data53.txt";
	//	//if (i == 8) name = "ATSP/ATSP/data56.txt";
	//	//if (i == 9) name = "ATSP/ATSP/data65.txt";
	//	//if (i == 10) name = "ATSP/ATSP/data70.txt";
	//	//if (i == 11) name = "ATSP/ATSP/data71.txt";
	//	//if (i == 12) name = "ATSP/ATSP/data100.txt";
	//	//if (i == 13) name = "ATSP/ATSP/data171.txt";
	//	//if (i == 14) name = "ATSP/ATSP/data323.txt";
	//	//if (i == 15) name = "ATSP/ATSP/data358.txt";
	//	//if (i == 16) name = "ATSP/ATSP/data403.txt";
	//	//if (i == 17) name = "ATSP/ATSP/data443.txt";

	//	tabuSearch.load(name);
	//	tabuSearch.solve(2000, 30, -30, 10);
	//	file << tabuSearch.bestRouteCost << endl;
	//}
	//for (int i = 0; i <= 7; i++)
	//{
	//	if (i == 0) name = "ATSP/ATSP/data17.txt";
	//	if (i == 1) name = "ATSP/ATSP/data36.txt";
	//	if (i == 2) name = "ATSP/ATSP/data43.txt";
	//	if (i == 3) name = "ATSP/ATSP/data48.txt";
	//	if (i == 4) name = "ATSP/ATSP/data56.txt";
	//	if (i == 5) name = "ATSP/ATSP/data70.txt";
	//	if (i == 6) name = "ATSP/ATSP/data100.txt";
	//	if (i == 7) name = "ATSP/ATSP/data323.txt";

	//	tabuSearch.load(name);
	//	StartCounter();
	//	tabuSearch.solve(2000, 30, -30, 10);
	//	endTime = GetCounter();
	//	file << endTime << endl;
	//}

	////-----------------TABU SEARCH, TSP---------------

	//file << "TABU SEARCH, TSP" << endl;
	//cout << "TABU SEARCH, TSP" << endl;
	//for (int i = 0; i <= 7; i++)
	//{
	//	if (i == 0) name = "TSP/TSP/data17.txt";
	//	if (i == 1) name = "TSP/TSP/data21.txt";
	//	if (i == 2) name = "TSP/TSP/data24.txt";
	//	if (i == 3) name = "TSP/TSP/data26.txt";
	//	if (i == 4) name = "TSP/TSP/data29.txt";
	//	if (i == 5) name = "TSP/TSP/data42.txt";
	//	if (i == 6) name = "TSP/TSP/data58.txt";
	//	if (i == 7) name = "TSP/TSP/data120.txt";

	//	tabuSearch.load(name);
	//	tabuSearch.solve(2000, 30, -30, 10);
	//	file << tabuSearch.bestRouteCost << endl;
	//}
	//for (int i = 0; i <= 7; i++)
	//{
	//	if (i == 0) name = "TSP/TSP/data17.txt";
	//	if (i == 1) name = "TSP/TSP/data21.txt";
	//	if (i == 2) name = "TSP/TSP/data24.txt";
	//	if (i == 3) name = "TSP/TSP/data26.txt";
	//	if (i == 4) name = "TSP/TSP/data29.txt";
	//	if (i == 5) name = "TSP/TSP/data42.txt";
	//	if (i == 6) name = "TSP/TSP/data58.txt";
	//	if (i == 7) name = "TSP/TSP/data120.txt";

	//	tabuSearch.load(name);
	//	StartCounter();
	//	tabuSearch.solve(2000, 30, -30, 10);
	//	endTime = GetCounter();
	//	file << endTime << endl;
	//}

	//file.close();

	////-----------------BRUTE FORCE, SMALL---------------
	//totalTime = 0;
	//averageTime = 0;
	//file << "BRUTE FORCE, SMALL" << endl;
	//cout << "BRUTE FORCE, SMALL" << endl;
	//for (int i = 10; i <14; i++)
	//{
	//	name = "SMALL/data" + to_string(i) + ".txt";
	//	bruteForce.load(name);

	//	for (int j = 0; j < 10; j++)
	//	{
	//		StartCounter();
	//		bruteForce.findPath();
	//		endTime = GetCounter();

	//		//file << endTime << endl;

	//		totalTime += endTime;
	//	}
	//	averageTime = totalTime / 10;
	//	file << averageTime << endl;
	//}

	////------------DYNAMIC PROGRAMMING, SMALL-----------------------
	//totalTime = 0;
	//averageTime = 0;
	//file << "DYNAMIC PROGRAMMING, SMALL" << endl;
	//cout << "DYNAMIC PROGRAMMING, SMALL" << endl;
	//for (int i = 10; i <= 18; i++)
	//{
	//	name = "SMALL/data" + to_string(i) + ".txt";

	//	for (int j = 0; j < 10; j++)
	//	{
	//		dynamic.load(name);
	//		StartCounter();
	//		dynamic.showSolution();
	//		endTime = GetCounter();

	//		//file << endTime << endl;
	//		totalTime += endTime;
	//		dynamic.~DynamicProgramming();
	//	}
	//	averageTime = totalTime / 10;
	//	file << averageTime << endl;
	//}

	////------------DYNAMIC PROGRAMMING, ATSP-----------------------
	////system("cls");
	//totalTime = 0;
	//averageTime = 0;
	//file << "DYNAMIC PROGRAMMING, ATSP" << endl;
	//cout << "DYNAMIC PROGRAMMING, ATSP" << endl;
	//for (int i = 0; i <= 5; i++)
	//{
	//	//if (i == 0) name = "ATSP/ATSP/data17.txt";
	//	//if (i == 1) name = "ATSP/ATSP/data34.txt";
	//	if (i == 2) name = "ATSP/ATSP/data36.txt";
	//	//if (i == 3) name = "ATSP/ATSP/data39.txt";
	//	//if (i == 4) name = "ATSP/ATSP/data43.txt";
	//	//if (i == 5) name = "ATSP/ATSP/data45.txt";
	//	dynamic.load(name);
	//	StartCounter();
	//	dynamic.showSolution();
	//	endTime = GetCounter();

	//	cout << i << ") -> " << endTime << endl;
	//	file << endTime << endl;

	//	totalTime += endTime;
	//}
	//averageTime = totalTime / 6;
	//cout << "Average performance time: " << averageTime << endl;
	//file << "Average time: " << averageTime << endl;

//	------------DYNAMIC PROGRAMMING, TSP-----------------------
//system("cls");
//	totalTime = 0;
//	averageTime = 0;
//	file << "DYNAMIC PROGRAMMING, TSP" << endl;
//	cout << "DYNAMIC PROGRAMMING, TSP" << endl;
//	for (int i = 0; i <= 5; i++)
//	{
//		if (i == 0) name = "TSP/TSP/data17.txt";
//		if (i == 1) name = "TSP/TSP/data21.txt";
//		if (i == 2) name = "TSP/TSP/data24.txt";
//		if (i == 3) name = "TSP/TSP/data26.txt";
//		if (i == 4) name = "TSP/TSP/data29.txt";
//		if (i == 5) name = "TSP/TSP/data42.txt";
//		dynamic.load(name);
//		StartCounter();
//		dynamic.showSolution();
//		endTime = GetCounter();
//
//		cout << i << ") -> " << endTime << endl;
//		file << endTime << endl;
//
//		totalTime += endTime;
//	}
//	averageTime = totalTime / 6;
//	cout << "Average performance time: " << averageTime << endl;
//	file << "Average time: " << averageTime << endl;
}

