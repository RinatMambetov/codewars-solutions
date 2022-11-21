#include <iostream>
#include <vector>
#include <numeric>

bool hasUniqueNum(std::vector<int> const &v, int num)
{
	int counter(0);
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v.at(i) == num)
			++counter;
	}
	if (counter > 1)
		return false;
	return true;
}

int repeats(std::vector<int> v)
{
	std::vector<int> t;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (hasUniqueNum(v, v.at(i)))
			t.push_back(v.at(i));
	}
	return std::accumulate(t.begin(), t.end(), 0);
}

int main()
{
	std::vector<int> V0{4, 5, 7, 5, 4, 8};
	std::vector<int> V1{5, 17, 18, 11, 13, 18, 11, 13};

	std::cout << repeats(V0) << '\n';
	std::cout << repeats(V1) << '\n';

	if (repeats(V0) == 15 &&
		repeats(V1) == 22)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
