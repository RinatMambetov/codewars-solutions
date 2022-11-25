#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> splitStr(std::string const &str)
{
	std::string myStr = str;
	std::string separator = " ";
	unsigned long position;
	std::vector<std::string> result;
	while ((position = myStr.find(separator)) != std::string::npos)
	{
		std::string subStr = myStr.substr(0, position);
		result.push_back(subStr);
		myStr.erase(0, position + separator.size());
	}
	result.push_back(myStr);
	return result;
}

std::string spinWords(const std::string &str)
{
	std::vector<std::string> v = splitStr(str);
	std::string result;
	for (auto &elem : v)
	{
		if (elem.size() > 4)
			std::reverse(elem.begin(), elem.end());
		result += elem + " ";
	}
	result.pop_back();
	std::cout << result << '\n';
	return result;
}

int main()
{
	if (spinWords("Hey fellow warriors").compare("Hey wollef sroirraw") == 0 &&
		spinWords("Pizza is the best vegetable").compare("azziP is the best elbategev") == 0)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
