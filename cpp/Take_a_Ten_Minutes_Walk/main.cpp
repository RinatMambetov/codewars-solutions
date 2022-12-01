#include <iostream>
#include <vector>

bool isValidWalk(std::vector<char> walk)
{
	if (walk.size() != 10)
		return false;
	int n(0);
	int s(0);
	int w(0);
	int e(0);
	for (size_t i = 0; i < walk.size(); ++i)
	{
		switch (walk.at(i))
		{
		case 'n':
			++n;
			break;
		case 's':
			++s;
			break;
		case 'w':
			++w;
			break;
		case 'e':
			++e;
			break;

		default:
			return false;
		}
	}
	if (n == s && w == e)
		return true;
	return false;
}

int main()
{
	std::vector<char> V0{'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'};
	std::vector<char> V1{'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 'n'};

	if (isValidWalk(V0) == true &&
		isValidWalk(V1) == false)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong:\n";

	return 0;
}
