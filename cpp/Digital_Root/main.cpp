#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

int getSumDig(int n)
{
	std::string str = std::to_string(n);
	int sum(0);
	for (size_t i = 0; i < str.size(); ++i)
	{
		sum += str.at(i) - '0';
	}
	return sum;
}

int digital_root(int n)
{
	while (static_cast<int>(log10(n) + 1) > 1)
	{
		n = getSumDig(n);
	}
	return n;
}

int main()
{
	if (digital_root(16) == 7 &&
		digital_root(167346) == 9)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
