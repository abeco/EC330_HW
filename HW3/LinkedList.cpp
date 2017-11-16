#include <iostream>

#include "LinkedList.h"

using namespace std;

template <class T> LinkedList<T>::LinkedList(){
	this->head = new Node<T>();
	listSize = 0;
}
//destruct some stuff, deallocate memory and such
template <class T> LinkedList<T>::~LinkedList(){
	Node<T>* behind = head;
	Node<T>* ahead = head->next;
	delete head;
	while(ahead){
		behind = ahead;
		ahead = behind->next;
		delete behind;
	}
}
//just a getter function?
//or should I iterate through the list?
template <class T> int LinkedList<T>::size(){
	int final = 0;
	Node<T>* placeHolder = head;
	if(placeHolder->data)
		final++;
	while((placeHolder)->next){
		final++;
		placeHolder = placeHolder->next;
	}
	listSize = final;
	return final;
}
//check if contains by iterating through list with a Node ptr
template <class T> bool LinkedList<T>::contains(T x){
	//start at the head -- special case
	Node<T>* placeHolder = head;
	if(placeHolder->data == x){
		return true;
	}
	//while there's a next element
	while(placeHolder->next){
		//move to that one
		placeHolder = (placeHolder->next);
		//is that element == x?
		if(placeHolder->data == x){
			return true;
		}
	}
	return false;
}
//builds off of contains, only adds element if not in LL
//returns true if add is successful, false if already in LL
template <class T> bool LinkedList<T>::add(T x){
	//need to build in case for 1st element
	if(listSize == 0){
		head->data = x;
		listSize++;
		return true;
	}
	//if it doesn't already contain the value x
	if(!contains(x)){
		//same iterating mechanism as contains pretty much
		Node<T>* placeHolder = head;
		while(placeHolder->next){
			placeHolder = placeHolder->next;
		}
		//should be pointing to the last element right now
		//create a Node to point to
		placeHolder->next = new Node<T>();
		//goes to new Node
		placeHolder = placeHolder->next;
		placeHolder->data = x;
		return true;
	}
	//if x is already in the list 
	return false;
}
//builds off of contains, only removes if value is present in LL
//returns true if successful, false if value not present
//pretty much the opposite of add
template <class T> bool LinkedList<T>::remove(T x){
	if(!contains(x)){
		return false;
	}
	//need special case for first node
	if(head->data == x){
		Node<T>* temp = head->next;
		delete head;
		this->head = temp;
		return true;
	}

	Node<T>* placeHolder = head;
	while(placeHolder->next){
		//look ahead to see if next element is x
		if((placeHolder->next)->data == x){
			cout<<"Got to if remove"<<endl;
			//copy pointer over
			Node<T>* temp = (placeHolder->next)->next;
			//delete desired node
			delete placeHolder->next;
			//make prev node point to next node
			placeHolder->next = temp;
			listSize--;
			return true;
		}
		else{
			//if the next element isn't x, move on
			placeHolder = placeHolder->next;
		}
	}
	return false;
}

template <class T> void LinkedList<T>::print(){
	Node<T>* placeHolder = head;
	cout<<placeHolder->data<<" ";
	while(placeHolder->next){
		placeHolder = (placeHolder->next);
		cout<<placeHolder->data<<" ";
	}
	cout<<endl;
}

template class LinkedList<int>;
template class LinkedList<char>;