// GameApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Adam Lundell Guessing game Using vectors

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>



void saveScore(int count) {

	std::ifstream inputScore("BestScore.txt");
	
	if (!inputScore.is_open()) {
	
		std::cout << "You can not open the file! " << std::endl;
		return;
	}

	int bestScore;
	inputScore >> bestScore;
	
	std::ofstream outputScore("BestScore.txt");
	if (!outputScore.is_open()) {
		std::cout << "You can not open the file! " << std::endl;
		return;
	}
	
	
	if (count < bestScore) {

		outputScore << "best Score so far is! : " << count; 
	}
	else {
		outputScore << bestScore;
	}

}

void printVector(std::vector<int> vector ) { //Method for printing vectors
	int showGuessCount = 0;
	for (int i = 0; i < vector.size(); i++) { //for loop stop att the size of the vector
		showGuessCount++;
		std::cout << "guess " << showGuessCount << " was: " << vector[i] << std::endl;;

	}


}


void playGame() { // method for the game

	int randomNum = rand() % 21; //using rand % 21= setting maximum random number to be 20 
	int guess; // my guess value
	std::vector <int> guesses; //vector of type int
	bool failNoNumber; // boolean for the do while loop so you cannot type in strings
	int count = 0;

	std::cout << "You selected play game " << std::endl;
	do {// do while loop is for error checking if string is inputted
		while (true) {// while loop inside the do while loop for the game
			count++;
			std::cout << "Guess a random number between 0 - 20 " << std::endl;
			std::cin >> guess;
			failNoNumber = std::cin.fail();// sett failnonumber to false
			if (failNoNumber) { // when it is false i can do an error message if a string is inputted
				std::cout << "Invalid input, try again: " << std::endl;
				std::cout << "Type in a Number: " << std::endl;
				std::cin.clear(); // clear the error flag of sin 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoring all not integers from the cin
			}

			guesses.push_back(guess); //vector(list) add the guess value in the list
			
			if (guess == randomNum) { //if correct value is set you win
				std::cout << "You won! " << std::endl;
				
				break;
			}
			else if (guess < randomNum)// if value are less than correct value
			{
				std::cout << "Number is higher" << std::endl;
			}
			else {
				std::cout << "Number is lower" << std::endl; //if value are more than correct value
			}
		}
	
		saveScore(count);
		printVector(guesses); //using function print vector passing 
	} while (failNoNumber == true);// ending the do while loop if only int are inputted


}


int main()
{
	int choice;
	srand(time(NULL));// generate random number from the clock
	do
	{
		std::cout << "(1) To play game" << std::endl;
		std::cout << "(2) To quit" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			playGame();
			break;


		}
		switch (choice)
		{
		case 2:
			std::cout << "Program will exit " << std::endl;
			return 0;
		}
	} while (choice != 0);





}
