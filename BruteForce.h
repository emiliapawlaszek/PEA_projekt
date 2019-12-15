#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Matrix.h"
using namespace std;


class BruteForce :
	public Matrix
{
public:
	BruteForce();
	~BruteForce();

	int findPath();
};
