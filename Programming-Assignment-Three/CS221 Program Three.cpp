// Jacob Neel
// Programming Assignment 3
// CS 221: Data Structures
// 11/1/2022

#include "Playerlist.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
//Function Declarations
void welcomeUser();
std::string getInputFileName();
std::string getOutputFileName();
Playerlist getPlayers(std::string inFileName);
void writeData(std::string outFileName, Playerlist players, char userInput);
//Main
int main() {

	welcomeUser();
	char userInput = NULL;
	std::string firstName;
	std::string lastName;
	std::cout << std::endl;
	std::string inFileName = getInputFileName();
	std::string outFileName = getOutputFileName();


	std::cout << std::endl << "Reading Players from: " << inFileName << std::endl;
	Playerlist players = getPlayers(inFileName);
	writeData(outFileName, players, userInput);


	do {
		std::cout << "Would you like to remove any players from your list? ";
		std::cin >> userInput;
		std::cout << std::endl;
		if (userInput == 'y') {
			std::cout << "	Please enter the First and Last Name of the Player: ";
			std::cin >> firstName >> lastName;
			std::cout << std::endl;
			if (players.removePlayer(firstName, lastName) == true) {
				std::cout << "\t" << firstName << " " << lastName << " Removed Successfully." << std::endl;
				writeData(outFileName, players, userInput);
			}
			else {
				std::cout << firstName << " " << lastName << " as not found in your list." << std::endl;
			}
		}
	} while (userInput == 'y' || userInput == 'Y');

	
	std::cout << "The data has been written to you output file: " << outFileName << std::endl << std::endl;


	std::cout << "End of Program 3" << std::endl;
}
//Welcomes the user
void welcomeUser() {
	std::cout << "Welcome to the player statistics calculator test program."
		<< std::endl << "I am going to read players from an input data file. You will tell me the names of your input and output files."
		<< std::endl << "I will store all of the players in a list, compute player's stats and then write the resulting team report to your output file."
		<< std::endl;
}
//Get input file name
std::string getInputFileName() {
	std::cout << "Enter the name of your input file: ";

	std::string inFileName;
	std::cin >> inFileName;
	return inFileName;
}
//Get output file name
std::string getOutputFileName() {
	std::cout << "Enter the name of your output file: ";

	std::string outFileName;
	std::cin >> outFileName;
	return outFileName;
}



//Gets the players from the input file and calls players.addPlayer()
Playerlist getPlayers(std::string inFileName) {
	std::ifstream inFile;
	inFile.open(inFileName);
	//Checks how many lines there are in the file
	std::string line;
	int numOfLines = 0;
	while (!inFile.eof()) {
		std::getline(inFile, line);
		numOfLines++;
	}
	//Goes back to the start of the file
	inFile.clear();
	inFile.seekg(0);
	//Create a player list
	Playerlist players = Playerlist(numOfLines);

	std::string firstName;
	std::string lastName;
	int age;
	int shotsTargetFor;
	int shotsTargetAgainst;
	int missedShotsFor;
	int missedShotsAgainst;
	int met;
	int bodyWeight;
	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> age;
		inFile >> shotsTargetFor;
		inFile >> shotsTargetAgainst;
		inFile >> missedShotsFor;
		inFile >> missedShotsAgainst;
		inFile >> met;
		inFile >> bodyWeight;
		Player* newPlayer = new Player(firstName, lastName, age, shotsTargetFor, shotsTargetAgainst, missedShotsFor, missedShotsAgainst, met, bodyWeight);
		players.addPlayer(newPlayer);
	}
	//Closes the file and returns players
	inFile.close();
	return players;
}
//Function to write the data to a file
void writeData(std::string outFileName, Playerlist players, char userInput) {
	//Creates ofstream of outfile
	std::ofstream outFile;

	if (userInput != 'y') {
		//Opens outfile using user defined name
		outFile.open(outFileName);
		//Writing to outfile
		outFile << "BASKETBALL TEAM REPORT --- " << players.getSize() << " PLAYERS FOUND IN FILE" << std::endl
			<< "TOTAL CALORIES BURNED: " << players.getTotalCaloriesBurned() << std::endl << std::endl
			<< std::string(6, ' ') << "PLAYER NAME" << std::string(6, ' ') << " :"
			<< std::string(7, ' ') << "FF%" << std::string(4, ' ')
			<< std::string(4, ' ') << "Calories burned" << std::endl
			<< std::string(58, '-') << std::endl;

		outFile << std::fixed << std::setprecision(1);

		Player* player = players.getHead();
		while (players.hasNext(player)) {

			outFile << std::setw(23) << (player->getLName() + ", " + player->getFName()) << " :"
				<< std::setw(11) << (player->getFenwick() * 100)
				<< std::setw(17) << player->getCaloriesBurned() << std::endl;
			player = players.getNext(player);
		}
		outFile.close();
	}
	if (userInput == 'y') { // If the user does remove a player we have to print the list in reverse order
		outFile.open(outFileName, std::ios_base::app);
		outFile << std::endl << "The list after removals contains " << players.getSize() << " entries." << std::endl;
		outFile << "They are in Reverse Order:" << std::endl;
		outFile << std::fixed << std::setprecision(1);

		Player* player = players.getTail(); // Uses getTail
		while (players.hasPrevious(player)) { // and hasPrevious to go print the list to the file in reverse order.

			outFile << std::setw(23) << (player->getLName() + ", " + player->getFName()) << " :"
				<< std::setw(11) << (player->getFenwick() * 100)
				<< std::setw(17) << player->getCaloriesBurned() << std::endl;
			player = players.getPrevious(player);
		}
		outFile.close();
	}
}