#include <iostream>
#include <vector>

class CategoryElement {
private:

	std::string name;
	std::vector<std::string> *choice;

public:

	//Constructor
	CategoryElement(std::string str): name(str){
		choice = new std::vector<std::string>();
	}

	bool equals(CategoryElement);
	
	//Getters
	std::string getName() { return name; }
	std::vector<std::string>* getChoice(){ return choice; }

	//Methods
	void setChoice(std::vector<std::string> *ces);
	void addChoice(std::string str);
	void addChoice(CategoryElement *ce);
	bool existsInChoice(std::string str);
};


