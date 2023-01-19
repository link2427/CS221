#include "Playerlist.h"
#include <iostream>
#include <string>
Playerlist::Playerlist(int size) {

	currentSize = 0;
	head = nullptr;
	current = head;
	tail = head;
}


//Add player into list
bool Playerlist::addPlayer(Player* player) {
	if (currentSize == 0)
	{
		head = player;
		tail = player;
		currentSize++;
		return (true);
	}
	Player* currentNode = head;
	while (currentNode != nullptr) {
		if ((player->getLName() + player->getFName()) < (currentNode->getLName() + currentNode->getFName())) {
			if (currentNode->previous == nullptr) { // at first node
				currentNode->previous = player; 
				player->next = currentNode;
				head = player;
			}
			else { // not at first node
				currentNode->previous->next = player;
				player->previous = currentNode->previous;
				player->next = currentNode;
				currentNode->previous = player;
				currentSize++;
				return true;
			}
			currentSize++;
			return(true);
		}
		currentNode = currentNode->next;
	}
	tail->next = player;
	player->previous = tail;
	tail = player;
	currentSize++;
}


bool Playerlist::removePlayer(std::string firstName, std::string lastName) {
	Player* currentNode = head;
	bool isRemoved = false;
	while (isRemoved == false) {
		if (currentNode == nullptr) {
			return isRemoved;
		}

		if ((firstName + lastName) == (currentNode->getFName() + currentNode->getLName())) {
			if (currentNode->previous == nullptr) { // if currentnode is head
				head = currentNode->next;
				currentNode->next->previous = nullptr;
				delete currentNode;
				currentSize--;
				return true;
			}
			if (currentNode->next != nullptr) { // if currentnode is not head or tail
				currentNode->next->previous = currentNode->previous;
				currentNode->previous->next = currentNode->next;
				delete currentNode;
				currentSize--;
				return true;
			}
			if (currentNode->next == nullptr) { // if currentnode is tail
				currentNode->previous->next = nullptr;
				tail = currentNode->previous;
				delete currentNode;
				currentSize--;
				return true;
			}
		}
		currentNode = currentNode->next;
	}
}


//Clear list
void Playerlist::clear() {
	currentSize = 0;
	Player* temp = nullptr;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}


//Check if list is empty
bool Playerlist::isEmpty() {
	return(currentSize == 0);
}


//Get list size
int Playerlist::getSize() {
	return(currentSize);
}


//Get total calories burned
double Playerlist::getTotalCaloriesBurned() {
	double total = 0;
	Player* currentPlayer = head;
	while (currentPlayer != nullptr) {
		total += currentPlayer->getCaloriesBurned();
		currentPlayer = currentPlayer->next;
	}
	return total;
}


//Get next in list
Player* Playerlist::getNext(Player *player) {
	return player->next;
}


//Check if has next in list
bool Playerlist::hasNext(Player *player) {
	if (player != nullptr) {
		return true;
	}
	return false;
}


//Returns the head
Player* Playerlist::getHead() {
	return head;
}


//Returns the tail
Player* Playerlist::getTail() {
	return tail;
}


//Gets the previous
Player* Playerlist::getPrevious(Player* player) {
	return player->previous;
}


//Checks if player has previous
bool Playerlist::hasPrevious(Player* player) {
	if (player != nullptr) {
		return true;
	}
	return false;
}