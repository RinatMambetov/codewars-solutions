#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
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

int getMiss(std::vector<int> const &arr)
{
	for (size_t i = 0; i < arr.size() - 1; ++i)
	{
		if (arr[i + 1] - arr[i] == 2)
			return arr[i + 1] - 1;
	}
	return 0;
}

std::pair<int, std::vector<int>> findDupsMiss(const std::vector<int> &arr)
{
	std::vector<int> t;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (std::count(arr.begin(), arr.end(), arr.at(i)) > 1 && !hasNum(t, arr.at(i)))
			t.push_back(arr.at(i));
	}
	std::sort(t.begin(), t.end());
	std::vector<int> s = arr;
	std::sort(s.begin(), s.end());
	int miss = getMiss(s);
	return {miss, t};
}

int main()
{
	std::vector<int> V0{10, 9, 8, 9, 6, 1, 2, 4, 3, 2, 5, 5, 3};
	std::vector<int> V1{5, 17, 18, 11, 13, 18, 11, 13};

	std::cout << findDupsMiss(V0).first << '\n';
	std::cout << findDupsMiss(V0).second.at(0) << '\n';

	if (findDupsMiss(V0).first == 7 &&
		findDupsMiss(V0).second.at(0) == 2)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
