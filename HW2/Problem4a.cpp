#include <iostream>
#include <fstream>		//for reading the text file
#include <string>
using namespace std;

int StringSearch(string filename, string pattern){
	//string filename = inFilename;
	//string pattern = inPattern;
	//cout<<pattern<<endl;
	int final = 0;
	string line;
	//char c;
	ifstream myfile;
	myfile.open(filename.c_str(), ios::in);
	if(myfile.is_open()){		
	//check if file is still open
		while(getline(myfile, line)){		
		//get 1 line at a time
			for(int i = 0; i < line.length();i++){
				if(line[i] == pattern[0]){
				//if a char in the line matches the first char in the pattern
					string match;
					match += line[i];
					for(int j = 1; j < pattern.length(); j++){
						match += line[i+j];
						//create a string starting from that char of the same length as pattern
					}
					//cout<<match<<endl;
					if(pattern.compare(match) == 0){
						//if it matches the pattern, increment number of matches to return
						final++;
					}
				}
			}
		}
		myfile.close();
	}
	return final;

}

//fix issue lets say pattern = 'cba' and in the file it goes 'cdcba', it won't find the match
//need to make a temporary placeholder so that if it's not a match, goes back to the char after
//the first one that matches
//works now that I used getline instead of get


int main(int argc, char* argv[]){
	cout<<StringSearch(argv[1], argv[2])<<endl;
	return 0;
}