#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MergeFiles(string file1, string file2){
	ifstream inFile1;
	ifstream inFile2;
	ofstream outFile;

	string line;

	outFile.open("output.txt");
	inFile1.open(file1.c_str(), ios::in);
	while(getline(inFile1, line)){
		outFile << line;
	}
	inFile1.close();
	inFile2.open(file2.c_str(), ios::in);
	while(getline(inFile2, line)){
		outFile << line;
	}
	outFile.close();
	inFile2.close();
}

int main(int argc, char* argv[]){
	MergeFiles(argv[1], argv[2]);
	return 0;
}