//Abraham Cohen
//EC330 HW8

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>

#include "MyBST.h"

using namespace std;
const int MAX_BUF_SIZE = 128;

vector<int> readBSTFile(string filename){

  vector <int> dataList;  // list of ints
  ifstream inputFile;

  // open file and
  inputFile.open(filename.c_str(),ios::in);

  static char buf[MAX_BUF_SIZE];

  while (inputFile.good()) {
      inputFile.getline(buf, sizeof(buf));

      // convert to an int and push onto our vector
      if (strlen(buf) > 0) {
        dataList.push_back(stoi(buf));
      }
  }

  inputFile.close();
  return dataList;

}

void printVector(vector<int> inputVector) {

  cout << "Vector: " << endl;
  for (int & i : inputVector) {
      cout << i << ' ';
  }
  cout << endl;
}

void printRotationVector(vector<Rotation> inputVector) {

//  cout << "Rotation: " << endl;
  for (Rotation & i : inputVector) {
    cout << i.print() << endl;
  }
  cout << endl;
}

int main(int argc, char *argv[]){


  /*  Error if we don't have 3 arguments
      command(1) and two parameters

      Show usage message and exit with exit
      value 1
   */
  if (argc < 3) {
    cout << "Usage: " << argv[0] << " file1 file2" << endl;

    return(1);
  }

  // Capture the two filenames
  const char *filename1 = argv[1];
  const char *filename2 = argv[2];

  // Create the vectors from the integers in the file
  vector <int> firstVector = readBSTFile(filename1);
  vector <int> secondVector = readBSTFile(filename2);

  vector<Rotation> rotations;

  // Let's look at the vectors
  printVector(firstVector);
  printVector(secondVector);

  // Now let's create the BSTs
  MyBST firstBST = MyBST(firstVector);
  MyBST secondBST = MyBST(secondVector);

  // Now let's print out the BSTs to see what they look like
  cout << "First BST: " << endl;
  cout << firstBST.print() << endl;

  cout << "Second BST: " << endl;
  cout << secondBST.print() << endl;


  printRotationVector(firstBST.transform(secondBST));

  return(0);
}
