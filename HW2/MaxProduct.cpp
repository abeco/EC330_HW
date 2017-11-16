//Abraham Cohen
//worked with Darshan Padmanabhan

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "MaxProduct.h"

using namespace std;

#define TERMINATOR -999999 
//clearer to define it than to type -999999 a bunch of times in the code

//constructor
MaxProductClass::MaxProductClass(){
	//this->file = file;
	//max = maxProduct(file);
	//printResults();
}
//real algorithmic beauty over here
long MaxProductClass::MaxProduct(string file){
	ifstream inputFile;
	inputFile.open(file.c_str(), ios::in);
	//reading in and opening the file

	string line;
	//to read in a line

	if(inputFile.is_open()){
	//check if the file is open
		while(getline(inputFile,line)){
			//get a line
			vector<int> lineInts;
			//put it in here
			stringstream ss(line);

			while(ss){
				int n;
				ss>>n;
				lineInts.push_back(n);
			}
			//now we start with the maxproduct algorithm
			vector<long> products;
			//keeps track of all possible return values
			for(int i = 0; i < lineInts.size() - 2; i++){
				//for some reason my vector had 2 terminators at the end. whatever
				if(lineInts[i+1] != TERMINATOR && lineInts[i+2] != TERMINATOR){
					products.push_back(lineInts[i]);
					products.push_back(lineInts[i]*lineInts[i+1]);
					products.push_back(lineInts[i]*lineInts[i+1]*lineInts[i+2]);
					//put into products the 3 values associated with that number,
					//the number itself, multiplied with it's neighbor, and that * 2 doors down
				}
				else if(lineInts[i+1] == TERMINATOR){
					products.push_back(lineInts[i]);
					//if the next one is terminator then just put that one into products
				}
				else if(lineInts[i+2] == TERMINATOR){
					products.push_back(lineInts[i]);
					products.push_back(lineInts[i]*lineInts[i+1]);
					//because my vector turned out a bit weird and had 2 terminators for some reason
				}
				
			}
		maxProducts.push_back(*max_element(products.begin(),products.end()));
		//keep track of maxProducts from each line
		}
	inputFile.close();
	}
	printResults();
	return(*max_element(maxProducts.begin(),maxProducts.end()));
	//return highest one
}
//to make things nice at the end
void MaxProductClass::printResults(){
	for(int i = 0;i<maxProducts.size();i++){
		cout<<maxProducts[i]<<endl;
	}
	//cout<<"The overall max product is: "<<max<<endl;
}
//destructor
MaxProductClass::~MaxProductClass(){
	//cout<<"MaxProduct object destructed"<<endl;
}
/*
int main(){
	MaxProductClass thing;
	long max = thing.MaxProduct("input3.txt");
	cout<<"the overall max product is "<<max<<endl;
	return 0;
}*/