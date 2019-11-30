#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>

#include "Data.h"
#include "BruteForce.h"
#include "DynamicProgramming.h"

using namespace std;

class Test{
	
	LARGE_INTEGER li;
	double PCFreq = double(li.QuadPart) / 1000000.0;
	__int64 CounterStart = 0;

public:
	void generateNames();
	void StartCounter();
	double GetCounter();
	void runTests();
};

