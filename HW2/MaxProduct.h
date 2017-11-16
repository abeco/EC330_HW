//Abraham Cohen
//worked with Darshan Padmanabhan
#ifndef MAXPRODUCT_H
#define MAXPRODUCT_H

using namespace std;

#include <vector>
#include <string>

class MaxProductClass{
	public:
		vector<long> maxProducts; //in order to print the set of lesser max Products 
		//long max; //to return at the end of maxProduct
		long MaxProduct(string file); //the moneymaker
		void printResults(); //to print everything at the end
		//string file; //because why not, lets me make everything private by passing to the constructor not the member function
		MaxProductClass(); //constructor
		~MaxProductClass(); //always gotta have a destructor, free up that memory

};

#endif