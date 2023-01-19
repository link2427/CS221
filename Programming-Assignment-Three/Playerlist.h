#pragma once

#include "Player.h"

class Playerlist {
private:
	Player* head;
	Player* tail;
	Player* current;
	int maxSize;
	int currentSize;
	int iteratorIndex;

public:
	Playerlist(int size);
	bool addPlayer(Player *player); // function to add a player to list
	bool removePlayer(std::string firstName, std::string lastName); // function to remove a player from the list
	void clear(); // function to clear list
	bool isEmpty(); // function to check if the list is empty
	int getSize(); // function to get size
	double getTotalCaloriesBurned(); // function to get total calories burned
	Player* getNext(Player *player); // function to get next
	bool hasNext(Player *player); // function to check if there is a next
	Player* getHead();
	Player* getTail();
	Player* getPrevious(Player *player);
	bool hasPrevious(Player* player);
};