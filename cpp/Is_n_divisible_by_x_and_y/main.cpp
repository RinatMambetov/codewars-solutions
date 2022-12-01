#include <iostream>

bool isDivisible(int n, int x, int y)
{
	return n % x == 0 && n % y == 0;
}

int main()
{
	if (isDivisible(3, 3, 4) == false &&
		isDivisible(12, 3, 4) == true)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
