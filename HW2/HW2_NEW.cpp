#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

void readFile(string filename, vector<int> &myVector){
	ifstream input(filename.c_str());
	//input.open(filename.c_str(), ios::in);

	if(input){
		string line;
		while(getline(filename.c_str(),line)){
			line = " " + line + " ";
			cout<<"Line: "<<line<<endl;

			for(int i = 0; i<line.size();i++){
				string numberString;
				if(line[i] == ' '){
					for(int j = i + 1;j<line.size();j++){
						if(line[j] == ' '){
							for(int k = i+1;k<j;k++){
								numberString = numberString + line[k];
							}
							cout<<"NumberString: "<<numberString<<endl;
							int numberInt = stoi(numberString);
							cout<<"Print numberInt: "<<numberInt<<endl;
							myVector.push_back(numberInt);
							break;
						}
					}
				}
			}
		}
	}
}

int main(){
	vector<int> testVector;
	readFile("input3.txt", testVector);
	return 0;
}