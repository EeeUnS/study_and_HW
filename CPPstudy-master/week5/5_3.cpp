#include<iostream>
#include<random>
#include<list>
#include<limits>

int main()
{
	std::mt19937_64 rng;
	rng.seed(std::random_device()());

	std::uniform_int_distribution<int>distribution(INT32_MIN, INT32_MAX);

	std::list<int> array(1, distribution(rng));
	for (int i = 0; i < 49; i++)
	{
		int num = distribution(rng);

		for (auto itr = array.begin(); itr != array.end(); itr++)
		{
			if (num == *itr)
			{
				std::cout << " 중복된 값 " << std::endl;
				break;
			}
			else if (num < *itr && itr == array.begin())
			{
				array.push_front(num);
				break;
			}
			else if (num < *itr)
			{
				array.insert(itr, num);
				break;
			}
			else//if (itr == --array.end())
			{
				array.push_back(num);
				break;

			}
		}

		if ((i + 2) % 10 == 0)
		{
			for (auto i : array)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl << std::endl;
		}
	}

	return 0;
}