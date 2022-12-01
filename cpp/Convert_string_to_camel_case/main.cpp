#include <iostream>
#include <string>

std::string to_camel_case(std::string text)
{
	if (text.size() < 2)
		return text;
	std::string s;
	s.push_back(text.at(0));
	bool flag = false;
	std::string set("-_");
	for (size_t i = 1; i < text.size(); ++i)
	{
		if (set.find(text.at(i)) != std::string::npos)
		{
			flag = true;
		}
		else if (flag)
		{
			s.push_back(std::toupper(text.at(i)));
			flag = false;
		}
		else
		{
			s.push_back(text.at(i));
		}
	}
	return s;
}

int main()
{
	if (to_camel_case("the-stealth-warrior").compare("theStealthWarrior") == 0 &&
		to_camel_case("The_Stealth_Warrior").compare("TheStealthWarrior") == 0)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
