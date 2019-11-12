#include<iostream>
#include<list>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (auto &i : list) {
		ostr << " " << i;
	}
	return ostr;
}



int main()
{
	std::list<int>container1 = { 4, 5,3 ,6,2,7,};

	std::cout << "container1:"<< container1 << std::endl << std::endl;

	std::list<int>container2;

	for (int i = 0; i <= 10; i++)
	{
		container2.push_back(i);
	}

	for (auto iter = container2.begin(); iter != container2.end(); iter++)
	{
		std::cout << *iter << " ";
	}

	std::cout << std::endl << std::endl;

	container1.pop_front();
	container1.push_front(0);
	container1.pop_back();
	std::cout << "container1:" << container1 << std::endl << std::endl;

	container1.reverse();
	std::cout << "container1:" << container1 << std::endl << std::endl;


	
	auto it = std::find(container2.begin(), container2.end(), 5);
	std::cout << *it << std::endl;

	container1.swap(container2);
	std::cout << "swap container1:" << container1 << std::endl << std::endl;
	std::cout << "swap container2:" << container2 << std::endl << std::endl;

	container1.sort();
	std::cout << "sort container1:" << container1 << std::endl << std::endl;

	container2.sort();
	
	container1.merge(container2);
	std::cout << "sort container1:" << container1 << std::endl << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}