bst_transform: MyBST.o BST.o main.o
	g++ -std=c++0x  MyBST.o BST.o main.o -o bst_transform

main.o: main.cpp
	g++ -std=c++0x -c -Wall main.cpp

MyBST.o: MyBST.cpp
	g++ -std=c++0x -c -Wall MyBST.cpp

BST.o: BST.cpp
	g++ -std=c++0x -c  -Wall BST.cpp

clean:
	$(RM) BST.o MyBST.o main.o bst_transform
