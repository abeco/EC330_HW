//Abraham Cohen
//Working with Darshan Padmanabhan
//EC330 HW5

/*If it isn't clear from the in-line comments, I'll explain my methodology for adding to the 
cuckoo hash table here. First I computed h1(b)(I made b = value and a the number in that space, so 
I could visualize it as b kicking out a). If that slot in the hash table was empty, I'd just insert
that and break the while loop. If that space was taken by another number, I'd store the value and
compute its h2(a), and replace a with b. Then I'd check h2(a) for a number, and if that was empty
I'd put a there. If not, I'd set the number that was there to the new b, put a in that slot and 
repeat the whole process until either the loop becomes infinite or it finds a slot.



Also just curious, why wasn't the add function a bool?
I feel like that would've been better style no? So that the main function makes sure everything 
was added correctly and can spit out an error if it doesn't?
*/
#include "CuckooHashTable.h"
#include <string>
#include <vector>
//#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
using namespace std;

CuckooHashTable::CuckooHashTable(){
	//initialize 2 vectors of 13 to all "-"s
	vector<string> hash1;
	contents.push_back(hash1);
	for(int i = 0; i < 13; i++){
		contents[0].push_back("-");
	}
	vector<string> hash2;
	contents.push_back(hash2);
	for(int i = 0; i < 13; i++){
		contents[1].push_back("-");
	}
	currentSize = 0;
}

//CuckooHashTable::~CuckooHashTable(){}

int CuckooHashTable::hashCode(string value, int which){
	int valueInt = atoi(value.c_str()); //can't mod a string with an int
	if(which == 1){
		return valueInt % 13;
	}
	else if(which == 2){
		return 11-(valueInt % 11);
	}
}

void CuckooHashTable::add(string value){
	int count = 0;
	//compute h1(x)
	string b = value;
	int h1b = hashCode(value, 1); 
	//52 is largest number before biggest infinite loop
	//because you'd have to visit every slot twice
	//might actually be 50, because it's not possible for h2(x) to ever be 12
	//but I just want to make sure, so I built in one extra round
	//also there's a built in safeguard against adding newline characters. Those mess stuff up
	while(count < 52 && value != "\0"){
			//check if anything is in that value
		//just a note, it's safe to use contents[] as opposed to contents.at() here because
		//I'm 100% sure the array index is in bounds
		if(contents[0][h1b] == "-"){
			//if not, insert b at first hash and break the loop
			contents[0][h1b] = b;
			//contents.at(0).at(h1) = b;
			break;
		}
		else{
			//if something is already there
			count++;
			//get the content and h2 of the thing already there
			string a = contents[0][h1b];
			int h2a = hashCode(a,2);
			//and put b there to kick out a
			contents[0][h1b] = b;
			//check the second hash
			if(contents[1][h2a] == "-"){
				//if empty, insert and break
				contents[1][h2a] = a;
				break;
			}
			else{
				//if something's there
				count++;
				//store that = new b and insert a into h2
				b = contents[1][h2a];
				h1b = hashCode(b,1);
				contents[1][h2a] = a;
			}
		}
	}
	if(count >= 52){
		cout<<"The given set of inputs produces an infinite loop"<<endl;
		exit (EXIT_FAILURE);		
	}
}

void CuckooHashTable::print(){
	for(int i = 0; i < 2; i++){
		cout<<"Table "<<(i+1)<<":"<<endl;
		for(int j = 0; j < 13; j++){
			cout<<contents[i][j]<<endl;
		}
	}
}

