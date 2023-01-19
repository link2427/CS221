#pragma once

#include <string>

class Player {
private:
	std::string fName;
	std::string lName;
	int stats[7];

public:
	Player();
	Player(std::string firstName, std::string lastName, int age,
		int shotsTargetFor, int shotsTargetAgainst, int missedShotsFor,
		int missedShotsAgainst, int met, int bodyWeight);

	std::string getFName(); // function to get first name
	std::string getLName(); // function to get last name
	int getStat(int index); // function to get stats
	double getFenwick(); // function to get fenwick
	double getCaloriesBurned(); // function to get calories burned
	Player* next;
	Player* previous;
	Player* val;
};