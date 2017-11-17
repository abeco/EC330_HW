//Abraham Cohen working with Darshan Padmanabhan
//EC330 HW4
//Our algorithm runs in n^2 time. First it reads the file into 2 vectors for x and y.
//Then, it generates the slope and intercept for every pair of points in the file and puts them
//into placeholder vectors. It then iterates through that placeholder vector and picks out the
//slope/intercept pairs that repeat more than 4 times. If there are more than 4 points on the line though
//the same slope/intercept will appear in the outputs vectors more than once, so we put in a function to delete
//duplicates, and since the algorithm is already n^2, another n^2 isn't asymptotically sugnificant.
//Then it just goes through the output vector and prints all the points on each line.

#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <algorithm>


#include "plane.h"

LineFinder::LineFinder(){
	size = 0;
}

LineFinder::~LineFinder(){
}

void LineFinder::readFile(string file){
	ifstream inputFile;
	inputFile.open(file.c_str(), ios::in);

	string line;

	if(inputFile.is_open()){ 
		while(getline(inputFile,line)){
			vector<float> lineFloat;
			//turn input line read as string into floats
			stringstream ss(line);
			float n;
			while(ss>>n){
				//put those floats in a vector
				lineFloat.push_back(n);
			}
			//at this point we should have a vector of x and y
			//unless first line
			if(lineFloat.size() == 1){
				this->size = lineFloat[0];
			}
			else if(lineFloat.size() == 2){
				//put x's into vector, y's into vector
				//i realize after that it could have been easier to make a 'point' object but whatever this works fine
				this->x.push_back(lineFloat[0]);
				this->y.push_back(lineFloat[1]);
			}
		}
	}
	inputFile.close();
}
//useful to have a slope function
double LineFinder::slope(float x1, float x2, float y1, float y2){
	return((y2 - y1) / (x2 - x1));
}
//also useful to have an intercept function
double LineFinder::y_intercept(float y, double m, float x){
	return(y - m*x);
}
//real algorithm
void LineFinder::getMoney(){
	vector<double> slopes;
	vector<double> intercepts;
	for(int i = 0; i < size - 1; i++){
		//calculates slope between all pairs
		for(int j = i + 1; j < size; j++){
			//asymptotically n^2
			double tempSlope = slope(x[i],x[j],y[i],y[j]);
			double tempIntercept = y_intercept(y[i],tempSlope,x[i]);
			//put them in these placeholder vectors
			slopes.push_back(tempSlope);
			intercepts.push_back(tempIntercept);

		}
	}
	//iterates through slopes, intercepts, and whichever slope pops up 4+ times
	//it adds to a new vector to output
	for(int i = 0; i<slopes.size();i++){
		int count = 0;
		for(int j = i + 1; j < slopes.size();j++){
			//n^2
			if((slopes[i] == slopes[j])&&(intercepts[i] == intercepts[j])){
				count++;
			}
		}
		//3 colinear points will only produce 3 successful comparisons, so any more than that gives 
		//us the desired 4 points on the same line
		//the drawback here is that if there are more than 4 points, the same slope and intercept will
		//be added to the output vectors multiple times
		if(count >= 4){
				toOutputSlope.push_back(slopes[i]);
				toOutputIntercept.push_back(intercepts[i]);
				//I originally had a find function in here to not add to the output vector if the same 
				//slope and intercept value was already there, but it would have increased the 
				//runtime past n^2, so I just made another function to delete duplicates
		}
	}
	//delete duplicates
	for(int i = 0; i < toOutputSlope.size();i++){
		//use placeholders for the slope/intercepts
		double placeHolderSlope = toOutputSlope[i];
		double placeHolderIntercept = toOutputIntercept[i];
		for(int j = i + 1;j<toOutputSlope.size();j++){
			//n^2
			//compare
			if(placeHolderSlope == toOutputSlope[j] && placeHolderIntercept == toOutputIntercept[j]){
				toOutputSlope.erase(toOutputSlope.begin()+j);
				toOutputIntercept.erase(toOutputIntercept.begin()+j);
				//need to decrement j if you erase so it doesn't skip the next element
				j--;
			}
		}
	}

	//now just print the points on each output line
	for(int i = 0;i < toOutputSlope.size();i++){
		for(int j = 0; j < x.size();j++){
			if(y[j] == toOutputSlope[i]*x[j] + toOutputIntercept[i]){
				cout<<"("<<x[j]<<","<<y[j]<<")"<<endl;
			}
		}
		cout<<endl;
	}
	//now just like iterate through the shit to print the points that have that slope/intercept

}


int main(){
	string filename = "points.txt";
	LineFinder gazz;

	gazz.readFile(filename);

	gazz.getMoney();

}