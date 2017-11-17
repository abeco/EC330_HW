//Abraham Cohen
//Working with Darshan Padmanabhan
//EC330 HW6 Question 4b

#include <iostream>
#include <fstream>
#include <string>
//#include <stdio.h>

using namespace std;
//just  a quick function to test if all the slots in letters are full
bool testPangram(bool letters[26]){
	for(int i = 0;i<26;i++){
		if(!letters[i]){
			return false;
		}
	}
	return true;
}
//iterate backwards to eliminate unnecessary characters from pangram
string shorten(string longPangram){

	bool shortenLetters[26];

	for(int i = 0;i<26;i++){
		shortenLetters[i] = false;
	}

	for(int i = longPangram.length()-1;i>=0;i--){
		int ascii = (int) longPangram[i];
		//if uppercase
		if(ascii >= 65 && ascii <= 90){
			shortenLetters[ascii-65] = true;
		}
		//else if lowercase
		else if(ascii >= 97 && ascii <= 122){
			shortenLetters[ascii-97] = true;
		}
		//test if it's a full pangram
		if(testPangram(shortenLetters)){
			string shorter = longPangram.substr(i,longPangram.length());
			//string shorter = longPangram[i:longPangram.length()-1];
			//cout<<"Shorter: "<<shorter<<" "<<shorter.length()<<endl;
			return shorter;
			//return longPangram[i:longPangram.length()-1];
		}	
		//it'll eventually get to being a full pangram because the only thing
		//that ever gets passed to it is a long pangram	
	}
}

string pangramFinder(string filename){
	//shortest pangram holder
	string shortest = "";

	//array to check if the string in foundPangram has all the letters
	bool letters[26];

	ifstream inputFile;
	inputFile.open(filename.c_str(), ios::in);

	char c;

	string foundPangram;

	while(inputFile.get(c)){
		//cout<<"c: "<<c<<endl;
		//get character, add to what will eventually be a pangram
		foundPangram = foundPangram + c;
		//cout<<"foundPangram: "<<foundPangram<<endl;
		int ascii = (int) c;
		//if uppercase
		if(ascii >= 65 && ascii <= 90){
			letters[ascii-65] = true;
		}
		//else if lowercase
		else if(ascii >= 97 && ascii <= 122){
			letters[ascii-97] = true;
		}
		//iterate through letters to check if foundPangram has all the letters,
		//and therefore is a valid pangram
		if(testPangram(letters)){
			//cout<<"FoundPangram: "<<foundPangram<<endl;
			//shorten it from the beginning
			//foundPangram = shorten(foundPangram);
			//cout<<"Shorter: "<<foundPangram<<endl;
			//check if it is shortest (or first)
			if( (foundPangram.length() < shortest.length()) || shortest.length() == 0){
				//if it is, foundPangram is the new shortest, and reset it to 0
				shortest = foundPangram;
				//cout<<"Shortest: "<<shortest<<" "<<shortest.length()<<endl;
				// for(int i = 0; i<26;i++){
				// 	cout<<letters[i]<<" ";
				// }
				//cout<<endl;
				for(int i = 0; i<26;i++){
					letters[i] = false;
				}
				foundPangram = "";
			}
			else{
				//if not, leave shortest unchanged and reset foundPangram
				foundPangram = "";
				for(int i = 0; i<26;i++){
					letters[i] = false;
				}

			}
		}
	}
	if(shortest.length()>0){
		//always gotta close the file. Don't be rude. 
		inputFile.close();
		return shortest;
	}
	else{
		shortest = "No pangrams could be found in the given text";
		inputFile.close();
		cout<<shortest<<endl;
		return shortest;
	}
}

int main(){
	cout<<pangramFinder("BigData.txt");
	return 0;
}