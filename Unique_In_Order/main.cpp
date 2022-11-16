#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T> &iterable)
{
	std::vector<T> t;
	t.push_back(iterable.at(0));
	for (size_t i = 1; i < iterable.size(); ++i)
	{
		if (iterable.at(i) != iterable.at(i - 1))
			t.push_back(iterable.at(i));
	}
	return t;
}

std::vector<char> uniqueInOrder(const std::string &iterable)
{
	std::vector<char> s;
	if (iterable.size() == 0)
		return s;
	s.push_back(iterable.at(0));
	for (size_t i = 1; i < iterable.size(); ++i)
	{
		if (iterable.at(i) != iterable.at(i - 1))
			s.push_back(iterable.at(i));
	}
	return s;
}

template <typename T>
void printV(std::vector<T> v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v.at(i);
	}
	std::cout << '\n';
}

int main()
{
	std::string V0{"AAAABBBCCDAABBB"};
	std::vector<int> V1{1, 1, 1, 2, 2, 3, 3, 3};
	std::vector<int> V2{1, 2, 3};

	printV(uniqueInOrder(V0));
	printV(uniqueInOrder(V1));

	std::vector<char> vec0 = uniqueInOrder(V0);
	std::vector<int> vec1 = uniqueInOrder(V1);

	if (std::equal(vec1.begin(), vec1.end(), V2.begin()) == true)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
