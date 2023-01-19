// CS 221 Programming Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include <cmath>


using namespace std;


class Player {
private:
    std::string firstName, lastName;

    int statistics[7] = {};

public:
    Player() {
        firstName = "unknown";
        lastName = "unknown";

        for (int i = 0; i < 7; i++)
        {
            statistics[i] = 0;
        }
    }

    void setFirstName(string first_Name) {
        firstName = first_Name;
    }


    void setLastName(string last_Name) {
        lastName = last_Name;
    }


    string getFirstName() {
        return firstName;
    }


    string getLastName() {
        return lastName;
    }


    void reader() {
        cin >> firstName >> lastName;

        for (int i = 0; i < 7; i++) {
            cin >> statistics[i];
        }
    }


    float fenwick() {
        float numerator = statistics[1] + statistics[3];
        float denominator = ((statistics[1] + statistics[3]) - (statistics[2] + statistics[4]));
        return(round(((numerator / denominator) * 100) * 10) / 10);
    }


    float caloricBurn() {
        return(round(((statistics[5] * statistics[6] * 3.5) / 200) * 10) / 10);
    }
};


int main()
{
    Player player;

    cout << "Welcome to the hockey player statistics test driver program. " << endl;                
    cout << "When prompted, please enter the player's data in the form of:" << endl;
    cout << "FirstName LastName Age ShotsTargetFor ShotTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight" << endl;
    
    bool contin = true;

    while (contin == true)
    {
        //
        cout << "Enter Player Data: " << endl;
        player.reader();

        //
        cout << player.getFirstName() << " " << player.getLastName();
        cout << "'s FF% = " << player.fenwick() << "% " << "and Calories burned " << player.caloricBurn() << endl;
        cout << "Would you like to calculate another? y/n" << endl;

        //
        string input;
        cin >> input;
        if (input == "n" || input == "N") {
            contin = false;
        }
    }
}
