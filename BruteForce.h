#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;


class BruteForce
{
public:
	BruteForce();
	~BruteForce();

	string instance;
	long int number;
	int** graph;
	bool* visited;
	int* weightOfpresentPath;
	int* weightOfAllPossiblePaths;


	void load(string name);
	int findPath();
};
