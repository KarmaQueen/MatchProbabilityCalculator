#include "CategoryElement.h"

bool CategoryElement::equals(CategoryElement ce)
{
	return name == ce.name;
}

void CategoryElement::setChoice(std::vector<std::string>* ces) {
	delete choice;
	choice = nullptr;

	choice = ces;
}

void CategoryElement::addChoice(CategoryElement * ce) {
	choice->push_back(ce->name);
}

void CategoryElement::addChoice(std::string str) {
	choice->push_back(str);
}

bool CategoryElement::existsInChoice(std::string str) {
	if (choice->size() <= 0) return false;
	for (std::string s : *choice) {
		if (s == str) return true;
	}
	return false;
}