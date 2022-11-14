#include <iostream>
#include <vector>

bool hasNum(const std::vector<int> &v, int num)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v.at(i) == num)
			return true;
	}
	return false;
}

int findOdd(const std::vector<int> &numbers)
{
	if (numbers.size() < 3)
		return numbers.at(0);
	std::vector<int> t;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (!hasNum(t, numbers.at(i)))
			t.push_back(numbers.at(i));
	}
	int c;
	for (size_t i = 0; i < t.size(); ++i)
	{
		c = 0;
		for (size_t j = 0; j < numbers.size(); ++j)
		{
			if (t.at(i) == numbers.at(j))
				++c;
		}
		if (c % 2 != 0)
			return t.at(i);
	}
	return 0;
}

int main()
{
	std::vector<int> V0{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5};
	std::vector<int> V1{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5};

	if (findOdd(V0) == 5 &&
		findOdd(V1) == -1)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
