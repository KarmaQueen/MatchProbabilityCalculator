#include <iostream>

class CategoryElement {
private:

	std::string name;
	CategoryElement *choice;
	int numChoice;

public:

	//Constructor
	CategoryElement(std::string str, int nchoice): name(str), numChoice(nchoice) { }

	bool equals(CategoryElement);
	
	//Getters
	std::string getName() { return name; }
	CategoryElement* getChoice(){ return choice; }

	//Setters
	void setChoice(CategoryElement *ces) {
		delete choice;
		choice = nullptr;

		choice = ces;
	}
};