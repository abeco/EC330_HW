#ifndef plane_h
#define plane_h

#include <iostream>
using namespace std;

#include <vector>
#include <string.h>

class LineFinder{
public:
	LineFinder();
	~LineFinder();
	void readFile(string file);
	double slope(float, float, float, float);
	double y_intercept(float, double, float);
	void getMoney();
	int size;
	vector<float> x;
	vector<float> y;
	vector<double> toOutputSlope;
	vector<double> toOutputIntercept;
};


#endif