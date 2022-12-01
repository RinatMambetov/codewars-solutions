#include <iostream>
#include <sstream>
#include <math.h>

// get the number of digits in num
int getNumOfDig(int num)
{
	return log10(num) + 1;
}

template <typename T>
inline std::string toString(T num)
{
	std::ostringstream oStream;
	oStream << num;
	return oStream.str();
}

bool narcissistic(int value)
{
	std::string svalue(toString(value));
	size_t len(svalue.size());
	double sum(0);
	for (size_t i = 0; i < len; ++i)
	{
		char ch = svalue.at(i) - '0';
		sum += pow(ch, len);
	}
	if (static_cast<int>(sum) == value)
		return true;
	else
		return false;
}

int main()
{
	std::cout << std::boolalpha;
	if (narcissistic(153) == true && narcissistic(1652) == false)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong:\n"
				  << "narcissistic(153) must be true, but is " << narcissistic(153)
				  << "\nnarcissistic(1652) must be false, but is " << narcissistic(1652)
				  << '\n';
	return 0;
}
