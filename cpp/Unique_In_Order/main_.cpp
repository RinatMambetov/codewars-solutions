#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::string s1 = "Theeeeee      string    with many       spaces!!!!!!";
	std::cout << "before: " << s1 << '\n';

	std::string s2;
	std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2));

	std::cout << "after:  " << s2 << '\n';
}
