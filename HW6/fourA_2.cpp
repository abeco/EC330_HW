//Abraham Cohen
//Working with Darshan Padmanabhan
//EC330 HW6 Question 4a
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool testWord(string& word){
	//for case where there are 2 whitespace chars in a row
	if(word.length() == 0){
		return false;
	}
	for(int i = 0; i<word.length(); i++){
		//convert to ascii for comparison
		int ascii = (int) word[i];
		//if the character isn't uppercase and not lowercase
		if((ascii < 65 || ascii > 90) && (ascii < 97 || ascii > 122) ){
			//cout<<"Found non-letter "<<word[i]<<endl;
			word = "";
			return false;
		}
	}
	//if it gets through the whole word without finding any non-letters
	word = "";
	return true;
}

int wordFinder(string filename){

	int counter = 0;

	ifstream inputFile;
	inputFile.open(filename.c_str(), ios::in);

	string line;

	if(inputFile.is_open()){
		while(getline(inputFile,line)){
			//cout<<"getline line: "<<line<<endl;
			//generate new word variable every line
			string word;

			int i = 0;

			while(i<line.length()){
				//if character in line isn't whitespace
				//don't think I need to include a newline, because getline would end there
				if(line[i] != ' ' && line[i] != '\t'){
					word = word + line[i];
					//cout<<"Added to word: "<<word<<endl;
				}
				//if it is whitespace
				else{
					//if word is a valid word
					if(testWord(word)){
						//increment the counter and reset word
						counter++;
						cout<<"Counted "<<word<<" in running total to make "<<counter<<endl;
						//word = "";
					}
					//if word contains any non-letter characters
					else{
						//just reset word and don't increment the counter
						//word = "";
					}
				}
				//need to account for last word in line, which won't be followed by whitespace
				if(i == (line.length() - 1) && testWord(word)){
					counter++;
				}
				//iterator for while loop
				i++;			
			}
		}
		//gotta close the file when you're done with it. If you don't that's just rude
		inputFile.close();
	}
	//should be the running total of valid words in the file
	return counter;
}

int main(){
	cout<<wordFinder("BigData.txt")<<endl;
}




//I think this is done