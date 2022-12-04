#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

#include <string>

std::string createPhoneNumber(const int arr[10])
{
	std::string result = "(nnn) nnn-nnnn";
	for (size_t i = 0; i < 10; ++i)
	{
		switch (i)
		{
		case 0:
			result[1] = arr[i] + '0';
			break;
		case 1:
			result[2] = arr[i] + '0';
			break;
		case 2:
			result[3] = arr[i] + '0';
			break;
		case 3:
			result[6] = arr[i] + '0';
			break;
		case 4:
			result[7] = arr[i] + '0';
			break;
		case 5:
			result[8] = arr[i] + '0';
			break;
		case 6:
			result[10] = arr[i] + '0';
			break;
		case 7:
			result[11] = arr[i] + '0';
			break;
		case 8:
			result[12] = arr[i] + '0';
			break;
		case 9:
			result[13] = arr[i] + '0';
			break;
		case 10:
			result[14] = arr[i] + '0';
			break;
		default:
			break;
		}
	}
	return result;
}

int main()
{
	int arr0[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int arr1[10] = {0, 2, 3, 0, 5, 6, 0, 8, 9, 0};

	if (createPhoneNumber(arr0).compare("(123) 456-7890") == 0 &&
		createPhoneNumber(arr1).compare("(023) 056-0890") == 0)
		std::cout << "Well done!\n";
	else
		std::cout << "Wrong!\n";

	return 0;
}
