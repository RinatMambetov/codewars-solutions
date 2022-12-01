#include <iostream>

// unsigned long long get_sum(unsigned int n)
// {
// 	return (n + 1L) * (n + 2L) * (4L * n + 3L) / 6L;
// }

unsigned long long get_sum(unsigned int n)
{
	unsigned long long sum(0);
	for (unsigned int i = 1; i < n + 2; ++i)
	{
		unsigned int t(i);
		for (unsigned int j = 0; j < i; ++j)
		{
			sum += t;
			t += 2;
		}
	}
	return sum;
}

int main()
{
	if (get_sum(2) == 22 && get_sum(3) == 50 && get_sum(1000) == 669169501)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong:\n"
				  << "get_sum(2) must be 22, but is " << get_sum(2)
				  << "\nget_sum(3) must be 50, but is " << get_sum(3)
				  << "\nget_sum(3) must be 691951, but is " << get_sum(100)
				  << "\nget_sum(3) must be 669169501, but is " << get_sum(1000) << '\n';
	return 0;
}
