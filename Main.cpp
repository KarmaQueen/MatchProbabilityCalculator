#include <iostream>
#include "CategoryElement.h"

class Main {
private:
	//num is the number of the category (e.g. 5 guys)
	//choice is how many choices the category gets on another category (e.g. guys get to choose 3 girls)
	int numA, choiceA;
	int numB, choiceB;

	char *arrA, *arrB;
public:
	int main() {
		numA = 30; //students
		choiceA = 3; //students choose 3 companies
		numB = 12; //companies
		choiceB = 3; //companies choose 3 students

		//initialize the arrays
		arrA = new char[numA];
		arrB = new char[numB];

		assignCharToEveryElementInArray(65, arrA, numA);
		assignCharToEveryElementInArray(97, arrB, numB);


	}

	inline void assignCharToEveryElementInArray(char begin, char *arr, int length) {
		for (int i = 0; i < length; i++) {
			*(arr + i) = begin+i;
		}
	}
};