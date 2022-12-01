#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

std::string likes(const std::vector<std::string> &names)
{
	if (names.size() == 0)
		return "no one likes this";
	if (names.size() == 1)
		return names.at(0) + " likes this";
	if (names.size() == 2)
		return names.at(0) + " and " + names.at(1) + " like this";
	if (names.size() == 3)
		return names.at(0) + ", " + names.at(1) + " and " + names.at(2) + " like this";
	return names.at(0) + ", " + names.at(1) + " and " + std::to_string(names.size() - 2) + " others like this";
}

int main()
{
	std::vector<std::string> v0{"Peter"};
	std::vector<std::string> v1{"Max", "John", "Mark"};
	std::vector<std::string> v2{"Alex", "Jacob", "Mark", "Max"};

	if (likes(v0).compare("Peter likes this") == 0 &&
		likes(v1).compare("Max, John and Mark like this") == 0 &&
		likes(v2).compare("Alex, Jacob and 2 others like this") == 0)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
