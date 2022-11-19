#include <iostream>
#include <string>
#include <cmath>

class DigPow
{
public:
	static int digPow(int n, int p)
	{
		int t = n;
		int len = log10(t) + 1;
		int sum(0);
		while (len)
		{
			--len;
			sum += static_cast<int>(pow(t % 10, p + len));
			t /= 10;
		}
		if (sum % n == 0)
			return sum / n;
		return -1;
	}
};

int main()
{
	DigPow dp;

	if (dp.digPow(695, 2) == 2 &&
		dp.digPow(46288, 3) == 51)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
