#include <iostream>
#include <string>
#include "CategoryElement.h"
 
//num is the number of the category (e.g. 5 guys)
//choice is how many choices the category gets on another category (e.g. guys get to choose 3 girls)
int numA, choiceA;
int numB, choiceB;

std::vector<CategoryElement> arrA, arrB;
std::string input;

int main(void) {
	numA = 30; //students
	choiceA = 10; //students choose 3 companies
	numB = 12; //companies
	choiceB = 10; //companies choose 3 students

	while (input != "exit") {

		//initialize the arrays
		arrA = std::vector<CategoryElement>();
		arrB = std::vector<CategoryElement>();

		//give a name to each array
		for (int i = 0; i < numA; i++) {
			arrA.push_back(CategoryElement(std::string(1, (char)('a' + i))));
		}
		for (int i = 0; i < numB; i++) {
			arrB.push_back(CategoryElement(std::string(1, (char)('A' + i))));
		}

		//array randomly chooses from the other
		int count = 0, number = 0;
		for (unsigned int i = 0; i < arrA.size(); i++) {
			while (count < choiceA) {
				number = rand() % numB;
				if (!arrA[i].existsInChoice(arrB[number].getName())) {
					arrA[i].addChoice(arrB[number].getName());
					count++;
				}
			}
		}

		for (unsigned int i = 0; i < arrB.size(); i++) {
			while (count <= choiceB) {
				number = rand() % numA;
				if (!arrB[i].existsInChoice(arrA[number].getName())) {
					arrB[i].addChoice(arrA[number].getName());
					count++;
				}
			}
		}


		//check for matches
		int matches = 0;

		for (unsigned int i = 0; i < arrA.size(); i++) {
			for (unsigned int j = i; j < arrB.size(); j++) {
				if (arrA[i].existsInChoice(arrB[j].getName()) || arrB[j].existsInChoice(arrA[i].getName())) matches++;
			}
		}

		std::cout << "The number of matches is " << matches << std::endl;


		std::cin >> input;

	}
}
